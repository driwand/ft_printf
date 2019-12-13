/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:21:53 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/13 18:43:41 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int main()
{
    unsigned long p;
    char *str = "hello";

    /* ----------------------     integer     ---------------------- */

//     printf("%d\n", ft_printf("%09.*d\n", -1, 22));
//     printf("%d\n", printf("%09.*d\n", -1, 22));

    /* unsigned */
//     printf("%u\n", ft_printf("%015.3d\n", UINT32_MAX + 2));
//     printf("%u\n", printf("%015.3d\n", UINT32_MAX + 2));

//    printf("%u\n", ft_printf("%*d\n",4, -3));
//    printf("%u\n", printf("%*d\n",4, -3));
    
//     printf("%d\n", ft_printf("%*10.*d\n", 4,3, 80));
//     printf("%d\n", printf("%*10.*d\n", 4,3, 80));

//     printf("%u\n", ft_printf("%015.6u\n", UINT32_MAX + 95));
//     printf("%u\n", printf("%015.6u\n", UINT32_MAX + 95));

//     printf("%u\n", ft_printf("%u\n", UINT32_MAX));
//     printf("%u\n", printf("%u\n", UINT32_MAX));

//     printf("%d\n", ft_printf("%5d\n", 4));
//     printf("%d\n", printf("%5d\n", 4));

//     printf("%d\n", ft_printf("%05d\n", -4));
//     printf("%d\n", printf("%05d\n", -4));

//     printf("%d\n", ft_printf("%5.d\n", -4));
//     printf("%d\n", printf("%5.d\n", -4));

//     printf("%d\n", ft_printf("%*d\n",4, -3));
//     printf("%d\n", printf("%*d\n",4, -3));

//     printf("%d\n", ft_printf("%-*.*d\n", 4,3,1));
//     printf("%d\n", printf("%-*.*d\n",4,3, 1));
//
//     printf("\n%d\n", ft_printf("%04d", 5));
//     printf("\n%d\n", printf("%04d", 5));

//     printf("\n%d\n", ft_printf("%05.3d", 12));
//     printf("\n%d\n", printf("%05.3d", 12));

//     printf("\n%d\n", ft_printf("%5.d", 0));
//     printf("\n%d\n", printf("%5.d", 0));

//     printf("%d\n", ft_printf("%2.04d\n", 1));
//     printf("%d\n", printf("%2.04d\n", 1));

//     printf("\n%d\n", ft_printf("%05.0d", -12));
//     printf("\n%d\n", printf("%05.0d", -12));

//     printf("\n%d\n", ft_printf("%3.0d", 12));
//     printf("\n%d\n", printf("%3.0d", 12));

//     printf("\n%d\n", ft_printf("%05d", 12));
//     printf("\n%d\n", printf("%05d", 12));

//     printf("%d\n", ft_printf("%*.*d\n", 10, 3, 32));
//     printf("%d\n", printf("%*.*d\n", 10, 3, 32));

//     printf("%d\n", ft_printf("%0*.*d\n", 10,5, -32));
//     printf("%d\n", printf("%0*.*d\n", 10,5, -32));

//     printf("%d\n", ft_printf("%*.05d\n", 10, 32));
//     printf("%d\n", printf("%*.05d\n", 10, 32));

     printf("%d\n", ft_printf("%20d\n", -2147483647));
     printf("%d\n", printf("%20d\n", -2147483647));

    // printf("%d\n", ft_printf("%4d\n", 2));
    // printf("%d\n", printf("%4d\n", 2));

    // printf("%d\n", ft_printf("%0-4d\n", 2));
    // printf("%d\n", printf("%0-4d\n", 2));

    // printf("%d\n", ft_printf("%-.3d\n",-2));
    // printf("%d\n", printf("%-.3d\n",-2));

    // printf("%d\n", ft_printf("%05.3d\n", 12));
    // printf("%d\n", printf("%05.3d\n", 12));

    // printf("%d\n", ft_printf("%4.2d\n", 0));
    // printf("%d\n", printf("%4.2d\n", 0));

    // printf("%d\n", ft_printf("%04i\n", 22));
    // printf("%d\n", printf("%04i\n", 22));

    // printf("%d\n", ft_printf("%4.2d\n", 1));
    // printf("%d\n", printf("%4.2d\n", 1));

    // printf("%d\n", ft_printf("%*.*d\n", 4, 4, 1));
    // printf("%d\n", printf("%*.*d\n", 4, 4, 1));

    /* ----------------------       hexa      ---------------------- */

    // printf("%d\n", ft_printf("%-6.x\n", 1533));
    // printf("%d\n", printf("%-6.x\n", 1533));

    // printf("%d\n", ft_printf("%x\n", UINT32_MAX + INT32_MIN));
    // printf("%d\n", printf("%x\n", UINT32_MAX + INT32_MIN));

    // printf("%d\n", ft_printf("%x\n", UINT32_MAX - 1));
    // printf("%d\n", printf("%x\n", UINT32_MAX - 1));
    
    // printf("%d\n", ft_printf("%-5x\n", 1512));
    // printf("%d\n", printf("%-5x\n", 1512));

    // printf("%d\n", ft_printf("%5.*x\n",4, 1512));
    // printf("%d\n", printf("%5.*x\n",4, 1512));

    // printf("%d\n", ft_printf("%015x",0x99));
    // printf("%d\n", printf("%015x",0x99));
    
    // printf("%d\n", ft_printf("%*X",300, 1));
    // printf("%d\n", printf("%*X",300, 1));

    // printf("%d\n", ft_printf("%015x",99));
    // printf("%d\n", printf("%015x",99));
    
    // printf("%d\n", ft_printf("%x\n",0));
    // printf("%d\n", printf("%x\n",0));
    
    // printf("%d\n", ft_printf("%p\n",(void *)0x100));
    // printf("%d\n", printf("%p\n",(void *)0x100));

    // printf("%d\n", ft_printf("%---15X %00015x\n",33, 0x99));
    // printf("%d\n", printf("%---15X %00015x\n",33, 0x99));
    
    /* ----------------------      huh??      ---------------------- */

    // printf("\n%d\n", ft_printf("%5*w", -12));
    // printf("\n%d\n", printf("%5*w", -12));

    // printf("\n%d\n", ft_printf("%3.*", 12));
    // printf("\n%d\n", printf("%3.*", 12));

    /* ----------------------     string 	  ---------------------- */

    // printf("%d\n", ft_printf("%*.*s\n", 6, 2, "hello"));
    // printf("%d\n", printf("%*.*s\n", 6, 2, "hello"));

    // printf("%d\n", ft_printf("%10*.1*s\n", 7,3,"hello"));
    // printf("%d\n", printf("%10*.1*s\n", 7,3,"hello"));

    // printf("%d\n", ft_printf("%-*.*s,%.s,%s|%-6s|,>%s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 2, "TYUI"));
    // printf("%d\n", printf("%-*.*s,%.s,%s|%-6s|,>%s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 2, "TYUI"));

    // printf("%d\n", ft_printf("%*.*s %s,%-3.*s '%-2c-%.c'||%s<%%>\n", 6, 2, "hello" , NULL, 1,"ld", 'r', 0,"wow"));
    // printf("%d\n", printf("%*.*s %s,%-3.*s '%-2c-%.c'||%s<%%>\n", 6, 2, "hello" , NULL, 1,"ld", 'r', 0,"wow"));

    // ft_printf("%*2s\n", 2, "h");
    // printf("%*2s\n", 2, "h");

    // ft_printf("%*s\n", 0, "h");
    // printf("%*s\n", 0, "h");

    /* ----------------------      NULL       ---------------------- */

    // printf("%d\n", ft_printf("%1.1s\n", NULL));
    // printf("%d\n", printf("%1.1s\n", NULL));

    // printf("\n%d\n", ft_printf("%*.*s", -15, 0, NULL));
    // printf("\n%d\n", printf("%*.*s", -15, 0, NULL));

    /* ----------------------      %% && c    ---------------------- */

    // printf("%d\n", ft_printf("%-5%%02%\n"));
    // printf("%d\n", printf("%-5%%02%\n"));

    // printf("%d\n", ft_printf("%.5c\n", 50));
    // printf("%d\n", printf("%.5c\n",50));

    // printf("%d\n", ft_printf("%c\n", 0));
    // printf("%d\n", printf("%c\n", 0));

    /* ----------------------    address     ---------------------- */

    // printf("%d\n", ft_printf("%*p\n", -16, &p));
    // printf("%d\n", printf("%*p\n", -16, &p));
	
    // printf("%d\n", ft_printf("%p\n", &p));
    // printf("%d\n", printf("%p\n", &p));
	
    // printf("\n%d\n", ft_printf("%p", (void*)-12));
    // printf("\n%d\n", printf("%p", (void*)-12));

    // printf("%d\n", ft_printf("%-8p\n", (void*)0xef));
    // printf("%d\n", printf("%-8p\n", (void*)0xef));

    // printf("%d\n", ft_printf("%-8p\n", (void*)100));
    // printf("%d\n", printf("%-8p\n", (void*)100));

    /* ---------------------- ultimate test ---------------------- */

    // printf("%d\n", ft_printf("%*.*s %s,%-3.*s '%-2c-%.c'|%.%%p|%s<%0*%>\n", 6, 2, str , NULL, 1,"ld", 'r', 0, &p,"wow", 2));
    // printf("%d\n", printf("%*.*s %s,%-3.*s '%-2c-%.c'|%.%%p|%s<%0*%>\n", 6, 2, str, NULL, 1,"ld", 'r', 0, &p, "wow", 2));

    // printf("%d\n", ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 50000, 1, 300, 22, -55, 1, -60));
    // printf("%d\n", printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 50000, 1, 300, 22, -55, 1, -60));

    // printf("%d\n", ft_printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey"));
    // printf("%d\n", printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey"));

    // printf("%d\n", ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3% %---15d %00015x\n", 7,5, "ABC",15,0,20,0x99));
    // printf("%d\n", printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3% %---15d %00015x\n", 7,5, "ABC",15,0,20,0x99));

    // printf("%d\n",ft_printf("hello fghjk's %%%s%%%s call his %02%%-2%%%%s\n" ,"friend","fghjk","dad"));
    // printf("%d\n",printf("hello fghjk's %%%s%%%s call his %02%%-2%%%%s\n" ,"friend","fghjk","dad"));
}
