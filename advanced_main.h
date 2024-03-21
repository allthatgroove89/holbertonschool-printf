#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
void _print_binary(va_list);
void _print_unsigned(va_list);
void _print_octal(va_list);
void _print_hexadecimal_lower(va_list);
void _print_hexadecimal_upper(va_list);

#endif
