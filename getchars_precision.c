#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @checklist: list of arguments.
 *
 * Return:precision.
 */
int get_precision(const char *format, int *i, va_list checklist)
{
	int curr_i = *i + 1;
	int accuracy = -1;

	if (format[curr_i] != '.')
		return (accuracy);

	accuracy = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
		
			accuracy *= 10;
			accuracy += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			accuracy = va_arg(checklist, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (accuracy);
}
