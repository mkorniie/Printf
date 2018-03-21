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

    ft_printf("Kashim a %D histoires à raconter\n", 1001);
//    ft_printf("%ld\n", 1);
//    ft_printf("%b\n", 1);
//    ft_printf("\n");
//    ft_printf("%%\n");
//    ft_printf("%d\n", 42);
//    ft_printf("%d%d\n", 42, 41);
//    ft_printf("%d%d%d\n", 42, 43, 44);
//    ft_printf("%ld\n", 2147483647);
//    ft_printf("%lld\n", 9223372036854775807);
//    ft_printf("%x\n", 505);
//    ft_printf("%X\n", 505);
//    ft_printf("%p\n", &ft_printf);
//    ft_printf("%20.15d\n", 54321);
//    ft_printf("%-10d\n", 3);
//    ft_printf("% d\n", 3);
//    ft_printf("%+d\n", 3);
//    ft_printf("%010d\n", 1);
//    ft_printf("%hhd\n", 0);
//    ft_printf("%jd\n", 9223372036854775807);
//    ft_printf("%zd\n", 4294967295);
//    ft_printf("%\n");
//    ft_printf("%U\n", 4294967295);
//    ft_printf("%u\n", 4294967295);
//    ft_printf("%o\n", 40);
//    ft_printf("%%#08x\n", 42);
//    ft_printf("%x\n", 1000);
//    ft_printf("%#X\n", 1000);
//    ft_printf("%s\n", NULL);
//    ft_printf("%S\n", L"ݗݜशব");
//    ft_printf("%s%s\n", "test", "test");
//    ft_printf("%s%s%s\n", "test", "test", "test");
//    ft_printf("%C\n", 15000);
//    while (1);
    return (0);

    setlocale(LC_ALL, "");

//     size1 = printf("1{%10R}\n");
     size2 = ft_printf("2{%10R}\n");
//     printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

//     size1 = printf("1{%10R}\n");
     size2 = ft_printf("2{%10R}\n");
//     printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
//     size1 = printf("1{%-15Z}\n", 123);
     size2 = ft_printf("2{%-15Z}\n", 123);
//     printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
//     size1 = printf("1{%05.Z}\n", 0);
     size2 = ft_printf("2{%05.Z}\n", 0);
//     printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
//    size1 = printf("1{%#.5x}\n", 1);
    size2 = ft_printf("2{%#.5x}\n", 1);
//    printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);



    // size1 = printf("1%4.1S\n", L"Jambon");
     size2 = ft_printf("2%4.1S\n", L"Jambon");
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);


    // size1 = printf("1%.6S\n", L"我是一只猫。");
     size2 = ft_printf("2%.6S\n", L"我是一只猫。");
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1%.5p\n", 0);
     size2 = ft_printf("2%.5p\n", 0);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1%.0p, %.p\n", 0, 0);
     size2 = ft_printf("2%.0p, %.p\n", 0, 0);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1{%030S}\n", L"我是一只猫。");
     size2 = ft_printf("2{%030S}\n", L"我是一只猫。");
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1{%03c}\n", 0);
     size2 = ft_printf("2{%03c}\n", 0);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1%lp\n", 42);
     size2 = ft_printf("2%lp\n", 42);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1%lD, %lD\n", 0, USHRT_MAX);
     size2 = ft_printf("2%lD, %lD\n", 0, USHRT_MAX);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);


    // size1 = printf("1%lc, %lc\n", L'暖', L'ح');
     size2 = ft_printf("2%lc, %lc\n", L'暖', L'ح');
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);


    // size1 = printf("1%lX, %lX\n", 0, ULONG_MAX);
     size2 = ft_printf("2%lX, %lX\n", 0, ULONG_MAX);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);

    // size1 = printf("1%C\n", 0);
     size2 = ft_printf("2%C\n", 0);
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
    // printf("%S\n", NULL);
     ft_printf("%S\n", NULL);

//     size1 = printf("1%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n",
    // L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
    // L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
     size2 = ft_printf("2%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n",
     L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
     L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
    // printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
    // printf("%p\n", &i);
    int i;

    i = 5;
    ft_printf("%p\n", &i);
     ft_printf("%010s is a string\n", "this");
    // printf("%010s is a string\n", "this");
     ft_printf("% \n");
     ft_printf("% h\n");
     ft_printf("% hZ\n");
     ft_printf("% hZ%\n");
 ft_printf("%\n");
 // printf("%\n");
// while(1);

     ft_printf("%.2c\n", NULL);
    // 1. (    0) --><--
    // 2. (    1) -->^@<--

// # 0079 (char)
     ft_printf("@moulitest: %c\n", 0);
//   // 1. (   12) -->@moulitest: <--
//   // 2. (   13) -->@moulitest: ^@<--

// // # 0080 (char)
   ft_printf("%2c\n", 0);
//   // 1. (    2) -->  <--
//   // 2. (    2) --> ^@<--

// // # 0081 (char)
   ft_printf("null %c and text\n", 0);
//   // 1. (   14) -->null  and text<--
//   // 2. (   15) -->null ^@ and text<--

// // # 0082 (char)
   ft_printf("% c\n", 0);
    // 1. (    0) --><--
    // 2. (    1) -->^@<--

     ft_printf("My:%hU", 4294967296);
    // printf("No:%hU", 4294967296);

     ft_printf("My:@moulitest: %.10d\n", -42);
    // printf("No:@moulitest: %.10d\n", -42);
     ft_printf("My:%03.2d\n", -1);
    // printf("No:%03.2d\n", -1);

     	ft_printf("My:%-+10.5d>\n", 4242);
    // printf("No:%-+10.5d>\n", 4242);
     ft_printf("My:%-503d alibaba\n", 42);
    // printf("No:%-503d alibaba\n", 42);
     ft_printf("My:%#8x\n", 42);
    // printf("No:%#8x\n", 42);
     ft_printf("My:%#6o\n", 2500);
    // printf("No:%#6o\n", 2500);
     ft_printf("My:%-+10.5d\n", 4242);
    // printf("No:%-+10.5d\n", 4242);

     ft_printf("My:%#x\n", 42);
    // printf("No:%#x\n", 42);
     ft_printf("My:%#llx\n", 9223372036854775807);
    // printf("No:%#llx\n", 9223372036854775807);
     ft_printf("My:%#X\n", 42);
    // printf("No:%#X\n", 42);
     ft_printf("My:%#8x\n", 42);
    // printf("No:%#8x\n", 42);
    return(0);
}