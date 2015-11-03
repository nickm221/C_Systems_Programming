/* 
 * Nicholas Massa
 * connect establishes a connection between the server and client.
 * The connect window is destroyed and the main window's widgets are enabled.
 * Pre: The server is running, the proper inputs are submitted.
 * Post: Client connects to the server.  Destroys connect win, enables main win.
 *
 */

#include "socketsgtk.h"

void 	   connect_server(GtkWidget* w, gpointer d)
{
	char*  message;
	char*  host;
	int    port;
	struct sockaddr_in  serv_addr;
	struct hostent* server;

	port = my_atoi((char*) gtk_entry_get_text((GtkEntry*) gl_env.user_input[1]));
	message = (char*) gtk_entry_get_text((GtkEntry*) gl_env.user_input[2]);
	host = (char*) gtk_entry_get_text((GtkEntry*) gl_env.user_input[0]);

	if(port == 0 || my_strcmp(message, "") == 0 || my_strcmp(host, "") == 0) {
		g_print("Please fill out all fields\n");
		return;
	}

	if(port <= 0 || port > 65535)
	{
		my_str("Invalid port number!\n");
		return;
	}

	memset(&serv_addr.sin_zero, 0, 8);

	gl_env.sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if((server = gethostbyname(host)) == NULL)
	{
		my_str("Couldn't find the server hostname!\n");
		return;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

	if(connect(gl_env.sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
	{
		my_str("Connection to server failed!\n");
		return;
	}

	if(write(gl_env.sockfd, message, my_strlen(message) + 1) < 0)
	{
		my_str("Communication with server failed!\n");
		return;
	}

	enable_main();
	g_print("Connected!\n");
	gtk_button_set_label((GtkButton*) gl_env.connect_button, "Disconnect");
	gtk_widget_destroy(d);
}