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




