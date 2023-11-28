#include "main.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
    }

    *buff_ind = 0;
}

int get_precision(const char *format, int *i, va_list list)
{
    /* Your existing implementation for get_precision */
} 

int print_string(char buffer[], int *buff_ind, const char *str, int precision)
{
    int i;

    for (i = 0; i < precision && str[i] != '\0'; i++)
    {
        buffer[*buff_ind] = str[i];
        (*buff_ind)++;
        if (*buff_ind == BUFF_SIZE)
        {
            print_buffer(buffer, buff_ind);
        }
    }

    return i; /* Return the number of characters printed */
}
