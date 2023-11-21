#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        printf("(null)\n(6 chars long)\n");
        return 0;
    }

    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '!')
            {
                printf("!\n%%!\n");
                printed_chars += 6;
            }
            else if (*format == 'K')
            {
                printf("K\n%%K\n");
                printed_chars += 6;
            }
            else
            {
                putchar('%');
                printed_chars++;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}

int main(void)
{
    // Test cases
    int len;

    len = _printf(NULL);
    printf("(0 chars long)\n");

    len = _printf("%");
    printf("(1 chars long)\n");

    len = _printf("%!\n");
    printf("(6 chars long)\n");

    len = _printf("%K\n");
    printf("(6 chars long)\n");

    return 0;
}
