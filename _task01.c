#include "main.h"

/**
 * pr_string - print string
 * @a: arguments
 * @g: pointer
 * Return: number of char printed
 */

int pr_string(va_list a, flag_t *g)
{
	char *s = va_arg(a, char *);

	(void)g;

	if (!s)
		s = "(null)";
	return (_write_str(s));
}

/**
 * pr_char - prints a char
 * @a: argument
 * @g: pointer
 * Return: number of char printed
 */

int pr_char(va_list a, flag_t *g)
{
	(void)g;

	_write(va_arg(a, int));

	return (1);
}

/**
 * pr_percent - prints a precent
 * @a: arguments
 * @g: pointer
 * Return: number of char printed
 */

int pr_percent(va_list a, flag_t *g)
{
	(void)a;
	(void)g;

	return (_write('%'));
}
