#include "main.h"

/**
 * pr_string - print string
 * @a: arguments
 * @f: pointer
 * Return: number of char printed
 */

int pr_string(va_list a, flags_t *f)
{
	char *s = va_arg(a, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_write_str(s));
}

/**
 * pr_char - prints a char
 * @a: argument
 * @f: pointer
 * Return: number of char printed
 */

int pr_char(va_list a, flags_t *f)
{
	(void)f;

	_write(va_arg(a, int));

	return (1);
}

/**
 * pr_percent - prints a precent
 * @a: arguments
 * @f: pointer
 * Return: number of char printed
 */

int pr_percent(va_list a, flags_t *f)
{
	(void)a;
	(void)f;

	return (_write('%'));
}
