#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
void handle_percent(int *count);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_int(va_list args, int *count);

#endif