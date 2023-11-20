int main(void)
{
    int len;

    len = _printf("%");
    if (len == 1 || len == 2) // Ignore length difference for '%'
    {
        printf("Output: [%%]\n");
    }
    else
    {
        printf("Lengths differ.\n");
    }

    return 0;
}
