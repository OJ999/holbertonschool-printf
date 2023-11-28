#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    // ... (Previous code)

    // Handle %s with precision
    ++i;
    if (format[i] == 's')
    {
        char *str = va_arg(list, char *);
        int precision = get_precision(format, &i, list);

        if (precision >= 0)
            printed = print_string(buffer, &buff_ind, str, precision);
        else
            printed = print_string(buffer, &buff_ind, str, INT_MAX);

        if (printed == -1)
            return (-1);
        printed_chars += printed;
    }


/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
