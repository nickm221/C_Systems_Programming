/* 
 * Nicholas Massa
 * create_connect_window creates the connect window with input options.
 * Pre: Main window is initialized
 * Post: If not connected, window is created.  Otherwise, disconnect.
 *
 */

#include "socketsgtk.h"

void create_connect_window(GtkWidget* w, GdkEvent* e, gpointer data)
{
	GtkWidget* win;
	GtkWidget* table;
	GtkWidget* server_label;
	GtkWidget* server_input;
	GtkWidget* port_label;
	GtkWidget* port_input;
	GtkWidget* username_label;
	GtkWidget* username_input;
	GtkWidget* ok_button;
	GtkWidget* cancel_button;
	
	if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w)))
	{
		disconnect();
	}
	else
	{
		disable_main();
		win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		table = gtk_table_new(4, 5, FALSE);
		server_label = gtk_label_new("Host: ");
		server_input = gtk_entry_new();
		port_label = gtk_label_new("Port: ");
		port_input = gtk_entry_new();
		username_label = gtk_label_new("Username: ");
		username_input = gtk_entry_new();
		ok_button = gtk_button_new_with_label("Ok");
		cancel_button = gtk_button_new_with_label("Cancel");

		gl_env.user_input[0] = server_input;
		gl_env.user_input[1] = port_input;
		gl_env.user_input[2] = username_input;

		gtk_window_set_title(GTK_WINDOW(win), "Connect");

		gtk_table_attach((GtkTable*) table, server_label, 0, 2, 0, 1, GTK_FILL, GTK_FILL, 5, 2);
		gtk_table_attach((GtkTable*) table, server_input, 2, 5, 0, 1, GTK_FILL, GTK_FILL, 5, 2);
		gtk_table_attach((GtkTable*) table, port_label, 0, 2, 1, 2, GTK_FILL, GTK_FILL, 5, 2);
		gtk_table_attach((GtkTable*) table, port_input, 2, 5, 1, 2, GTK_FILL, GTK_FILL, 5, 2);
		gtk_table_attach((GtkTable*) table, username_label, 0, 2, 2, 3, GTK_FILL, GTK_FILL, 5, 2);
		gtk_table_attach((GtkTable*) table, username_input, 2, 5, 2, 3, GTK_FILL, GTK_FILL, 5, 2);
		gtk_table_attach((GtkTable*) table, ok_button, 0, 3, 3, 4, GTK_FILL, GTK_FILL, 5, 3);
		gtk_table_attach((GtkTable*) table, cancel_button, 3, 5, 3, 4, GTK_FILL, GTK_FILL, 5, 3);

		g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(close_connect_window), G_OBJECT(win));
		g_signal_connect_swapped(cancel_button, "clicked", G_CALLBACK(close_connect_window), G_OBJECT(win));
		g_signal_connect(ok_button, "clicked", G_CALLBACK(connect_server), win);
		g_signal_connect(server_input, "activate", G_CALLBACK(connect_server), win);
		g_signal_connect(port_input, "activate", G_CALLBACK(connect_server), win);
		g_signal_connect(username_input, "activate", G_CALLBACK(connect_server), win);

		gtk_container_add(GTK_CONTAINER(win), table);

		gtk_widget_show_all(win);
	}
}