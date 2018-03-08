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
// #include <stdio.h>

int ft_inactive(wchar_t src)
{
	int i;
	int count;

	i = -1;
	count = 1;
	count = count << 31;
	while(++i < 32)
	{
		if((src & count) != 0)
			break;
		count = count >> 1;
	}
	return(i);
}

void	ft_addunicode(int active)
{
	int* temp;
	int len;
	int i;

	len = 0;
	i = 0;
	temp = UNISTRINGS[CURR];
	if (UNISTRINGS[CURR] != NULL)
		while (UNISTRINGS[CURR][i])
			i++;
	len += i;
	UNISTRINGS[CURR] = (int*)malloc(sizeof(int*) * (len + 1));
	i = -1;
	if (temp != NULL)
		while (temp[++i])
			UNISTRINGS[CURR][i] = temp[i];
	if (active <= 7)
		UNISTRINGS[CURR][i] = 1;
	else if (active <= 11 && MB_CUR_MAX >= 2)
		UNISTRINGS[CURR][i] = 2;
	else if (active <= 16 && MB_CUR_MAX >= 3)
		UNISTRINGS[CURR][i] = 3;
	else if (active > 16 && MB_CUR_MAX >= 4)
		UNISTRINGS[CURR][i] = 4;
}

char	*ft_unicode(unsigned int src, int flag)
{
	int		active;
	char	*res;
	int		curr;

	active = (8 * 4) - ft_inactive(src);
	if (active <= 7)
	{
		res = (char*)malloc(sizeof(char) * 2);
		res[1] = '\0';
		res[0] = (char)src;
	}
	else if (active <= 11 && MB_CUR_MAX >= 2)
	{
		res = (char*)malloc(sizeof(char) * 3);
		res[2] = '\0';
		res[0] = (6 << 5) + (src >> 6);
		res[1] = (2 << 6) + ((src << 26) >> 26);
	}
	else if (active <= 16 && MB_CUR_MAX >= 3)
	{
		res = (char*)malloc(sizeof(char) * 4);
		res[3] = '\0';
		res[0] = (14 << 4) + (src >> 12);
		res[1] = (2 << 6) + (((src >> 6) << 26) >> 26);
		res[2] = (2 << 6) + ((src << 26) >> 26);
	}
	else if (active > 16 && MB_CUR_MAX >= 4)
	{
		res = (char*)malloc(sizeof(char) * 5);
		res[4] = '\0';
		res[0] = (30 << 3) + (src >> 18);
		res[1] = (2 << 6) + (((src >> 12) << 26) >> 26);
		res[2] = (2 << 6) + (((src >> 6) << 26) >> 26);
		res[3] = (2 << 6) + ((src << 26) >> 26);
	}
	else{
		ERROR = 1;
		return (NULL);
	}
	if (flag == 1)
		ft_addunicode(active);
	return(res);
}
