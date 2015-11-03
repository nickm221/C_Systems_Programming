/* Nicholas Massa
 * my.h Header file for my library.
 * The my library contains basic C functions for string/vector/integer manipulation and printing. 
*/
#ifndef _MY_H_
#define _MY_H_

#ifndef NULL 
#define NULL ((void*) 0
#endif

#include <unistd.h>
#include <stdlib.h>

void my_char(char); /* Prints a char */
void my_str(char*); /* Prints a string */
void my_int(int); /* Prints an int */
void my_num_base(int, char*); /* Prints an int in a base in char form */
void my_alpha(); /* Prints a-z */
void my_digits(); /* Prints 0-9 */

int my_strlen(char*); /* Returns the length of a string */
int my_revstr(char*); /* Reverses the length of a string */
int my_strindex(char*, char); /* Returns the index of the first of a char */
int my_strrindex(char*, char); /* Returns the index of the last of a char */

char *my_strdup(char*); /* Return pointer to new, duplicate string */
char *my_strcpy(char*,char*); /* Copies entire string from source to dest */
char *my_strncpy(char*, char*, unsigned int); /* Copies string from start up to index n to destination */

int my_strcmp(char*, char*);  /* String comparison.  negative if s1<s2.  0 if same.  positive if s1>s2. */
int my_strncmp(char*, char*, unsigned int);  /* String comparison up to n.  negative if s1<s2.  0 if same.  positive if s1>s2. */

char *my_strconcat(char*, char*);  /* Returns a new string containing s1 followed by s2. */
char *my_strnconcat(char*, char*, unsigned int); /* Returns a new string up to index n containing s1 followed by s2. */
char *my_strcat(char*, char*);  /* Copies s2 at the end of s1. */

void *xmalloc(unsigned int);  /* Wrapper to check return type of malloc. */
void my_panic(char*, unsigned int);  /* Prints char sting and exits with exit status one */

char *my_strfind(char*, char); /* Find a character and return a ptr to the first occurence of char in str*/
char *my_strrfind(char*, char); /* Find a character and return a ptr to the last occurence of char in str*/

char *my_vect2str(char**);  /* Converts a vector to a standard string */
char **my_str2vect(char*);  /* Converts a string to a vector */
int my_atoi(char*);  /* Converts a string to an integer */

#endif
