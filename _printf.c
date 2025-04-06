#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * _printf - prints formatted string with c, s, %, d, and i
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));

			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}

			else if (format[i] == '%')
				count += _putchar('%');

			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));

			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
	}

	va_end(args);

	return (count);
}
