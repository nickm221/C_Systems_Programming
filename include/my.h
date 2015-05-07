/* Nicholas Massa
 * my.h Header file for LibMy v1.0
 * LibMy v1.0 contains a variety of useful functions that we will implement.  
 * These functions will assist in basic printing, calculations, and operations in C.  
 * I pledge my honor that I have abided by the Stevens Honor System.  NMassa
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

/* Assignment #2 Additions */

char *my_strdup(char*); 
/*1  Return pointer to new, duplicate string */

char *my_strcpy(char*,char*);
/* 2 Copies entire string from source to dest */

char *my_strncpy(char*, char*, unsigned int); 
/* 3 Copies string from start up to index n to destination */

int my_strcmp(char*, char*);
/* 4 String comparison.  neg if s1<s2.  0 if same.  pos if s1>s2. */

int my_strncmp(char*, char*, unsigned int);
/* 5 String comparison up to n.  neg if s1<s2.  0 if same.  pos if s1>s2. */

void *xmalloc(unsigned int);
/* 6 Wrapper to check return type of malloc. */

char *my_strconcat(char*, char*);
/* 7 Returns a new string containing s1 followed by s2. */

char *my_strnconcat(char*, char*, unsigned int);
/* 8 Returns a new string up to index n containing s1 followed by s2. */

char *my_strcat(char*, char*);
/* 9 Copies s2 at the end of s1. */

void my_panic(char*, unsigned int);
/* 10 prints char sting and exits with exit status one */

char *my_strfind(char*, char);
/* 11 find a character and return a ptr to the first occurence of char in str*/

char *my_strrfind(char*, char);
/* 12 Find a character and return a ptr to the last occurence of char in str*/

char *my_vect2str(char**);

char **my_str2vect(char*);

int my_atoi(char*);

#endif
