#include "main.h"

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
		case 'r':
			str = va_arg(list, char *);
			(*counter) += to_reverse(str);
			break;
		case 'R':
			str = va_arg(list, char *);
			(*counter) += to_Rot13(str);
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


	if (format == NULL)
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
