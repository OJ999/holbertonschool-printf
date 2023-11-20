#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;
    unsigned int ui;

    len = _printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;

    _printf("Length: [%d]\n", len);
    _printf("Unsigned: [%u]\n", ui);

    return (0);
}