#include "main.h"

/**
 * to_reverse - reverse string
 * @str: string
 * Return: number of characters printed
 */

int to_reverse(char *str)
{
	int i = 0, length;

	if (str)
	{
		while (str[i])
			i++;

		length = i - 1;
		while (str[length])
		{
			_putchar(str[length]);
			length--;
		}
	}
	return (i);
}

