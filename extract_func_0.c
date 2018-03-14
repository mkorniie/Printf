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
	if (ft_strlen(res) == 0)
	{
		res = (char*)malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	return (ft_strdup(res));
}

void	ft_addustring(void)
{
	int** temp;
	int len;
	int i;

	// ft_putstr("HERE! ENTERS ft_addustring\n");
	len = 0;
	i = 0;
	temp = UNISTRINGS;
	if (UNISTRINGS != NULL)
	{
		// ft_putstr("HERE! UNISTRINGS != NULL\n");
		while (UNISTRINGS[i])
			i++;
	}
	len += i;
	// ft_putstr("HERE! Before malloc\n");
	UNISTRINGS = (int**)malloc(sizeof(int*) * (len + 1));
//	len = i;
	i = -1;
	if (temp != NULL)
		while (temp[++i])
			UNISTRINGS[i] = temp[i];
	UNISTRINGS[CURR] = NULL;
}

char	*ft_sccnv(va_list ap)
{
	char	*res[2];
	wchar_t	*temp;
	int		i;

	if ((temp = va_arg(ap, wchar_t*)) == NULL)
		return (ft_strdup("(null)"));
	if (CURR != 0)
		CURR++;
	ft_addustring();
	// ft_putstr("HERE! ft_sccnv after ft_addustring\n");
	if (ft_strlen(temp) == 0)
		return (ft_strdup(""));
	res[0] = ft_unicode(temp[0], 1);
	if (ERROR == 1)
		return(NULL);
	i = 0;
	// printf("ft_sccnv!!!!!\n");
	while (temp[++i] != '\0')
	{
		res[1] = res[0];
		// printf("%c", res[1]);
		res[0] = ft_strjoin(res[0], ft_unicode(temp[i], 1));
		free(res[1]);
	}
	i = 0;
	// ft_putstr("HERE! ft_sccnv after UNICODING\n");
	// while (UNISTRINGS[CURR][i])
	// {
	// 	printf("%d", UNISTRINGS[CURR][i]);
	// 	i++;
	// }
	// printf("\n");
	return (res[0]);
}

char	*ft_pcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	// printf("temp is [%zu]\n", temp);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	// printf("res is [%s]\n", res);
	res = ft_strjoin("0x", res);
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
