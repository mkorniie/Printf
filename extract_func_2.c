/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:26:17 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:26:22 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_xcnv(va_list ap)
{
	// ft_putstr("ft_xcnv\n");
	char			*res;
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	return (res);
}

char	*ft_xccnv(va_list ap)
{
	// ft_putstr("ft_xccnv\n");
	char			*res;
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	res = ft_ubase(temp, 16, "0123456789ABCDEF");
	return (res);
}

char	*ft_ccnv(va_list ap)
{
	char *res;
	char temp;

	temp = va_arg(ap, int);
	if (temp == 0)
		return (res = ft_strdup("zero"));
	else
		res = ft_chartostr(temp);
	return (res);
}

char	*ft_cccnv(va_list ap)
{
	char	*res;
	wchar_t	temp;

	temp = va_arg(ap, wchar_t);
	if (temp == 0)
		return (res = ft_strdup("zero"));
	res = ft_unicode(temp);
	return (res);
}

char	*ft_ecnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}
