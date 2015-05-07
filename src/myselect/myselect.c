/* Nicholas Massa
 * main() runs the myselect program
 * Pre: valid items are entered
 * Post: the program is run
 *
 */

#include "myselect.h"

int main(int argc, char** argv)
{

  signal(SIGWINCH, show_elems);
  int n = 0; 
  int BUFF_SIZE = 4;
  char buffer[BUFF_SIZE];
  
  // 1. Check Input
  if(argc < 2)
    my_panic("Usage: ./myselect itemSelector1, itemSelector2, ..., itemSelectorX\n", 1);
  
  // 3.  Change I/O settings
  init_terminal();

  // 2.  Get all cap info
  init_caps();
  
  // 4.  Fill element array
  setup_elems(argc, &argv[1]);

  term_vi();

  show_elems();

  while((n = read(0, buffer, 3)) > 0)
    {
      buffer[n] = '\0';
      check_character(buffer);
    }
  
  restore_terminal();
  return 0;
}
