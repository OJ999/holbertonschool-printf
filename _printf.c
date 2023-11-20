#include "main.h"
#include <unistd.h>

int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    (void)format; /* To silence the unused parameter warning */

    /* Example: printing a string */
    const char *str = "Hello, world!";
    int str_len = 13; /* The length of the string */

    /* Start processing variable arguments */
    va_start(args, format);

    printed_chars = write(1, str, str_len); /* Assuming write is used to print to stdout */

    /* End processing variable arguments */
    va_end(args);

    return printed_chars;
}
