#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	const char *m;
	int (*pr)(va_list, flags_t *);
	flags_t flags = {0, 0, 0, 0, 0};
	va_list argus;

	register int leng = 0;


	va_start(argus, format);

	if (!format || (!format[1] && format[0] == '%'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (m = format; *m; m++)
	{
		if (*m == '%')
		{
			m++;
			if (*m == '%')
			{
				leng += _write('%');
				continue;
			}
			while (p_flag(*m, &flags))
				m++;
			pr = _pr_spf(*m);
			leng += (pr)
				? pr(argus, &flags)
				: _printf("%%%c", *m);
		}
		else
			leng += _write(*m);
	}
	_write(-1);
	va_end(argus);
	return (leng);
}
