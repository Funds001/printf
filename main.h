#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _putchar(char c);
int _print(const char *format, ...);
int print_percent(va_list args __attribute__((unused)));
int print_string(va_list args);
int print_char(va_list args);
#endif
