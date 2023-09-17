#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: chracter string
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list argument;
	char c;
	char *s;
	int d;
	int j;
	int leng;
	char buffer[11];

	if (format == NULL)
		return (-1);
	va_start(argument, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
			format++;
		if (*format == '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else if (*format == 'c')
		{
			c = va_arg(argument, int);
			write(1, &c, 1);
			chara_print++;
		}
		else if (*format == 's')
		{
			s = va_arg(argument, char *);
			leng = 0;
			while (s[leng] != '\0')
				leng++;
			write(1, s, leng);
			chara_print += leng;
		}
		else if (*format == 'd' || *format == 'i')
		{
			d = va_arg(argument, int);
			if (d < 0)
			{
				write(1, "-", 1);
				chara_print++;
				d = -d;
			}
			j = 0;
			if (d == 0)
			{
				buffer[j] = '0';
				j++;
			}
			while (d > 0)
			{
				buffer[j] = (d % 10) + '0';
				j++;
				d /= 10;
			}
			while (j > 0)
			{
				j--;
				write(1, &buffer[j], 1);
				chara_print;
			}
		}
	}
	va_end(argument);
	return (chara_print);
}
