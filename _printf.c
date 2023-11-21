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
    if (!format)
    {
        write(1, "(null)", 6);
        return -1; /* Handle NULL format */
    }

    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past '%' */

            char c;
            int char_arg;
            const char *s;

            switch (*format)
            {
                case 'c':
                    char_arg = va_arg(args, int); /* Cast to int */
                    printed_chars += write(1, &char_arg, 1);
                    break;
                case 's':
                    s = va_arg(args, const char *);
                    if (s)
                        printed_chars += write(1, s, strlen(s));
                    else
                        printed_chars += write(1, "(null)", 6);
                    break;
                case '%':
                    printed_chars += write(1, "%", 1);
                    break;
                default:
                    printed_chars += write(1, "%", 1);
                    c = *format;
                    printed_chars += write(1, &c, 1);
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
