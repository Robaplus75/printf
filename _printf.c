#include "main.h"
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
 * _printf - it prints as printf.
 * @format: list of types of arguments
 * @...:arguments
 *Return:length
 */

int _printf(const char * const format, ...)
{
	va_list list;
	unsigned int i = 0;
	int counter = 0;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
		i++;
			switch (format[i])
			{
			case 'c':
				_putchar(va_arg(list, int));
				counter++;
				break;
			case 's':
				str = va_arg(list, char *);
				counter += str_print(str);
				break;
			case '%':
				_putchar('%');
				counter++;
				break;
			}
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
