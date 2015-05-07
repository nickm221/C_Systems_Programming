/* Nicholas Massa
 * disconnect() disconnects exits the server
 * Pre: None
 * Post: exit the the server (clients will die)
 * 
 */

#include "sockets.h"

extern int sockfd;

void disconnect()
{
  sleep(1);
  my_str("Bye!\n");
  exit(0);
}
