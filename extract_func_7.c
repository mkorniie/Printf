/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:29:57 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:02 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// #include <stdio.h>

char	*ft_lxcnv(va_list ap)
{
	// ft_putstr("ft_lxcnv\n");
	char			*res;
	unsigned long	temp;

	temp = va_arg(ap, long);
	// printf("ft_lxcnv: temp is %lu\n", temp);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	// ft_putstr("ft_lxcnv: res is ");
	// ft_putstr(res);
	// ft_putstr("\n");
	return (res);
}

char	*ft_lxccnv(va_list ap)
{
	char			*res;
	unsigned long	temp;

	temp = va_arg(ap, long);
	res = ft_ubase(temp, 16, "0123456789ABCDEF");
	return (res);
}
