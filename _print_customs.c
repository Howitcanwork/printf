#include "main.h"

/**
 * pr_binary - unsigned int convert to binary
 * @a: arguments
 * @f: pointer
 * Return: number of char printed
 */

int pr_binary(va_list a, flags_t *f)
{
	unsigned int num = va_arg(a, unsigned int);
	char *s = convert(num, 2, 0);

	(void)f;

	return (_write_str(s));
}

/**
 * pr_unsigned - prints number in base 2
 * @a: argument
 * @f: pointer
 * Return: number of char printed
 */

int pr_unsigned(va_list a, flags_t *f)
{
	unsigned int u = va_arg(a, unsigned int);
	char *s = convert(u, 10, 0);

	(void)f;

	return (_write_str(s));
}

/**
 * pr_octal - prints nymber in base 8
 * @a: va_list arguments from _printf
 * @f: pointer
 * Return: number of char printed
 */

int pr_octal(va_list a, flags_t *f)
{
	unsigned int num = va_arg(a, unsigned int);
	char *s = convert(num, 8, 0);
	int leng = 0;

	if (f->hash == 1 && s[0] != '0')
		leng += _write('0');
	leng += _write_str(s);

	return (leng);
}

/**
 * pr_hex - prints number in hexadicimal base in lowercase
 * @a: arguments
 * @f: pointer
 * Return: number of character printed
 */

int pr_hex(va_list a, flags_t *f)
{
	unsigned int num = va_arg(a, unsigned int);
	char *s = convert(num, 16, 1);
	int leng = 0;

	if (f->hash == 1 && s[0] != '0')
		leng += _write_str("0x");
	leng += _write_str(s);

	return (leng);
}

/**
 * pr_hex_big - prints number in hexamecimal base uppercase
 * @a: arguments
 * @f: pointer
 * Return: number of char printed
 */

int pr_hex_big(va_list a, flags_t *f)
{
	unsigned int num = va_arg(a, unsigned int);
	char *s = convert(num, 16, 0);
	int leng = 0;

	if (f->hash == 1 && s[0] != '0')
		leng += _write_str("0X");
	leng += _write_str(s);

	return (leng);
}
