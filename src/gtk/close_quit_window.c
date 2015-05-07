/* 
 * Nicholas Massa
 * no_quit_window is the callback function for the quit window "no" option.
 * Pre: None
 * Post: The quit window is closed.  Main Window re-enabled. 
 *
 */

#include "socketsgtk.h"

void close_quit_window(GtkWidget* w, gpointer d)
{
	enable_main();
	gtk_widget_destroy(w);
}