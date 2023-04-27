#include "main.h"

void print_buffer(char buffer[], int *buff_len);

/**
 * _printf - Custom printf function that handles various format
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_len = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_len++] = format[i];
			if (buff_len == BUFF_SIZE)
				print_buffer(buffer, &buff_len);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_len);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_len);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer, if it exists
 * @buffer: Array of characters to print
 * @buff_len: Length of the buffer
 */
void print_buffer(char buffer[], int *buff_len)
{
	if (*buff_len > 0)
		write(1, &buffer[0], *buff_len);

	*buff_len = 0;
}
