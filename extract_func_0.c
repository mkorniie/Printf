/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:03:09 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:19:53 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_scnv(va_list ap)
{
	char *res;

	res = va_arg(ap, char*);
	if (res == NULL)
		res = ft_strdup("(null)");
	return (ft_strdup(res));
}

char	*ft_sccnv(va_list ap)
{
	char	*res[2];
	wchar_t	*temp;
	int		i;

	if ((temp = va_arg(ap, wchar_t*)) == NULL)
		return (NULL);
	res[0] = ft_unicode(temp[0]);
	i = 0;
	while (temp[++i] != '\0')
	{
		res[1] = res[0];
		res[0] = ft_strjoin(res[0], ft_unicode(temp[i]));
		free(res[1]);
	}
	return (res[0]);
}

char	*ft_pcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	res = ft_strcat("0x", res);
	return (res);
}

char	*ft_dcnv(va_list ap)
{
	char	*res;
	int		temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}

char	*ft_dccnv(va_list ap)
{
	char *res;
	long temp;

	temp = va_arg(ap, long);
	res = ft_litoa(temp);
	return (res);
}
