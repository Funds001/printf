#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* _printf - produces output according to a format
* @format: a character string containing directives
* Return: the number of characters printed (excluding null bytes)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int pc = 0;
	int i;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			pc++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					pc += _putchar(va_arg(args, int));
					break;
				case 's':
				{
					char *str = va_arg(args, char *);
					if (str)
					{
						for (i = 0; str[i]; i++)
						{
							pc += _putchar(str[i]);
						}
					}
					else
					{
						pc += _putchar('(');
						pc += _putchar('n');
						pc += _putchar('i');
						pc += _putchar('l');
						pc += _putchar(')');
					}
					break;
				}
				case '%':
					pc += _putchar('%');
					break;
				default:
					return (-1);
			}
		}
		format++;
	}
	va_end(args);
	return (pc);
}
