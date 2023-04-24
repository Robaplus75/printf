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
 * to_binary - converts number to binary and also prints
 * @num: number to be converted
 * Return: number of characters printed
 */

int to_binary(int num)
{
	int digit[10], i, counter = 0;

	for (i = 0; num > 0; i++)
	{
		digit[i] = num % 2;
		num = num / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		num_print(digit[i]);
		counter++;
	}
	return (counter);
}

/**
 * type_handler - it prints the appropirate datatype
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
		case 'b':
			(*counter) += to_binary(va_arg(list, int));
			break;
		default:
			_putchar(format[i]);
			(*counter)++;
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


	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
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
