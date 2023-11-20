#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>  // Include this for the strlen function

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;
            switch (*ptr)
            {
            case 'c':
                c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            case 's':
                str = va_arg(args, char *);
                fputs(str, stdout);
                count += (int)strlen(str);
                break;
            case '%':
                putchar('%');
                count++;
                break;
            default:
                /* Handle unknown format specifier */
                putchar('%');
                putchar(*ptr);
                count += 2;
                break;
            }
        }
        else
        {
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);

    return count;
}
