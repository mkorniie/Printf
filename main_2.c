#include <stdio.h>
#include "header.h"
int		ft_printf(const char * restrict format, ...);

int main(void)
{
	int i;

	printf("%p\n", &i);
	ft_printf("%p\n", &i);
	// ft_printf("%010s is a string\n", "this");
	// printf("%010s is a string\n", "this");
	// ft_printf("% \n");
	// ft_printf("% h\n");
	// ft_printf("% hZ\n");
	// ft_printf("% hZ%\n");
// ft_printf("%\n");
// // printf("%\n");
// while(1);

	// ft_printf("%.2c\n", NULL);
  // 1. (    0) --><--
  // 2. (    1) -->^@<--

// # 0079 (char)
  // ft_printf("@moulitest: %c\n", 0);
//   // 1. (   12) -->@moulitest: <--
//   // 2. (   13) -->@moulitest: ^@<--

// // # 0080 (char)
//   ft_printf("%2c\n", 0);
//   // 1. (    2) -->  <--
//   // 2. (    2) --> ^@<--

// // # 0081 (char)
//   ft_printf("null %c and text\n", 0);
//   // 1. (   14) -->null  and text<--
//   // 2. (   15) -->null ^@ and text<--

// // # 0082 (char)
//   ft_printf("% c\n", 0);
  // 1. (    0) --><--
  // 2. (    1) -->^@<--

	// ft_printf("My:%hU", 4294967296);
	// printf("No:%hU", 4294967296);

	// ft_printf("My:@moulitest: %.10d\n", -42);
	// printf("No:@moulitest: %.10d\n", -42);
	// ft_printf("My:%03.2d\n", -1);
	// printf("No:%03.2d\n", -1);

	// 	ft_printf("My:%-+10.5d>\n", 4242);
	// printf("No:%-+10.5d>\n", 4242);
	// ft_printf("My:%-503d alibaba\n", 42);
	// printf("No:%-503d alibaba\n", 42);
	// ft_printf("My:%#8x\n", 42);
	// printf("No:%#8x\n", 42);
	// ft_printf("My:%#6o\n", 2500);
	// printf("No:%#6o\n", 2500);
	// ft_printf("My:%-+10.5d\n", 4242);
	// printf("No:%-+10.5d\n", 4242);

	// ft_printf("My:%#x\n", 42);
	// printf("No:%#x\n", 42);
	// ft_printf("My:%#llx\n", 9223372036854775807);
	// printf("No:%#llx\n", 9223372036854775807);
	// ft_printf("My:%#X\n", 42);
	// printf("No:%#X\n", 42);
	// ft_printf("My:%#8x\n", 42);
	// printf("No:%#8x\n", 42);
	return(0);
}