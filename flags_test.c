#include <stdlib.h>
#include <stdio.h>

int ft_printf(const char*, ...);

int main()
{
    int r = 2541;
    int k = 23;
    char *str = "heo";
    // %[flags][width][.precision][length] specifier
    /*
        flags : - | 0
        width : number | *
        precision : .number | .*
    */
    
    printf("%-10.5d\n", r);
    printf("%-.3d\n", r); // Left-justify flags = -
    printf("%.3d\n", r);

    printf("%0d\n", r); // Left-pads the number with zeroes (0) instead of spaces
    printf("%.d\n", r);
    printf("%d\n", r);
    return (0);
}