/* Nicholas Massa
 * my_vect2str converts a vector to a string
 * Pre: Takes a valid vector 
 * Post: Returns a string with all elements of the vector
 *
 */

#include "my.h"

char* my_vect2str(char** vec)
{
    unsigned int strlen;
    char*        str;
    char**       temp;

    if(*vec != NULL)
    {
	 //Get length of total string
        temp = vec;
        for(strlen = 0; *vec; strlen += (my_strlen(*vec) + 1), vec++) 
            ;
        strlen--;
	 // allocate total string length
        str = (char*) xmalloc(strlen * sizeof(char));

	 //insert content into the string 
        for(vec = temp; *vec; vec++)
        {
            my_strcat(str, *vec);
            my_strcat(str, " ");
        }
        str[strlen] = '\0';
    }
    else
    {
        str = my_strdup(""); 
    }

    return str;
}
