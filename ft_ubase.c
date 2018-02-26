/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ubase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:33:52 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:33:54 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <stdio.h>

uintmax_t ft_powlen(uintmax_t src, uintmax_t len)
{
	uintmax_t i;

	i = 0;
	if (src == 0)
		return (1);
	if (src >= 10000000000000000000LU)
	{
		// printf("HERE!\n");
		return (ft_powlen(src / len, len) + 1);
	}
	while((src / ft_powl(len, i)) > (len - 1))
	{
		// printf("ft_powl(%lu, %lu) is %lu\n", len, i, ft_powl(len, i));
		// printf("SRC is %lu\n", src);
		i++;
		// printf("Magic:%lu, len = %lu  i =%lu \n", ft_powl(len, i), len, i);
	}
	// printf("The length is %lu\n", i);
	return (i + 1);
}

char *ft_ubase(uintmax_t src, uintmax_t len, const char *pattern)
{
	char *res;
	uintmax_t plen;
	uintmax_t size;
	uintmax_t i;
	uintmax_t temp;

	// printf("ft_ubase: src is [%zu]\n", src);
	// printf("Input value is %lu\n", src);
	plen = ft_strlen(pattern);
	// printf("ft_ubase: 1 [%zu]\n", src);
	if(plen != len)
		return (NULL);
	// printf("ft_ubase: 2 [%zu]\n", src);
	i = -1;
	size = ft_powlen(src, len);
	// printf("ft_ubase: 3 [%zu]\n", src);
	// printf("U-la-la! s is %lu\n", size);
	if(!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return(NULL);
	res[size] = '\0';
	// printf("ft_ubase: 4 [%zu]\n", src);
	while (++i < size)
	{
		// printf("ft_ubase: 5\n");
		temp = src / ft_powl(len, size - i - 1);
		// printf("src is |%lu|\n ft_powl(|%lu|, |%lu|\n temp is |%lu|\n)", src, len, size - i - 1, temp);
		// printf("ft_ubase: 6\n");
		res[i] = pattern[temp];
		// printf("Index is pattern|%lu| = %c\n", temp, pattern[temp]);
		// printf("ft_ubase: 7\n");
		src -= temp * ft_powl(len, size - i - 1);
		// printf("ft_ubase: 8\n");
	}
	// printf("ft_ubase: 9\n");
	// printf("res is [%s]\n", res);
	return(res);
}

// int main(void)
// {
// 	int i;

// 	i = -1;
// 	while(++i < 128)
// 		printf("|%s| - [%c]\n", ft_ubase(i, 16, "0123456789abcdef"), i);
// 	return 0;
// }
