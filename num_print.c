#include "main.h"

/**
 * num_print - prints a number
 * @num: the number tobe printed
 * Return: none
 */

void num_print(int num)
{
	char buffer[20];
	int len = 0, i;
	char *str;

	if (num < 0)
	{
		num *= -1;
		buffer[0] = '-';
		len++;
	}
	do {
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return;
	}
	for (i = 0; i < len; i++)
	{
		str[i] = buffer[(len - i) - 1];
	}
	str[len] = '\0';
	write(STDOUT_FILENO, str, len);
	free(str);
}
