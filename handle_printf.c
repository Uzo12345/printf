#include "main.h"

void print_buffer(char myBuffer[], int *bufferIndex);

/**
 * _print - Print function
 * @myFormat: format.
 * Return: Printed characters.
 */
int _print(const char *myFormat, ...)
{
	int i, printed = 0, printedChars = 0;
	int myFlags, myWidth, myPrecision, mySize, bufferIndex = 0;
	va_list myList;
	char myBuffer[BUFF_SIZE];

	if (myFormat == NULL)
		return (-1);

	va_start(myList, myFormat);

	for (i = 0; myFormat && myFormat[i] != '\0'; i++)
	{
		if (myFormat[i] != '%')
		{
			myBuffer[bufferIndex++] = myFormat[i];
			if (bufferIndex == BUFF_SIZE)
				print_buffer(myBuffer, &bufferIndex);
			/* write(1, &myFormat[i], 1);*/
			printedChars++;
		}
		else
		{
			print_buffer(myBuffer, &bufferIndex);
			myFlags = get_flags(myFormat, &i);
			myWidth = get_width(myFormat, &i, myList);
			myPrecision = get_precision(myFormat, &i, myList);
			mySize = get_size(myFormat, &i);
			++i;
			printed = handle_print(myFormat, &i, myList, myBuffer,
				myFlags, myWidth, myPrecision, mySize);
			if (printed == -1)
				return (-1);
			printedChars += printed;
		}
	}

	print_buffer(myBuffer, &bufferIndex);

	va_end(myList);

	return (printedChars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @myBuffer: Array of chars
 * @bufferIndex: Index at which to add next char, represents the length.
 */
void print_buffer(char myBuffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &myBuffer[0], *bufferIndex);

	*bufferIndex = 0;
}

