/* Test Main One
 * Description: This Main Function tests all functions 
 * within the LibMy v1.0 Library
 * Author: Nicholas Massa
*/
#include "my.h"
int main(int argc, char** argv) 
{
#if 0
  /*Testing for the my_char function. Takes a char and prints it.*/
  my_char('c'); my_char('\n');
  my_char('2');  my_char('\n');
  my_char('A'); my_char('\n');

  /*Testing for the my_str function.  Takes an array of characters and prints it.*/
  my_str(NULL); my_char('\n');
  my_str("Hello"); my_char('\n');
  my_str("String with a space"); my_char('\n');
  my_str(" "); my_char('\n');
  my_str(""); my_char('\n');

  my_str("All my_str tests now complete."); my_char('\n'); my_char('\n');

  /*Testing for the my_int function.  Takes an int and prints it.*/
  my_int(5); my_char('\n');
  my_int(12345678); my_char('\n');
  my_int('E'); my_char('\n');
  my_int(-5); my_char('\n');
  my_int(0); my_char('\n');
  my_int(1000); my_char('\n');
  my_int(1 << (8 * sizeof(int) - 1)); my_char('\n'); /* Test for minimum value of int. */

  my_str("All my_int tests now complete."); my_char('\n'); my_char('\n');

  /* Testing the my_strlen function.  If the test fails, the main will return -1,
     otherwise will print the pass message. */
  if(my_strlen("abc") != 3)
     my_str("my_strlen abc FAILED."); 
  my_int(my_strlen("abc")); my_char('\n');

  if(my_strlen("") != 0)
      my_str("my_strlen "" FAILED."); 
  my_int(my_strlen("")); my_char('\n');

  if(my_strlen(NULL) != -1)
      my_str("my_strlen NULL FAILED.");
  my_int(my_strlen(NULL)); my_char('\n');

  if(my_strlen("A Space") != 7)
      my_str("my_strlen spaces FAILED");
  my_int(my_strlen("A space")); my_char('\n');

  my_str("All my_strlen tests complete."); my_char('\n'); my_char('\n');

  /*Testing for my_alpha function.  Should print all lower case letters a-z.*/
  my_alpha(); my_char('\n'); /* Expected: a-z */

  my_str("my_alpha test complete."); my_char('\n'); my_char('\n');

  /* Testing for my_digit function.  Should print all digits 0-9.  */
  my_digits();  my_char('\n'); /* Expected: 0-9 */

  my_str("my_digit test complete."); my_char('\n'); my_char('\n');

  /* Testing for my_strindex function.  If the test passes it will print the
     passing statement.  Negative 1 otherwise */
  if(my_strindex("hello",'l') != 2) 
     my_str("my_strindex hello,l FAILED");      
  my_int(my_strindex("hello",'l')); my_char('\n');

  if(my_strindex(NULL,'a') != -1)
     my_str("my_strindex NULL,a FAILED");       
  my_int(my_strindex(NULL, 'a')); my_char('\n');

  if(my_strindex("camel",'\0') != -1)
     my_str("my_strindex camel,\0 FAILED");      
  my_int(my_strindex("camel",'\0')); my_char('\n');

  if(my_strindex("hello", 'o') != 4)
     my_str("my_strindex hello,o FAILED");      
  my_int(my_strindex("hello",'o')); my_char('\n');

  if(my_strindex("test",'c') != -1)
     my_str("my_strindex test,c FAILED");       
  my_int(my_strindex("test",'c')); my_char('\n');

  my_str("All my_strindex tests complete."); my_char('\n'); my_char('\n');

  /* Testing for my_strrindex function.  If the test passes it will print the passing
     statement.  Otherwise, will return -1.   */
  if(my_strrindex("hello",'l') != 3)
     my_str("my_strrindex hello,l FAILED");      
  my_int(my_strrindex("hello",'l')); my_char('\n');

  if(my_strrindex(NULL,' ') != -1)
     my_str("my_strrindex NULL,' ' FAILED");     
  my_int(my_strrindex("NULL",' ')); my_char('\n');

  if(my_strrindex(NULL, 'a') != -1)
     my_str("my_strrindex NULL,a FAILED");       
  my_int(my_strrindex(NULL, 'a')); my_char('\n');    

  if(my_strrindex("LOOOOOL", 'L') != 6)
     my_str("my_strrindex LOOOOL,L FAILED");      
  my_int(my_strrindex("LOOOOOL",'L')); my_char('\n');    

  if(my_strrindex("test", 'a') != -1)
     my_str("my_strrindex test,a FAILED");       
  my_int(my_strrindex("test",'a')); my_char('\n');    

  if(my_strrindex("test",'t') != 3)
     my_str("my_strrindex test,t FAILED");       
  my_int(my_strrindex("test",'t')); my_char('\n');

  if(my_strrindex("test",'e') != 1)
     my_str("my_strrindex test,e FAILED");      
  my_int(my_strrindex("test",'e')); my_char('\n');

  my_str("All my_strrindex tests complete.");  my_char('\n'); my_char('\n');



  /*Testing for the my_num_base function.  Takes an int followed by an array of 
    characters and prints the value in the given base. */
  my_num_base(9,"BLAH"); my_char('\n'); /* Expected: AL */
  my_num_base(5,"01"); my_char('\n'); /* Expected: 101 */  
  my_num_base(21,"01"); my_char('\n'); /* Expected: 10101 */
  my_num_base(-15,"0123456789ABCDEF"); my_char('\n'); /* Expected: -F */
  my_num_base(-21,"01"); my_char('\n'); /* Expected: -10101 */
  my_num_base(4 ,"ASDF"); my_char('\n'); /* Expected: SA */
  my_num_base(4, "ASD"); my_char('\n'); /* Expected: SS  */
  my_num_base(123456789, "012345678"); my_char('\n'); /* Expected: 123456789 in base 8. */
  my_num_base(5, NULL); my_char('\n'); /* Expected: "Base not valid \n" */
  my_num_base(-5, NULL); my_char('\n'); /* Expected: "Base not valid \n" */
  my_num_base(5, ""); my_char('\n'); /* Expected: "Base not valid \n" */
  my_num_base(0, "25"); my_char('\n'); /* Expected: 2 */


  /* Testing for the my_revstr function.  If the test fails, will return -1,
     otherwise the test will print the pass message. */
  char str[] = "hello";  
  char rev[] = "olleh";
  char one[] = "A";
  if(my_revstr(str) != 5)
    {
  return -1;
    }
  my_str(str); my_char('\n');
  if(my_revstr(rev) != 5)
    {
      return -1;
    }
  my_str(rev); my_char('\n');
  if (my_revstr(one) != 1)
    return -1;
  my_str(one);
  if(my_revstr("") != -1)
    {
      return -1; 
    }
  my_str("no length string passed.");  my_char('\n');
  if(my_revstr(NULL) != -1) 
    {
      return -1;
    }
	 my_str("NULL Passed"); my_char('\n');

  my_str("All my_revstr tests completed and passed."); my_char('\n');
#endif

  my_str("\n\n\n my str2vect tests \n");
char **vect;
  int i;

  if (argc > 1)
    {
      vect = my_str2vect(argv[1]);
      for (i = 0; vect[i] != NULL; i++)
	{
	  my_str("-->");
	  my_str(vect[i]);
	  my_str("<--\n");
	}
    }
  else
    my_str("Use: ./a.out 'some long string'\n");



  my_str("All Test Cases complete and successful."); my_char('\n');
  return 0;
}
