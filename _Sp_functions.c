#include "main.h"

/**
 * pr_bigS - non printable characters
 * @a: arguments
 * @f: pointer
 * Return: number of characters printed
 */

int pr_bigS(va_list a, flags_t *f)
{
	int j;
	int leng;
	char *result;
	char *s = va_arg(a, char *);

	(void)f;

	if (!s)
		return (_write_str("(null)"));

	for (j = 0; s[j]; j++)
	{
		if (s[j] > 0 && (s[j] < 32 || s[j] >= 127))
		{
			_write_str("\\x");
			leng += 2;
			result = convert(s[j], 16, 0);
			if (!result[1])
				leng += _write('0');
			leng += _write_str(result);
		}
		else
			leng += _write(s[j]);
	}
	return (leng);
}

/**
 * pr_address - prints address
 * @a: arguments
 * @f: pointer
 * Return: number of characters printed
 */

int pr_address(va_list a, flags_t *f)
{
	char *s;
	unsigned int i = va_arg(a, unsigned long int);

	register int leng = 0;

	(void)f;

	if (!i)
		return (_write_str("(nil)"));
	s = convert(i, 16, 1);
	leng += _write_str("0x");
	leng += _write_str(s);
	return (leng);
}
