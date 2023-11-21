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

    if (!format)
        return -1; // Handle NULL format

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == '\0')
                break; // Ignore a single '%' at the end of the string

            if (*format == 'c')
            {
                char char_arg = va_arg(args, int);
                printed_chars += write(1, &char_arg, 1);
            }
            else if (*format == 's')
            {
                const char *str_arg = va_arg(args, const char *);
                if (str_arg)
                    printed_chars += write(1, str_arg, _strlen(str_arg));
            }
            else if (*format == '%')
            {
                printed_chars += write(1, "%", 1);
            }
            // Add more format specifiers as needed

            // Move to the next character in the format string
            format++;
        }
        else
        {
            printed_chars += write(1, format, 1);
            format++;
        }
    }

    va_end(args);
    return printed_chars;
}

/**
 * _strlen - Calculate the length of a string
 * @s: Input string
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}
