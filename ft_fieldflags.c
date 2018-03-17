/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fieldflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:31:32 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:31:34 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_presicion(char *res, int pres, char x)
{
	int len;
	char *temp;
	int	 sign;

	if (res == NULL || pres == -1)
		return (res);
	sign = (res[0] == '-' ? 1 : 0);
	len = ft_strlen(res) - sign;
	if (ft_strchr("dioOuxXp", x) != NULL)
	{
		if (x == 'p')
			res = ft_strdup(res + 2);
		if (x == 'p' && pres == 2)
			return (ft_strdup("0x"));
		if (pres == 0 && res[0] == '0')
			return(ft_strdup(""));
		if (pres > len)
		{
			temp = (sign == 1? res + 1 : res);
			while((--pres - len + 1) > 0)
				temp = ft_strjoin("0", temp);
			if (sign == 1)
				res = ft_strjoin(ft_chartostr(res[0]), temp);
			else
				res = temp;
		}
	}
	else if (x == 's' || x == 'g' || x == 'G')
		if (pres < len)
		{
			temp = res;
			res = ft_strndup(res, pres);
		}
	if (x == 'S')
	{
		if (pres < len)
		{
			int i;
			int sum;
			i = 0;
			sum = 0;
			while (sum <= pres)
			{
				sum += UNISTRINGS[CURR][i];
				i++;
			}
			sum -= UNISTRINGS[CURR][i - 1];
			res = ft_strndup(res, sum);
		}
		CURR++;
	}
	if (x == 'p')
		res = ft_strjoinfree("0x", res, 2);
	return (res);
}

char	*ft_Fwidth(char *res, int width, int *flg)
{
	char *temp;
	size_t len;

	if (res == NULL || width == -1)
		return (res);
	if (flg[4] == 1)
		return (res);
	len = ft_strlen(res);
	if ((unsigned long)width > len)
		len = width - len + 1;
	else
		return (res);
	while (--len > 0)
	{
		temp = res;
		temp = ft_strjoin(" ", temp);
		res = temp;
	}
	return(res);
}

char	**ft_fieldflags(char **res, char **flags)
{
	int *flg;
	int i;
	int x;
	int *wp;
	int len;

	i = -1;
	while (++i < N_OF_F)
		if (flags[i] == NULL)
			res[i] = NULL;
		else
		{
			len = ft_strlen(flags[i]);
			flg = ft_findflag(flags[i]);
			wp = ft_widthPres(flags[i], flg[0]);
			wp[2] = ft_changewidth(flg, res[i], flags[i][len - 1]);
			x = -1;
			res[i] = ft_presicion(res[i], wp[1], flags[i][len - 1]);
			while (++x < 5)
				if (flg[x] != -1)
					res[i] = ft_flags[x](res[i], wp, flags[i][len - 1]);
			res[i] = ft_Fwidth(res[i], wp[0], flg);
		}
//	free(flg);
//    free(wp);
	return (res);
}
