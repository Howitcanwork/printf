#include "main.h"

/**
 * pr_bi - prints number in base 2
 * @a: argument
 * @g: pointer
 * Return: number of char printed
 */

int pr_bi(va_list a, flags_t *g)
{
	unsigned int u = va_arg(a, unsigned int);
	char *s = convert(u, 10, 0);

	(void)g;

	return (_write_str(s));
}

/**
 * pr_octal - prints nymber in base 8
 * @a: va_list arguments from _printf
 * @g: pointer
 * Return: number of char printed
 */

int pr_octal(va_list a, flags_t *g)
{
	unsigned int num = va_arg(a, unsigned int);
	char *s = convert(num, 8, 0);
	int leng = 0;

	if (g->hash == 1 && s[0] != '0')
		leng += _write('0');
	leng += _write_str(str);

	return (leng);
}

/**
 * pr_hex - prints number in hexadicimal base in lowercase
 * @a: arguments
 * @g: pointer
 * Return: number of character printed
 */

int pr_hex(va_list a, flags_t *g)
{
	unsigned int num = va_arg(a, unsigned int);
	char *s = convert(num, 16, 1);
	int leng = 0;

	if (g->hash == 1 && s[0] != '0')
		leng += _write_str("0x");
	leng += _write_str(s);

	return (leng);
}

/**
 * pr_hex_big - prints number in hexamecimal base uppercase
 * @a: arguments
 * @g: pointer
 * Return: number of char printed
 */

int pr_hex_big(va_list a, flags_t *g)
{
	unsigned int num = va_arg(a, unsigned int);
	vhar *s = convert(num, 16, 0);
	int leng = 0;

	if (g->hash == 1 && s[0] != '0')
		leng += _write_str("0X");
	leng += _write_str(str);

	return (leng);
}
