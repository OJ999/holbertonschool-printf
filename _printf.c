#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    if (!format)
    {
        return -1; /* Handle NULL format */
    }

    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = (char)va_arg(args, int);
                printed_chars += write(1, &c, 1);
            }
            else if (*format == 's')
            {
                const char *s = va_arg(args, const char *);
                if (s)
                    printed_chars += write(1, s, strlen(s));
                else
                    printed_chars += write(1, "(null)", 6);
            }
            else if (*format == '%')
            {
                printed_chars += write(1, "%", 1);
            }
            else
            {
                printed_chars += write(1, "%", 1);
                printed_chars += write(1, format, 1);
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

int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d]\n", _printf("test"));
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    return 0;
}
