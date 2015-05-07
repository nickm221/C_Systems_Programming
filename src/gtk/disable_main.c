/* 
 * Nicholas Massa
 * disable_main disables all of the widgets on the main window
 * Pre: Main window is initialized
 * Post: All of the widgets on the main window are disabled.
 *
 */

#include "socketsgtk.h"

void disable_main()
{
	gtk_widget_set_sensitive((GtkWidget*) gl_env.quit_button, FALSE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.connect_button, FALSE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.send_button, FALSE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.message_input, FALSE);
}