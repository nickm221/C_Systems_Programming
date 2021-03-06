/* Nicholas Massa
 * client.c client portion of the server
 * Pre: is run by typing "./client [server] [portnumber]"
 * Takes the commands /me, /nick, /exit
 * Post: runs the client portion of the server
 *
 */


#define CLIENT
#include "sockets.h"

int sockfd;

void diecli(int sig)
{
	my_str("\nPeace sucka\n");
	write(sockfd,"/exit",6);
	exit(0);
}

int main(int argc, char** argv)
{
	int bytes_read;
	int port;
	struct sockaddr_in serv_addr;
	struct hostent* server;
	char message[BUFFER_SIZE];

	signal(SIGINT, diecli);

	if(argc != 3)
	{
		my_str("Usage: ./client serverName portNum\n");
		exit(1);
	}

	if((port = my_atoi(argv[2])) <= 0 || port > 65535)
	{
		my_str("Invalid port number!\n");
		exit(1);
	}

	memset(&serv_addr.sin_zero, 0, 8);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if((server = gethostbyname(argv[1])) == NULL)
	{
		my_str("Couldn't find the server hostname!\n");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

	if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
	{
		my_str("Connection to server failed!\n");
		exit(1);
	}

	my_str("Username: ");
	bytes_read = read(0, message, BUFFER_SIZE - 1);
	message[bytes_read - 1] = '\0';
	my_char('\n');

	if(write(sockfd, message, bytes_read) < 0)
	{
		my_str("Communication with server failed!\n");
		exit(1);
	}

	while(1)
	{
		bytes_read = read(sockfd, message, BUFFER_SIZE - 1);
		if(bytes_read < 1)
		{
			my_str("Server closed connection!\n");
			exit(1);
		}
		my_str("Message: ");
		bytes_read = read(0, message, BUFFER_SIZE - 1);
		message[bytes_read - 1] = '\0';
		write(sockfd, message, bytes_read);
		if(my_strncmp(message, "/exit", 5) == 0 && (message[5] == ' ' || message[5] == '\0'))
		{
			my_str("\nBye!\n");
			exit(0);
		}
	}

	return 0;
}
