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
    va_list args;
    int printed_chars;

    if (!format)
    {
        return -1; /* Handle NULL format */
    }

    va_start(args, format);

    while (*format)
    {
        int char_arg;

        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char_arg = va_arg(args, int);
                printed_chars = write(1, &char_arg, 1);
            }
            else if (*format == 's')
            {
                const char *str = va_arg(args, const char *);
                if (str)
                    printed_chars = write(1, str, strlen(str));
                else
                    printed_chars = write(1, "(null)", 6);
            }
            else if (*format == '%')
            {
                printed_chars = write(1, "%", 1);
            }
            else
            {
                printed_chars = write(1, "%", 1);
                printed_chars += write(1, format, 1);
            }
        }
        else
        {
            printed_chars = write(1, format, 1);
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
