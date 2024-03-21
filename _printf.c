#include "main.h"


/**
 * handle_percent - a function that handles the percent sign
 * @count: the count of characters printed
 * Return: void
 */
void handle_percent(int *count)
{
	char c = '%';

	write(1, &c, 1);
	(*count)++;
}

/**
 * handle_char - a function that handles the char
 * @args: the list of arguments
 * @count: the count of characters printed
 * Return: void
 */
void handle_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * handle_string - a function that handles the string
 * @args: the list of arguments
 * @count: the count of characters printed
 * Return: void
 */
void handle_string(va_list args, int *count)
{
	char *str;
	int len;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	len = strlen(str);

	write(1, str, len);
	(*count) += len;
}

/**
 * handle_int - a function that handles the int
 * @args: the list of arguments
 * @count: the count of characters printed
 * Return: void
*/
void handle_int(va_list args, int *count)
{
	int num;
	int len;
	char str[12];

	num = va_arg(args, int);

	sprintf(str, "%d", num);

	len = strlen(str);

	write(1, str, len);
	(*count) += len;
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
		 write(1, "(null)", 6);
	 }

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
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
