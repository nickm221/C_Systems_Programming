/* Nicholas Massa
 * my_str2vect takes in a string and converts it to a vector
 * Pre: Takes in a non-null string
 * Post: Returns a vector
 *
 */

#include "my.h"

char** my_str2vect(char* str)
{
    int counter;
    int numchar;
    int numstr;
    int len;
    char* word;
    char* ptr;
    char* dupstr;
    char** retvect;

    if(str != NULL)
    {
        for(ptr = str, numstr = 0, numchar = 0; *ptr != '\0'; )
        {
	    //Pass first white space
            while(*ptr =='\t' || *ptr == ' ' || *ptr == '\n')
	 	 ptr++;
	    
            if (*ptr != '\0') 
                numstr++;
            
            for(; *ptr != '\t' && *ptr != ' ' && *ptr != '\0'; ptr++)
                numchar++;
        }
	//allocate main vect
        retvect = (char**) xmalloc((numstr + 1) * sizeof(char*));
        retvect[numstr] = NULL;

	//Place in vect
        for(counter = 0, ptr = str; counter < numstr; counter++)
        {
            while(*ptr == '\t' || *ptr == ' ' || *ptr == '\n')
		  ptr++;

            //length of word    
            for(len = 0, word = ptr; *word != '\t' && *word != ' ' && *word != '\0';  word++)
                len++;
            

            if(len != 0)
            {
                retvect[counter] = (char*) xmalloc((len + 1) * sizeof(char));
                my_strncpy(retvect[counter], ptr, len + 1);
                retvect[counter][len] = '\0';
            }
            ptr = word;
        }
    }
    else
        retvect = NULL;
    

    return retvect;
}
