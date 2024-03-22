#include "main.h"
/**
 * handle_format_specifier - a function that handles the format specifier
 * @format: the format specifier
 * @args: the list of arguments
 * @count: the count of characters printed
 * Return: void
 */
void handle_format_specifier(char format, va_list args, int *count)
{
	switch (format)
	{
		case '%':
			handle_percent(count);
			break;
		case 'c':
			handle_char(args, count);
			break;
		case 's':
			handle_string(args, count);
			break;
		case 'd':
		case 'i':
			handle_int(args, count);
			break;
		default:
			write(1, &format, 1);
			count += 2;
			break;
	}
}
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
			handle_format_specifier(format[i], args, &count);
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
