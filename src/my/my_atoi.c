/* Nicholas Massa
 * my_atoi takes in a char* and converts it to an integer, ignoring spacing
 * Pre: Takes in a string of characters
 * Post: Returns the integer value of the number contained in the string
 *
 */

#include "my.h"

int my_atoi(char* str)
{
	int sign;
	int result;
	if(str != NULL)
	{
        while(*str == ' ')
        {
            str++;
        }
		sign = 1;
		result = 0;
        for( ; *str && *str != ' ' && (*str == '+' || *str == '-' || (*str <= '9' && *str >= '0')); str++)
		{
			if(*str == '-')
			{
				sign *= -1;
			}
            else if(*str <= '9' && *str >= '0')
			{
				result = (result * 10) + (*str - '0');
			}
		}
		return result * sign;
	}
	return 0;
}
