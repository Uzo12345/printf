#include "main.h"

/**
 * get_size - Calculates the sizes to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sizes = 0;

	if (format[curr_i] == 'l')
		sizes = S_LONG;
	else if (format[curr_i] == 'h')
		sizes = S_SHORT;

	if (sizes == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sizes);
}
