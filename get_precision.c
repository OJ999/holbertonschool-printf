#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index in the format string
 * @list: List of arguments
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            if (precision < 0)
            {
                /* Handle negative precision as if it was not specified */
                precision = -1;
            }
            break;
        }
        else
        {
            break;
        }
    }

    *i = curr_i - 1;

    return (precision);
}

/**
 * print_string - Print a string to the buffer with precision
 * @buffer: Buffer to print to
 * @buff_ind: Index at which to add next char, represents the length.
 * @str: String to print
 * @precision: Maximum number of characters to print
 * Return: Number of characters printed
 */
int print_string(char buffer[], int *buff_ind, const char *str, int precision)
{
    int i;

    for (i = 0; i < precision && str[i] != '\0'; i++)
    {
        buffer[*buff_ind] = str[i];
        (*buff_ind)++;
        if (*buff_ind == BUFF_SIZE)
            print_buffer(buffer, buff_ind);
    }

    return i; // Return the number of characters printed
}
