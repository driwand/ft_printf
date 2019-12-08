#include <stdlib.h>
#include <stdio.h>

int ft_printf(const char*, ...);

int main()
{   
    // %[flags][width][.precision][length] specifier
    /*
        flags : - | 0
        width : number | *
        precision : .number | .*
    */

    int r = 2541;
    int k = 23;
    char *s = "hr";
    char c = 'q';
    char *str = "hello";

    int *p;
    p = &k;
    char *adr = (char *)&r;
    printf("\n%d\n", ft_printf("%5u*w", -12));
    printf("\n%d\n", printf("%5u*w", -12));
    // ft_printf("%02c\n", 'r');
    // printf("%*c\n",2, 'c');
    return (0);
}