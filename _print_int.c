#include "main.h"

/**
 * pr_int - prints int
 * @a: arguments
 * @f: pointer
 * Return: num of char printed
 */

int pr_int(va_list a, flags_t *f)
{
	int j = va_arg(a, int);
	int result = _length(j);

	if (f->space == 1 && f->plus == 0 && j >= 0)
		result += _write(' ');
	if (f->plus == 1 && j >= 0)
		result += _write('+');
	if (j <= 0)
		result++;
	pr_num(j);

return (result);
}

/**
 * pr_num - prints all num digits
 * @n: number
 */

void pr_num(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_write('-');
		x = -n;
	}
	else
		x = n;

	if (x / 10)
		pr_num(x / 10);
	_write((x % 10) + '0');
}

/**
 * _length - counts printed char
 * @i: integer
 * Return: num of char printed
 */

int _length(int i)
{
	unsigned int x = 0;
	unsigned int y;

	if (i < 0)
		y = i * -1;
	else
		y = i;

	while (y != 0)
	{
		y /= 10;
		x++;
	}

	return (x);
}
