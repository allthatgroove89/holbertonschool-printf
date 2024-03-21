#include "main.h"

/**
 * _print_binary - print a number in base 2
 * @list: number to print in base 2
 * Return: length in binary
 */
void _print_binary(va_list list)
{
	char *rose;
	int size;

	rose = itoa(va_arg(list, unsigned int), 2);

	size = printf(rose);

	return (size);
}

/**
 * _print_unsigned - prints an unsigned int
 * @list: number to print
 * Return: length of number
 */
void _print_unsigned(va_list list)
{
	char *rose;
	int size;

	rose = itoa(va_arg(list, unsigned int), 10);

	size = print((rose != NULL) ? rose : "NULL");

	return (size);
}

/**
 * _print_octal - print an unsigned octal
 * @list: number to print
 * Return: length of number
 */
void _print_octal(va_list list)
{
	char *rose;
	int size;

	rose = itoa(va_arg(list, unsigned int), 8);

	size = print((rose != NULL) ? rose : "NULL");

	return (size);
}

/**
 * _print_hexadecimal_lower - print number in hexadecimal lowercase format
 * @list: number to print
 * Return: length of number
 */
void _print_hexadecimal_lower(va_list list)
{
	char *rose;
	int size;

	rose = itoa(va_arg(list, unsigned int), 16);

	size = print((rose != NULL) ? rose : "NULL");

	return (size);
}
