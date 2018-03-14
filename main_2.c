#include <stdio.h>
#include "header.h"
int		ft_printf(const char * restrict format, ...);
#include <locale.h>
#include <limits.h>

int main(void)
{
	int i;
	int size1;
	int size2;

	setlocale(LC_ALL, "");

//    size1 = printf("1{%05.Z}\n", 0);

    size2 = ft_printf("2{%S}\n", L"");

//    while (1)
//    {
//
//    }
//    printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
	return(0);
}