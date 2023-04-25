#include "main.h"

/**
 * num_print - prints integer numbers
 * @num: the number to printed
 * Return: the number of characters printed
 */

int num_print(int num)
{
	int divisor = 1000000000;
	int digits[10];
	int i, remove_zero, counter = 0;

	digits[0] = num / divisor;
	for (i = 1; i < 10; i++)
	{
		divisor /= 10;
		digits[i] = (num / divisor) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		counter++;
		for (i = 0; i < 10; i++)
		{
			digits[i] *= -1;
		}
	}
	for (i = 0, remove_zero = 0; i < 10; i++)
	{
		remove_zero += digits[i];
		if (remove_zero != 0 || i == 9)
		{
			_putchar('0' + digits[i]);
			counter++;
		}
	}
	return (counter);
}

