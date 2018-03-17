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

    size2 = ft_printf("2a%Sb%sc%S\n", L"我", "42", L"猫");

//    while (1)
//    {
//
//    }
//    printf("PRINTF resturns [%d] MY PRINTF resturns [%d]\n", size1, size2);
	return(0);
}