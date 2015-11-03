/* 
 * Nicholas Massa
 * server runs the server portion of the chat client.
 * Pre: './server [portNum]'. Ports from 50,000+ 52,123 recommended.
 * Press ctrl-c to disconnect server and all clients.
 * Post: The server is running
 *
 */

#define SERVER_INC
#include "sockets.h"

 void shutdown_server()
{
    usleep(getpid());
    free(gl_env.username);
    close(gl_env.sockfd);
    exit(0);
}
void bye()
{
    usleep(2 * getpid());
    my_str("\nServer shutting down...Goodbye!\n");
    exit(0);
}
int        main(int argc, char** argv)
{
    int    port;
    int    pid;
    int    clientfd;
    int    sockfd;
    int    clilen;
    int    bytes_read;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char   buffer[BUFFER_SIZE];
    char** input;

    signal(SIGINT, bye);

    if(argc != 2)
    {
        my_str("Usage: ./server portNum\n");
        exit(1);
    }

    if((port = my_atoi(argv[1])) <= 0 || port > 65535)
    {
        my_str("Invalid port number!\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_port = htons(port);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    memset(&serv_addr.sin_zero, 0, 8);

    if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
    {
        my_str("Unable to bind socket!\n");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    while(1)
    {
        if((clientfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen)) < 0)
        {
            my_str("Unable to accept client\n");
            exit(1);
        }

        if((pid = fork()) < 0)
        {
            my_str("fork() critical error!\n");
            exit(1);
        }

        if(pid == 0)
        {
            signal(SIGINT, shutdown_server);
            gl_env.sockfd = clientfd;
            bytes_read = read(clientfd, buffer, BUFFER_SIZE - 1);
            buffer[bytes_read] = '\0';
            gl_env.username = my_strdup(my_str2vect(buffer)[0]);
            my_str("***");
            my_str(gl_env.username);
            my_str(" connected!\n");
            while(1)
            {
                if((bytes_read = read(clientfd, buffer, BUFFER_SIZE - 1)) < 0)
                {
                    my_str("Read failed!\n");
                    exit(1);
                }
                write(clientfd, ".", 1);
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
