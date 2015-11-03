/* 
 * Nicholas Massa
 * create_main_window creates main gtk window
 * Pre: init has been called
 * Post: The main window is shown.
 *
 */

#include "socketsgtk.h"

void create_main_window()
{
	GtkWidget* win;
	GtkWidget* table;
	GtkWidget* text_label;

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "Client");
	
	table = gtk_table_new(4, 7, FALSE);
	gl_env.connect_button = gtk_toggle_button_new_with_label("Connect");
	gl_env.quit_button = gtk_button_new_with_label("Quit");
	text_label = gtk_label_new("Message: ");
	gl_env.message_input = gtk_entry_new();
	gl_env.send_button = gtk_button_new_with_label("Send");

	gtk_table_attach((GtkTable*) table, text_label, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach((GtkTable*) table, gl_env.message_input, 0, 5, 1, 2, GTK_FILL, GTK_FILL, 5, 5);
	gtk_table_attach((GtkTable*) table, gl_env.send_button, 5, 7, 1, 2, GTK_FILL, GTK_FILL, 5, 5);
	gtk_table_attach((GtkTable*) table, gl_env.connect_button, 0, 3, 2, 3, GTK_FILL, GTK_FILL, 5, 5);
      	gtk_table_attach((GtkTable*) table, gl_env.quit_button, 4, 7, 2, 3, GTK_FILL, GTK_FILL, 5, 5);
	gtk_table_set_row_spacing((GtkTable*) table, 1, 15);
	gtk_table_set_row_spacing((GtkTable*) table, 2, 25);

	
	g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(create_quit_window), NULL);
	gl_env.connect_id = g_signal_connect(gl_env.connect_button, "toggled", G_CALLBACK(create_connect_window), NULL);
	g_signal_connect(gl_env.quit_button, "clicked", G_CALLBACK(create_quit_window), NULL);
	g_signal_connect(gl_env.send_button, "clicked", G_CALLBACK(send_message), NULL);
	g_signal_connect(gl_env.message_input, "activate", G_CALLBACK(send_message), NULL);

	gtk_container_add(GTK_CONTAINER(win), table);

	gtk_widget_show_all(win);

	gtk_main();
}
