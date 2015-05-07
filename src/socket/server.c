/* Nicholas Massa
 * server.c runs the server portion of the chat client. 
 * Pre: './server [portNum]'. Ports from 50,000+ 52,123 recommended.  
 * Press ctrl-c to disconnect server and all clients.
 * Postcondition: The server is running
 *
 */

#define SERVER_INC
#include "sockets.h"

struct s_gl_env gl_env;


int main(int argc, char** argv)
{
    int port;
    int pid;
    int clientfd;
    int sockfd;
    int clilen;
    int bytes_read;
    struct sockaddr_in srv;
    struct sockaddr_in cli_addr;
    char buffer[BUFFER_SIZE];
    char** input;
    signal(SIGINT, disconnect);

    if(argc != 2)
        my_panic("Usage: ./server portNum\n",1);
  

    if((port = my_atoi(argv[1])) <= 0 || port > 65535)
        my_panic("Invalid port number.\n", 1);
            

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
    srv.sin_addr.s_addr = INADDR_ANY;
    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);
    

    memset(&srv.sin_zero, 0, sizeof(srv));

    if(bind(sockfd, (struct sockaddr*) &srv, sizeof(srv)) < 0)
        my_panic("Socket binding error.\n", 1);
        

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    while(1)
    {
        if((clientfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen)) < 0)
            my_panic("Unable to accept client\n", 1);
        
        if((pid = fork()) < 0)    
            my_panic("forking error.\n", 1);

        if(pid == 0)
        {
                signal(SIGINT, bye);
                gl_env.sockfd = clientfd;
        	bytes_read = read(clientfd, buffer, BUFFER_SIZE - 1);
	        buffer[bytes_read] = '\0';
	        gl_env.username = my_strdup(my_str2vect(buffer)[0]);
	        my_str("***");
	        my_str(gl_env.username);
	        my_str(" connected\n");
        	
		while(1)
        	{
                write(clientfd, ".", 1);
	            if((bytes_read = read(clientfd, buffer, BUFFER_SIZE - 1)) < 0)
	                my_panic("Read failed.\n", 1);
	            
                input = my_str2vect(buffer);
	            if(my_strcmp(input[0], "/exit") == 0)
            	{
            		my_str("***");
            		my_str(gl_env.username);
            		my_str(" disconnected\n");
            		close(clientfd);
            		free(gl_env.username);
            		exit(1);
            	}
            	else if(my_strcmp("/nick", input[0]) == 0)
            	{
                    if(input[1])
                    {
                        bytes_read = 1;
                        if(my_strcmp(input[1], "") == 0 || my_strcmp(input[1], "\t") == 0)
                        {
                            for( ; my_strcmp(input[bytes_read], "") == 0 || my_strcmp(input[bytes_read], "\t") == 0; bytes_read++)
                                ;
                        }
                        my_str("***");
                	   my_str(gl_env.username);
                	   my_str(" changed username to ");
                	   free(gl_env.username);
                        gl_env.username = my_strdup(input[bytes_read]);
                	   my_str(gl_env.username);
                        my_char('\n');
                    }
            	}
            	else if(my_strcmp("/me", input[0]) == 0)
            	{
            		my_str("***");
            		my_str(gl_env.username);
                    if(input[1])
                    {
                        my_str(" ");
                        bytes_read = 1;
                        for( ; input[bytes_read]; bytes_read++)
                        {
                            if(!my_strcmp(input[bytes_read], "") == 0 && !my_strcmp(input[bytes_read], "\t") == 0)
                            {
                                my_str(input[bytes_read]);
                                my_str(" ");
                            }
                        }
                    }
                    my_char('\n');
            	}
	            else if(my_strcmp(buffer, "") != 0)
	            {
				 my_str(gl_env.username);
			        my_str(": ");
			        my_str(buffer);
                    my_char('\n');
	            }
	        }
        }
    }

    return 0;
}
