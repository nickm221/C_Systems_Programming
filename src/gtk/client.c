/* 
 * Nicholas Massa
 * client main is the client portion of the server.
 * Pre: Server is running and valid parameters are passed
 * Post: Client begins running
 *
 */

#define CLIENT_INC
#include "socketsgtk.h"

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);

	gl_env.sockfd = -1;
	
	create_main_window();

	return 0;
}