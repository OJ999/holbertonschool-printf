#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        /* Handle NULL format input */
        return 0;  /* or any other appropriate action */
    }

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
                    {
                        char c = (char)va_arg(args, int);
                        count += write(1, &c, 1);
                    }
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

int main(void)
{
    /* Example usage */
int len = _printf(NULL);
_printf("Length: [%d]\n", len);

len = _printf("%%");
_printf("Length: [%d]\n", len);

return 0;
}
