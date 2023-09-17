#include "main.h"

/**
 * main - Entry point
 * Description - printf project
 * Return: 0
 */

int main(void)
{
/**
 *  * _print_simple - print %
 *   * @std: standard output
 *    * @string: string we wanna print
 *     * @leng: lenght
 *      * Return: VOID
 *       */
void _print_simple(int std, const char *string, int leng)
{
	write(std, string, leng);
}

/**
 *  * _specifiers - solution for specifiers
 *   * @std: standard output
 *    * @specf: specifier
 *     * @argu: location
 *      * @chara_print: return value
 *       * Return: characters printed
 *        */


void _specifiers(int std, char specf, va_list argu, int *chara_print)
{
	char c, *s;
	char buff[3];
	int i;

	buff[0] = '%';
	buff[1] = specf;
	buff[2] = '\0';
	switch (specf)
	{
		case 'c':
			c = (char)va_arg(argu, int);
			_print_simple(std, &c, 1);
			*chara_print += 1;
			break;
		case 's':
			s = va_arg(argu, char *);
			_pr_str(std, s, chara_print);
			break;
		case '%':
			_pr_perc(std, chara_print);
			break;
		case 'd':
			i = va_arg(argu, int);

			_pr_num(std, i, chara_print);
			break;
		case 'i':
			i = va_arg(argu, int);
			_pr_num(std, i, chara_print);
			break;
		default:
			_print_simple(std, buff, 2);
			*chara_print += 2;
			break;
	}
}
/**
 *  * _printf - produces output according to a format
 *   * @format: character string
 *    * Return: number of characters printed
 *     */

int _printf(const char *format, ...)
{
	va_list argu;
	int chara_print = 0;

	if (format == NULL)
		return (-1);
	va_start(argu, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			_specifiers(1, *format, argu, &chara_print);
		}
		else
		{
			_print_simple(1, format, 1);
			chara_print++;
		}
		format++;
	}
	va_end(argu);
	return (chara_print);
}
}
