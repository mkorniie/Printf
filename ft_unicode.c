/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:19 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:34:24 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_inactive(wchar_t src)
{
	int i;
	int count;

	i = -1;
	count = 1;
	count = count << 31;
	while (++i < 32)
	{
		if ((src & count) != 0)
			break ;
		count = count >> 1;
	}
	return (i);
}

int		ft_find_n_by_active(int active)
{
	if (active <= 7)
		return (1);
	else if (active <= 11 && MB_CUR_MAX >= 2)
		return (2);
	else if (active <= 16 && MB_CUR_MAX >= 3)
		return (3);
	else if (active > 16 && MB_CUR_MAX >= 4)
		return (4);
}

void	ft_addunicode(int active)
{
	int		*temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	temp = UNISTRINGS[CURR];
	if (UNISTRINGS[CURR] != NULL)
		while (UNISTRINGS[CURR][i])
			i++;
	len += i;
	UNISTRINGS[CURR] = (int*)malloc(sizeof(int) * (len + 2));
	UNISTRINGS[CURR][len + 1] = 0;
	i = 0;
	if (temp != NULL)
		while (temp[i])
		{
			UNISTRINGS[CURR][i] = temp[i];
			i++;
		}
	UNISTRINGS[CURR][i] = ft_find_n_by_active(active);
	free(temp);
}

void	ft_mask(int active, char **res, unsigned int src)
{
//    setlocale();
	if (active <= 7)
		(*res)[0] = (char)src;
	else if (active <= 11 && MB_CUR_MAX >= 2)
	{
		(*res)[0] = (6 << 5) + (src >> 6);
		(*res)[1] = (2 << 6) + ((src << 26) >> 26);
	}
	else if (active <= 16 && MB_CUR_MAX >= 3)
	{
		(*res)[0] = (14 << 4) + (src >> 12);
		(*res)[1] = (2 << 6) + (((src >> 6) << 26) >> 26);
		(*res)[2] = (2 << 6) + ((src << 26) >> 26);
	}
	else if (active > 16 && MB_CUR_MAX >= 4)
	{
		(*res)[0] = (30 << 3) + (src >> 18);
		(*res)[1] = (2 << 6) + (((src >> 12) << 26) >> 26);
		(*res)[2] = (2 << 6) + (((src >> 6) << 26) >> 26);
		(*res)[3] = (2 << 6) + ((src << 26) >> 26);
	}
	else
	{
        free(*res);
        (*res) = (char*)malloc(sizeof(char) * (2));
		 (*res)[0] = (char)src;
		 (*res)[1] = '\0';
//		ERROR = 1;
//		free(*res);
//		(*res) = NULL;
	}
}

char	*ft_unicode(unsigned int src, int flag)
{
	int		active;
	char	*res;

	active = (8 * 4) - ft_inactive(src);
	res = (char*)malloc(sizeof(char) * (ft_find_n_by_active(active) + 1));
	res[ft_find_n_by_active(active)] = '\0';
	ft_mask(active, &res, src);
	if (flag == 1 && (ERROR == 0))
		ft_addunicode(active);
	return (res);
}
