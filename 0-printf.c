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

/**
 * str_print - it format string
 * @str:pointer
 *Return: number of characters
 */

int str_print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * type_handler - it handles the datatype
 * @i: index of the format or the given string
 * @counter: counts the number of strings printed
 * @format: the given string
 * @list: its the list created for the vardiac function
 * Return: none
 */

void type_handler(int i, int *counter, const char * const format, va_list list)
{
	char *str;

	switch (format[i])
	{
		case 'c':
			_putchar(va_arg(list, int));
			(*counter)++;
			break;
		case 's':
			str = va_arg(list, char *);
			(*counter) += str_print(str);
			break;
		case '%':
			_putchar('%');
			(*counter)++;
			break;
		case 'd':
			(*counter) += num_print(va_arg(list, int));
			break;
		case 'i':
			(*counter) += num_print(va_arg(list, int));
			break;
	}
}

/**
 * _printf - it prints as printf.
 * @format: list of types of arguments
 * @...:arguments
 *Return:length
 */

int _printf(const char * const format, ...)
{
	va_list list;
	int i = 0, counter = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			type_handler(i, &counter, format, list);
		}
		else
		{
			_putchar(format[i]);
			counter++;
		}
		i++;
	}
	va_end(list);
	return (counter);
}

