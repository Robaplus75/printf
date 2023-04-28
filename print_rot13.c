#include "main.h"

/**
 * to_Rot13 - reverse string
 * @str: string
 * Return: number of characters printed
 */

int to_Rot13(char *str)
{
	int i = 0, index = 0, count = 0;
	char arr_upper[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	char arr_lower[] = "nopqrstuvwxyzabcdefghijklm";


	if (str)
	{
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				index = str[i] - 65;
				count += _putchar(arr_upper[index]);
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				index = str[i] - 97;
				count += _putchar(arr_lower[index]);
			}
			else
				count += _putchar(str[i]);

			i++;
		}
	}
	return (count);
}

