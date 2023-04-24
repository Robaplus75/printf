#include "main.h"

/**
 * str_print - it format string
 * @str:pointer
 *Return: number of characters
 */

int str_print(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}


