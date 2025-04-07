#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				printed += print_char(args);
			else if (format[i] == 's')
				printed += print_string(args);
			else if (format[i] == '%')
				printed += print_percent();
			else
			{
				printed += _putchar('%');
				printed += _putchar(format[i]);
			}
		}
		else
		{
			printed += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (printed);
}
