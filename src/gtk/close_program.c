/* 
 * Nicholas Massa
 * close_program shuts down the program.  
 * Pre: None
 * Post: Disconnect signal is sent to the server, quits gtk. 
 *
 */

#include "socketsgtk.h"

void close_program(GtkWidget* w, gpointer d)
{
	if(gl_env.sockfd > -1)
	{
		disconnect();
	}

	gtk_main_quit();
}