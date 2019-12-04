#include <stdlib.h>
#include <stdio.h>
#include "utils.c"

int ft_printf(const char*, ...);

int main()
{
    int r = 2541;
    int k = 23;
    char *s = "hr";
    char c = 'q';
    // %[flags][width][.precision][length] specifier
    /*
        flags : - | 0
        width : number | *
        precision : .number | .*
    */
    int *p;
    p = &k;
    char *adr = (char *)&r;

    printf("%-.26s\n", "hello");

    return (0);
}
