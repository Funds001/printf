#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_char - print a single character
 * @args: a va_list containing the character to point
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string- print a string
 * @args: a va_list containing the string to print
 * Return: the nurmber of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	for (; *str; ++str)
	{
		_putchar(*str);
		++len;
	}
	return (len);
}

/**
 * print_percent - print percent sign
 * @args: unused
 * Return: the number of character printed
 */

int print_percent(va_list args __attribute__((unused)))
{
	return (write(1, "%", 1));
}

/**
* print_int - print an integer
* @args: a va_list containing the integer to print
* Return: the number of characters printed
*/
int print_int(va_list args)
{
	int n = va_arg(args, int);
	char buffer[12];

	int len = snprintf(buffer, sizeof(buffer), "%d", n);

	return (write(1, buffer, len));
}

/**
 * print_binary - print an unsigned int in binary
 * @args: a va_list containing the unsigned int to print
 * Return: the number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		buffer[i] = (n & 1) + '0';
		n >>= 1;
		i++;
	}

	i--;

	while (i >= 0)
	{
		write(1, &buffer[i], 1);
		i--;
	}

	return (i);
}

/**
 * _printf - produce output according to format
 * @format: a character string containing directives
 * Return: the number of character printed (excluding null bytes)
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
			else if (format[i] == 'd' || format[i] == 'i')
				pc += print_int(args);
			else if (format[i] == 'b')
				pc += print_binary(args);
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
