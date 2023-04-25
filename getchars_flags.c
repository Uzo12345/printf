#include "main.h"

/**
 * get_flags - Calculates active flag
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flag:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, curr_i;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (k = 0; FLAG_CH[k] != '\0'; k++)
			if (format[curr_i] == FLAG_CH[k])
			{
				flag |= FLAG_ARR[k];
				break;
			}

		if (FLAG_CH[k] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flag);
}
