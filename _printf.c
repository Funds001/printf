#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
* print_char - print a single character
* @args:  a va_list containing the character to print
* Return: the number of characters printed
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
* print_string - print a string
* @args: a va_list containing the string to print
* Return: the  numbers of characters printed
*/
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;
	return (write(1, str, len));
}

/**
* print_percent - print a percent sign
* @args: unused
* Return: the number of character printed
*/
int print_percent(va_list args __attribute__((unused)))
{
	return (write(1, "%", 1));
}

/**
* _printf - produces output according to a format
* @format: a character string containing directives
* Return: the number of characters printed (excluding null bytes)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int pc = 0, i = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			pc += write(1, &format[i], 1);
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'c')
				pc += print_char(args);
			else if (format[i] == 's')
				pc += print_string(args);
			else if (format[i] == '%')
				pc += print_percent(args);
			else
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (pc);
}
