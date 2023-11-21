#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing format specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    if (!format)
        return -1; // Handle NULL format

    va_list args;
    va_start(args, format);

    const char *str = format;
    int printed_chars = 0;

    while (*str)
    {
        if (*str == '%' && *(str + 1) != '\0')
        {
            str++; // Move past '%'
            char c = *str;

            switch (c)
            {
                case 'c':
                    printed_chars += write(1, va_arg(args, int), 1);
                    break;
                case 's':
                    {
                        const char *s = va_arg(args, const char *);
                        if (s)
                            printed_chars += write(1, s, strlen(s));
                        else
                            printed_chars += write(1, "(null)", 6);
                    }
                    break;
                case '%':
                    printed_chars += write(1, "%", 1);
                    break;
                default:
                    printed_chars += write(1, "%", 1);
                    printed_chars += write(1, &c, 1);
            }
        }
        else
        {
            printed_chars += write(1, str, 1);
        }

        str++;
    }

    va_end(args);

    return printed_chars;
}
