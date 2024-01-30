#include "main.h"

/**
 * _printf - Mimics printf
 * @format: string of char
 *
 * Return: lenght of output
 */

int _printf(const char *format, ...)
{
	int output_count = 0;
	int str_len;
	char c, *str;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			output_count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
				output_count++;
			}
			if (*format == 's')
			{
				str = va_arg(ap, char*);
				str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				output_count += str_len;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				output_count++;
			}
			if (*format == '\0')
				break;
		}

		format++;
	}

	va_end(ap);

	return (output_count);
}
