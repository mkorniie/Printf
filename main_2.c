#include <stdio.h>
#include "header.h"
int		ft_printf(const char * restrict format, ...);
#include <locale.h>
#include <limits.h>

int main(void)
{
//	int i;
	int size1;
	int size2;

	setlocale(LC_ALL, "");

//    size1 = printf("1a%Sb%sc%S\n", L"我", "42", L"猫");

//    size2 = ft_printf("2a%Sb%sc%S\n", L"我", "42", L"猫");

//    while (1)
//    {
//
//    }
//    printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
while(1) {
    ft_printf("\n");
    ft_printf("%%\n");
    ft_printf("%d\n", 42);
//    while (1) {
    ft_printf("%d%d\n", 42, 41);
//        ft_printf("%D", 0L);
//        ft_printf("%D", 1L);
//        ft_printf("%D", -1L);
//        ft_printf("%D", 42L);
//    ft_printf("%15.4d", -42);
//    }
    ft_printf("%d%d%d\n", 42, 43, 44);
    ft_printf("%ld\n", 2147483647);
    ft_printf("%lld\n", 9223372036854775807);
    ft_printf("%x\n", 505);
    ft_printf("%X\n", 505);
    ft_printf("%p\n", &ft_printf);
    ft_printf("%20.15d\n", 54321);
    ft_printf("%-10d\n", 3);
    ft_printf("% d\n", 3);
    ft_printf("%+d\n", 3);
    ft_printf("%010d\n", 1);
    ft_printf("%hhd\n", 0);
    ft_printf("%jd\n", 9223372036854775807);
    ft_printf("%zd\n", 4294967295);
    ft_printf("%\n");
    ft_printf("%U\n", 4294967295);
    ft_printf("%u\n", 4294967295);
    ft_printf("%o\n", 40);
    ft_printf("%%#08x\n", 42);
    ft_printf("%x\n", 1000);
    ft_printf("%#X\n", 1000);
    ft_printf("%s\n", NULL);
    ft_printf("%S\n", L"ݗݜशব");
    ft_printf("%s%s\n", "test", "test");
    ft_printf("%s%s%s\n", "test", "test", "test");
    ft_printf("%C\n", 15000);
}
//    while (1);
//    return (0);

    return(0);
}