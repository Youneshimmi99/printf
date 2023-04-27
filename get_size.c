#include "main.h"

/**
 * get_size - Calculates the size modifier to use for printing
 * @format: Formatted string where we print the arguments
 * @i: pointer to integer of current position of the format string
 *
 * Return: Integer representing the size modifier to use for printing
 */
int get_size(const char *format, int *i)
{
	int current_i = *i + 1;
	int size = 0;

	if (format[current_i] == 'l')
		size = S_LONG;
	else if (format[current_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (size);
}
