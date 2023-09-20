#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <limits.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args __attribute__((unused)));
int print_int(va_list args);
#endif
