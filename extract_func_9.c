/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:30:29 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:31 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_dssize_tcnv(va_list ap)
{
	char	*res;
	ssize_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_litoa(temp);
	return (res);
}

char	*ft_osize_tcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_ubase(temp, 8, "01234567");
	return (res);
}

char	*ft_usize_tcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_ulitoa(temp);
	return (res);
}

char	*ft_xsize_tcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	return (res);
}

char	*ft_xcsize_tcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_ubase(temp, 16, "0123456789ABCDEF");
	return (res);
}
