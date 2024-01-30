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
	va_list ap;

	if (!format || (format[0] == '%' && format[1] == '\0'))
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
				char c = va_arg(ap, int);

				write(1, &c, 1);
				output_count++;
			}
			if (*format == 'i' || *format == 'd')
			{
				int n = va_arg(ap, int);
				int num, last_digit = n % 10, digit, exp = 1;
				int  i = 1;

				n = n / 10;
				num = n;
				
				if (last_digit < 0)
				{
					_putchar('-');
					num = -num;
					n = -n;
					last_digit = -last_digit;
					i++;
				}
				if (num > 0)
				{
					while (num / 10 != 0)
					{
						exp = exp * 10;
						num = num / 10;
					}

					num = n;
					
					while (exp > 0)
					{
						digit = num / exp;
						_putchar(digit + '0');
						num = num - (digit * exp);
						exp = exp / 10;
						i++;
					}
				}
				
				_putchar(last_digit + '0');
			}
			if (*format == 's')
			{
				char *str = va_arg(ap, char*);
				int str_len = 0;
				
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
		}

		format++;
	}

	va_end(ap);

	return (output_count);
}
