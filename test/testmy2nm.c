#include "my.h"

/* Nicholas Massa
 * I pledge my honor that I have abided by the Stevens Honor System.
 * LibMy v1.1 tests: Tests for adding multiple string functionality to LibMy.
 * Test main returns 0 and displays "All Tests complete" if all tests pass.
 * If a test fails, my_panic will exit.  
 *
*/


/* NOTE: string comparison NOT used until it is tested. */
int main()
{
  char* str = "hello";
  char* str2 = "This is a longer string.";
  char* empty = "";
  char* dst = "abcdef";
  char* test = "";
  unsigned int n = -1;
  my_str("---- 1. my_strdup ----"); my_char('\n');

  my_str("Should read hello below:");
  test = my_strdup(str); 
  my_str(test); my_char('\n'); /* Returns copy of hello to be printed */
  test = "";

  my_str("Should read 'This is a longer string' below:");
  test = my_strdup(str2); 
  my_str(test); my_char('\n');

  my_str("Should read blank below (blank):"); my_char('\n');
  test = my_strdup(empty);
  my_str(test); my_char('\n');

  my_str("Should read blank below (blank):"); my_char('\n');
  test = my_strdup(NULL);
  my_str(test); my_char('\n');

  my_str("my_strdup tests complete."); my_char('\n'); my_char('\n');


  my_str("---- 2. my_strcpy ----"); my_char('\n');
  my_str("Should read 'Test' below:"); my_char('\n');
  my_str(my_strcpy(str, "Test")); my_char('\n');
  my_str("Should read 'Test' below (into empty):"); my_char('\n');
  my_str(my_strcpy(empty, "Test")); my_char('\n');
  my_str("Should be blank below (empty str):"); my_char('\n');
  my_str(my_strcpy(str,""));  my_char('\n'); 
  my_str("Should be blank below (str, NULL):");  my_char('\n');
  my_str(my_strcpy(str, NULL));  my_char('\n');
  my_str("Should be blank below (NULL, str):");  my_char('\n');
  my_str(my_strcpy(NULL, str)); my_char('\n');
  my_str("Should be blank below (NULL,NULL):");
  my_str(my_strcpy(NULL, NULL)); my_char('\n');
  str = "hello";
  my_str("my_strcpy tests complete."); my_char('\n'); my_char('\n');


#if 0
  my_str("---- 3. my_strncpy ----"); my_char('\n');
  my_str("Should read 'Dello' below:"); my_char('\n');
  my_str(my_strncpy(str, "DUH", 1)); my_char('\n');
  my_str("Should read 'Hellef' below:"); my_char('\n');
  my_str(my_strncpy(dst, "Hello", 4); my_char('\n');
  my_str("Should read 'Hello' below (large n val):"); my_char('\n');
  my_str(my_strncpy(empty, "Hello", 12345);  my_char('\n');
  my_str("Should read 'This is a longer string' below (str2,NULL,12345):"); my_char('\n');
  my_str(my_strncpy(str2, NULL, 12345); my_char('\n');
  my_str("Should be blank below (NULL, str, 12345):");  my_char('\n');
  my_str(my_strncpy(NULL, str, 12345); my_char('\n');
  my_str("Test for max unsigned int:");	  my_char('\n');
  my_str(mystrncpy(str, "hello", n)); my_char('\n');
  str[] = "hello";
  str2[] = "This is a longer string";
  empty[] = "abcdef";
  my_str("my_strncpy tests complete.");

  my_str("---- 4. my_strcmp ----");  my_char('\n');
  if(my_strcmp("Hello","Hello") != 0)
    my_panic("Equal test failed", 1);
  if(my_strcmp("Hello","AAAAAAAAAAAA") >= 0)
    my_panic("strcmp(Hello,AAAAAAA) did not return neg val", 1);
  if(my_strcmp("AAAAA", "Hello" >= 0))
    my_panic("strcmp(AAAAA,Hello) did not return a pos val",1);
  if(my_strcmp("abc","ab") <= 0)
    my_panic("(abc,ab) failed should be pos val", 1);
  if(my_strcmp("ab","abc") >= 0)
    my_panic("(ab,abc) should be a neg val", 1);
 if(my_strcmp("","abc") >= 0)
    my_panic("(,abc) should be a neg val", 1);
 if(my_strcmp("abc","") <= 0)
    my_panic("(abc,) should be a pos val", 1);
 if(my_strcmp("","") != 0)
    my_panic("(,) should be 0", 1);
 if(my_strcmp("ab",NULL) <= 0)
    my_panic("(ab,NULL) should be a pos val", 1);
 if(my_strcmp(NULL,"abc") >= 0)
    my_panic("(ab,abc) should be a neg val", 1);
 if(my_strcmp(NULL, NULL) != 0)
    my_panic("(NULL, NULL) should be 0", 1);
  my_str("All my_strcmp tests passed."); my_char('\n'); my_char('\n');
 
  my_str("---- 5. my_strncmp ----"); my_char('\n');
  if(my_strncmp("Hello","Hello", 12345) != 0)
    my_panic("Equal test failed", 1);
  if(my_strncmp("Hello","AAAAAAAAAAAA", 1) <= 0)
    my_panic("strcmp(Hello,AAAAAAA, 1) did not return neg val", 1);
  if(my_strncmp("AAAAA", "Hello", 1) >= 0))
    my_panic("strcmp(AAAAA,Hello) did not return a pos val",1);
  if(my_strncmp("abc","ab", 56) <= 0)
    my_panic("(abc,ab,56) failed should be pos val", 1);
  if(my_strncmp("ab","abc", 56) >= 0)
    my_panic("(ab,abc,56) should be a neg val", 1);
  if(my_strncmp("","abc", 1) >= 0)
    my_panic("(,abc,1) should be a neg val", 1);
  if(my_strncmp("abc","",1) <= 0)
    my_panic("(abc,,1) should be a pos val", 1);
  if(my_strncmp("","",2) != 0)
    my_panic("(,,2) should be 0", 1);
  if(my_strncmp("ab",NULL,2) <= 0)
    my_panic("(ab,NULL,2) should be a pos val", 1);
  if(my_strncmp(NULL,"abc",2) >= 0)
    my_panic("(ab,abc) should be a neg val", 1);
  if(my_strncmp(NULL, NULL,2) != 0)
    my_panic("(NULL, NULL,2) should be 0", 1);
  if(my_strncmp("abc", "abc", 0) != 0)
    my_panic("(abc, abc, 0) should be 0", 1);
  if(my_strncmp("abcd", "a", 0) != 0)
    my_panic("(abcd, a, 0) should be 0", 1);
  if(my_strncmp("abc","",n) <= 0)
    my_panic("(abc,,n) should be a pos val", 1);
  my_str("All my_strncmp tests passed."); my_char('\n'); my_char('\n');


 my_str("---- 6. xmalloc ----"); my_char('\n');
 my_str("No tests necessary.  Given Function."); my_char('\n'); my_char('\n');

 /* Now that strcmp has been tested, we can use that function to
 test the functions that return a char* */
 my_str("---- 7. my_strconcat ----"); my_char('\n');
 if(my_strcmp(my_strconcat("",""), "") != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat("abc","def"), "abcdef") != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat("","def"), "def") != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat("",""), "") != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat("abc",""), "abc") != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat(NULL,NULL), NULL) != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat(NULL,"abc"), "abc") != 0)
   my_panic("my_strconcat failed", 1);
 if(my_strcmp(my_strconcat("def",NULL), "def") != 0)
   my_panic("my_strconcat failed", 1);
 
 my_str("All my_strconcat tests complete."); my_char('\n'); my_char('\n');


 my_str("---- 8. my_strnconcat ----"); my_char('\n');

 if(my_strcmp(my_strnconcat("", "", 5), "") != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat("abc", "def", 1), "abcde") != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat("", "abcdefghijklmnop", 3), "abcd") != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat("abcdefghijklmnop","",3), "abcdefghijklmnop") != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat(NULL,NULL,5), NULL) != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat(NULL,"abc",5), "abc") != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat("def",NULL,5), "def") != 0)
   my_panic("my_strnconcat failed", 1); 
 if(my_strcmp(my_strnconcat("abc", "def", n), "abcde") != 0)
   my_panic("my_strnconcat failed", 1); 
 my_str("All my_strnconcat tests complete."); my_char('\n'); my_char('\n');


 my_str("---- 9. my_strcat ----"); my_char('\n');

 if(my_strcmp(my_strcat("",""), "") != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat("abc","def"), "abcdef") != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat("","def"), "def") != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat("",""), "") != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat("abc",""), "abc") != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat(NULL,NULL), NULL) != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat(NULL,"abc"), NULL) != 0)
   my_panic("my_strcat failed", 1);
 if(my_strcmp(my_strcat("def",NULL), "def") != 0)
   my_panic("my_strcat failed", 1);
 my_str("All my_strcat tests complete.");  my_char('\n'); my_char('\n');


 my_str("---- 10. my_panic ----"); my_char('\n');
 my_str("No tests necessary.  Function given in class."); my_char('\n'); my_char('\n');


 my_str("---- 11. my_strfind ----"); my_char('\n'); 

 if(my_strcmp(my_strfind("hello",'l'), "llo") != 0)
   my_panic("my_strfind failed", 1);
 if(my_strcmp(my_strfind(NULL,'l'), "") != 0)
   my_panic("my_strfind failed", 1);
 if(my_strcmp(my_strfind("test",'l'), "") != 0)
   my_panic("my_strfind failed", 1);
 if(my_strcmp(my_strfind("",'l'), "") != 0)
   my_panic("my_strfind failed", 1);
 my_str("All my_strfind tests complete. ");  my_char('\n');  my_char('\n');


 my_str("---- 12. my_strrfind ----"); my_char('\n'); 

 if(my_strcmp(my_strrfind("hello",'l'), "lo") != 0)
   my_panic("my_strrfind failed", 1);
 if(my_strcmp(my_strrfind(NULL,'l'), "") != 0)
   my_panic("my_strrfind failed", 1);
 if(my_strcmp(my_strrfind("test",'l'), "") != 0)
   my_panic("my_strrfind failed", 1);
 if(my_strcmp(my_strrfind("",'l'), "") != 0)
   my_panic("my_strrfind failed", 1);
 my_str("All my_strrfind tests complete. ");  my_char('\n');  my_char('\n');


#endif
 my_str("~~~~~~~~~ ALL TESTS COMPLETE ~~~~~~~~~");  my_char('\n');  my_char('\n');



  return 0;
}
