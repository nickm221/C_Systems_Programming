/* Nicholas Massa
 * pipes main forks child processes, sending data to both children via pipes
 * Pre: Takes argc the number of arguments and argv the vector of arguements
 * Post: Prints the strings sent to the children
 *
 */

#include "my.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif

int main(int argc, char** argv)
{
    char  buffer[BUFFER_SIZE];
    int   pipe1[2];
    int   pipe2[2];
    int   fd;
    int   msglen;
    char* input;

	//Error Checking user input.
    if(argc < 2)
        my_panic("Use: ./pipes arg1 [arg2] [arg3]...\n", 1);
    
	//Create pipe1 Grandparent<->Parent
    pipe(pipe1);

	//
    if((fd = fork()) < 0)
        my_panic("Grandparent fork() error!\n", 1);
    
    if(fd > 0)
    {
		//Close read side of pipe1 
        close(pipe1[0]);
        
		//Take input from user.
        input = my_vect2str(&argv[1]);
        my_str("Grandparent says: \"");
        my_str(input);
        my_str("\"\n");

		//Write the given string to pipe1 
        write(pipe1[1], input, BUFFER_SIZE - 1);
        wait();
    }
    else
    {
		//Close write side of pipe1
        close(pipe1[1]);
		//read in message from buffer & print
        msglen = read(pipe1[0], buffer, BUFFER_SIZE - 1);
        buffer[msglen] = '\0';
        my_str("Parent says: \"");
        my_str(buffer);
        my_str("\"\n");

		//Create pipe2 Parent<->Child
        pipe(pipe2);

        if((fd = fork()) < 0)
            my_panic("Parent fork() error!\n", 1);
       
		if(fd > 0)
        {
			//Close Read side.  Write to pipe2 
            close(pipe2[0]);
            write(pipe2[1], buffer, BUFFER_SIZE - 1);
            wait();
        }
        else
        {
			//close write side of pipe2 and read in message from buffer
            close(pipe2[1]);
            msglen = read(pipe2[0], buffer, BUFFER_SIZE - 1);
            buffer[msglen] = '\0';
            my_str("Child says: \"");
            my_str(buffer);
            my_str("\"\n");
            exit(0);
        }
    }

    return 0;
}