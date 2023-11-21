#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++; /* Move to the next character after '%' */
            switch (*format)
            {
            case 'c':
                printed_chars += write(1, va_arg(args, int), 1);
                break;
            case 's':
                printed_chars += write(1, va_arg(args, char *), 1);
                break;
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
