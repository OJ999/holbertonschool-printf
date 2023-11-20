#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;

    len = _printf("%");
    printf("Length:[%d]\n", len);

    return (0);
}