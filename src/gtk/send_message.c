/* 
 * Nicholas Massa
 * send_message sends a message to the server.
 * Pre: The client and server are connected.  
 * Post: The message is sent or an error is printed.
 *
 */


#include "socketsgtk.h"

void 	  send_message(GtkWidget* w, gpointer d)
{
	char  message[2];
	char* user_message;
	int   bytes_read;

	user_message = (char*) gtk_entry_get_text((GtkEntry*) gl_env.message_input);

	if(gl_env.sockfd == -1)
	{
		g_print("ERROR: You are not currently connected to a server.\n");
		return;
	}

	if(my_strcmp(user_message, "") == 0)
	{
		g_print("ERROR: You cannot send a blank message.\n");
		return;
	}

	if(write(gl_env.sockfd, user_message, my_strlen(user_message) + 1) < 0)
	{
		g_print("Communication with server failed!\n");
		disconnect();
	}

	bytes_read = read(gl_env.sockfd, message, 3);

	if(bytes_read < 1)
	{
		my_str("Server closed connection!\n");
		gtk_toggle_button_set_active((GtkToggleButton*) gl_env.connect_button, FALSE);
		return;
	}

	if(my_strncmp(user_message, "/exit", 5) == 0 && (user_message[5] == ' ' || !user_message[5]))
	{
		gtk_toggle_button_set_active((GtkToggleButton*) gl_env.connect_button, FALSE);
	}

	gtk_entry_set_text((GtkEntry*) gl_env.message_input, "");
}
