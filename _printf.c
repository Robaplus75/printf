#include "main.h"

/**
 * _printf - has similar characteristics with printf
 * @format: the string
 * Return: length of string
 */

int _printf(const char *format, ...)
{
	va_list list;
	unsigned int i, counter = 0;
	char *str;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i += 1;
			switch (format[i])
			{
			case 'c':
				_putchar(va_arg(list, int));
				counter += 1;
				break;
			case 's':
				str = va_arg(list, char *);
				str_print(str, &counter);
				break;
			}
		}
		else
		{
			_putchar(format[i]);
			counter += 1;
		}
	}
	va_end(list);
	return (counter);
}
