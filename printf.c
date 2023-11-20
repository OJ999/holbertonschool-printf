#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function with basic format specifiers
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            switch (*(++ptr))
            {
                case 'c':
                    count += write(1, &(char){va_arg(args, int)}, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                        count += write(1, str++, 1);
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, &(*ptr), 1);
                    break;
            }
        }
        else
        {
            count += write(1, &(*ptr), 1);
        }
    }

    va_end(args);
    return count;
}
