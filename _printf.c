/* _printf.c */

#include "main.h"
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars;

    (void)format; /* To silence the unused parameter warning */

    /* Example: printing a string */
    const char *str;
    int str_len;

    /* Start processing variable arguments */
    va_start(args, format);

    /* Assign values to variables after variable declarations */
    str = "Hello, world!";
    str_len = 13; /* The length of the string */

    /* End processing variable arguments */
    va_end(args);

    printed_chars = write(1, str, str_len); /* Assuming write is used to print to stdout */

    return printed_chars;
}
