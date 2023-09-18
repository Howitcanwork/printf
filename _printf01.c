#include "main.h"

/**
 * pr_buff - print the buffer
 * @buffer: array
 * @buffer_index: length
 */
void pr_buff(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}

/**
 * _printf - produce output according to format
 * @format: format
 * Return: numb of char printed
 */
int _printf(const *format, ...)
{
	int i;
	int pr = 0;
	int chara_printed = 0;
	char buffer[BUFF_SIZE];
	int buffer_index = 0;
	int size = 0;
	va_list argus;

	if (format == NULL)
		return (-1);
	va_start(argus, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index = BUFF_SIZE)
				pr_buff(buffer, &buffer_index);
			chara_printed++;
		}
		else
		{
			pr_buff(buffer, &buffer_index);
			size = get_size(format, &i);
			++i;
			pr = handle_specifiers(format, &i, argus, buffer, size);
			if (pr == -1)
				return (-1);
			chara_printed += pr;
		}
	}
	pr_buff(buffer, &buffer_index);

	va_end(argus);

	return (chara_printed);
}
