#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h> /* Include for strlen function */

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    if (!format)
        return -1; /* Handle NULL format */

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move to the next character after '%' */
            if (!*format)
                break; /* Stop if '%' is at the end of the string */

            switch (*format)
            {
            case 'c':
            {
                char c = (char)va_arg(args, int); /* Cast to char */
                printed_chars += write(1, &c, 1);
                break;
            }
            case 's':
            {
                char *str = va_arg(args, char *);
                if (str)
                    printed_chars += write(1, str, strlen(str));
                else
                    printed_chars += write(1, "(null)", 6);
                break;
            }
            case '%':
                printed_chars += write(1, "%", 1);
                break;
            default:
                /* Ignore unsupported conversion specifiers */
                break;
            }
        }
        else
        {
            printed_chars += write(1, format, 1);
        }

        format++; /* Move to the next character in the format string */
    }

    va_end(args);

    return printed_chars;
}
