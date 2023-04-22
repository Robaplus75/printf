#include "main.h"

/**
 * num_print - prints a number
 * @num: the number tobe printed
 * @pCount: increments the counter
 * Return: none
 */

void num_print(unsigned int num, int *pCount)
{
	if ((int)num < 0)
	{
		_putchar('-');
		*pCount += 1;
		num *= -1;
	}
	/* check if the num not one digit */
	if (num / 10)
		_putInt(num / 10, pCount); /* call the fun again if not one digit */
	/* print the num in ascii by adding 48  */
	_putchar(num % 10 + '0');
	*pCount += 1;
}
