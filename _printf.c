#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

int print_positive_integer(int num);

/**
 * print_integer - Print an integer
 * @args: va_list containing the integer to print
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}

	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		count += print_positive_integer(num);
	}

	return (count);
}

/**
 * print_positive_integer - Print a positive integer
 * @num: The positive integer to print
 * Return: Number of characters printed
 */
int print_positive_integer(int num)
{
	int count = 0;
	char digit;

	if (num / 10 != 0)
		count += print_positive_integer(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}

/**
 * _printf - Printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_integer(args);
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				printed_chars += 2;
			}
		}
		i++;
	}

	va_end(args);

	return (printed_chars);
}
