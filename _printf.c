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

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len])
					len++;
				write(1, str, len);
				count += len;
			}
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				count += 2;
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
