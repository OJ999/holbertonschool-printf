#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing format specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    if (!format)
    {
        write(1, "(null)", 6);
        return -1; /* Handle NULL format */
    }

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past '%' */

            switch (*format)
            {
                case 'c':
                {
                    int char_arg = va_arg(args, int); /* Cast to int */
                    printed_chars += write(1, &char_arg, 1);
                    break;
                }
                case 's':
                {
                    const char *s = va_arg(args, const char *);
                    if (s)
                        printed_chars += write(1, s, strlen(s));
                    else
                        printed_chars += write(1, "(null)", 6);
                    break;
                }
                case '%':
                    printed_chars += write(1, "%", 1);
                    break;
                default:
                    printed_chars += write(1, "%", 1);
                    int char_arg = *format;
                    printed_chars += write(1, &char_arg, 1);
            }
        }
        else
        {
            printed_chars += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}
