#include <stdio.h>
#include "main.h"
/**
 * str_print - prints a string
 * @str: the string to be printed
 * @count: counts the number of characters printed
 * Return: none
 */

void str_print(char *str, int *count)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		*count += 1;
	}
}
