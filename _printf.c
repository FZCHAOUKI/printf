#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 *
 * Return: Number of characters printed (excluding the null byte).
 */

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					str++;
					printed_chars++;
				}
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
