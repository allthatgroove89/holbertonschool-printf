#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: format given
 * Return: output according to a format
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				return (-1);
			}
			switch (format[i])
			{
					case '%':
					handle_percent(&count);
					break;
					case 'c':
					handle_char(args, &count);
					break;
					case 's':
					handle_string(args, &count);
					break;
					case 'd':
					case 'i':
					handle_int(args, &count);
					break;
					default:
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);

	return (count);
}
