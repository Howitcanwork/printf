#include "main.h"
void pr_buff(char buffer[], int *buffer_index);

/**
 * _printf - produces output according to a format
 * @format: chracter string
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	int chara_printed = 0;
	int i;
	int pr = 0;
	int size = 0;
	int buffer_index = 0;
	char buffer[BUFF_SIZE];
	va_list argus;

	if (format == NULL)
		return (-1);
	va_start(argus, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
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

/**
 * pr_buff - prints the buffer
 * @buffer: array
 * @buffer_index: length
 */
void pr_buff(char buffer[], int *buffer_index)
{
	if (buffer_index > 0)
		write(1, &buffer[0], &buffer_index);
	*buffer_index = 0;
}
