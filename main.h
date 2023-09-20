#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <limits.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args __attribute__((unused)));
void print_buffer(char buffer[], int *buff_ind);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_print(const char *format, int *i, va_list list, char buffer[],
                        int flags, int width, int precision, int size);
#endif
