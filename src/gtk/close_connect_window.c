/* 
 * Nicholas Massa
 * cancel_connect_window is the callback function for the connect window cancel.
 * Pre: None
 * Post: The window is closed.  Connection button is reset.  Main window 
 *
 */

#include "socketsgtk.h"

void close_connect_window(GtkWidget* w, gpointer d)
{
	gtk_signal_handler_block(gl_env.connect_button, gl_env.connect_id);
	gtk_toggle_button_set_active((GtkToggleButton*) gl_env.connect_button, FALSE);
	gtk_signal_handler_unblock(gl_env.connect_button, gl_env.connect_id);
	enable_main();
	gtk_widget_destroy(w);
}