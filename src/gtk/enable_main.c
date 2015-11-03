/* 
 * Nicholas Massa
 * enable_main enables all of the widgets on the main window
 * Pre: Main window is initialized
 * Post: All of the widgets on the main window are enabled.
 *
 */

#include "socketsgtk.h"

void enable_main()
{
	gtk_widget_set_sensitive((GtkWidget*) gl_env.quit_button, TRUE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.connect_button, TRUE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.send_button, TRUE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.message_input, TRUE);
}