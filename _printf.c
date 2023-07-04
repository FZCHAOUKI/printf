#include "main.h"
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
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
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				printf("%d", num);
				printed_chars += count_digits(num);
			}
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * count_digits - Count the number of digits in an integer.
 * @num: The integer to count digits.
 *
 * Return: Number of digits.
 */
int count_digits(int num)
{
	int count = 0;

	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		count++;
	}

	return (count);
}
