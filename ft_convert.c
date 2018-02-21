/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:30:55 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:56 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// #include <stdio.h>

int		ft_getcvsindex(int mod, char *flag)
{
	int		cvs;
	size_t	len;

// ft_putstr("ft_getcvsindex\n");
	len = ft_strlen(flag);
	cvs = ft_isspecifier(flag[len - 1]);
	// ft_putstr("ft_getcvsindex: CVS is ");
	// ft_putstr(ft_itoa(cvs));
	if (cvs == 7 || cvs == 9)
		return ((cvs == 7 ? 7 : 9));
	if (mod == 0 || mod == 1)
	{
		// ft_putstr("ft_getcvsindex: mod == 1 || mod == 2\n");
		return (ft_modifpart1(mod, cvs));
	}
	if (mod >= 2 && mod <= 5)
	{
		// ft_putstr("ft_getcvsindex:mod >= 2 && mod <= 5\n");
		return (ft_modifpart2(mod, cvs));
	}
	// ft_putstr("ft_getcvsindex: returns -1\n");
	return (-1);
}

char	*ft_extractor(va_list ap, int z, char *flag)
{
	int x;

// ft_putstr("ft_extractor\n");
	if ((x = ft_isMod(flag)) == -1)
	{
		// ft_putstr("ft_extractor: (x = ft_isMod(flag)) == -1!!! \n");
		return (ft_cvs[z](ap));
	}
	else
	{
		// ft_putstr("ft_extractor: go to ft_getcvsindex\n");
		z = ft_getcvsindex(x, flag);
		// ft_putstr("ft_extractor: the ft_getcvsindex is ");
		// ft_putstr(ft_itoa(z));
		// ft_putstr("\n");

	}
	// ft_putstr("ft_extractor: succesfully returns a value\n");
	return (ft_cvs[z](ap));
}

char	**ft_get(va_list ap, char **flags, char **arr)
{
	// ft_putstr("ft_get\n");
	int i;
	int z;
	int strlen;

	i = -1;
	while (++i < N_OF_F)
	{
		z = -1;
		// ft_putstr("ft_get: 1\n");
		if (flags[i] == NULL)
			arr[i] = NULL;
		else
		{
			strlen = ft_strlen(flags[i]);
			// printf("ft_get: 2 ft_strlen of (flags[%d]) [%s]   is   %d\n", i, flags[i], strlen);
			if (flags[i][strlen - 1] == '%')
			{
				// ft_putstr("ft_get: arr[i] is %!\n");
				arr[i] = ft_strdup("%");
			}
			else
			{
				// ft_putstr("ft_get: 3 else!\n");
				while (convs[++z])
					if (convs[z][0] == flags[i][strlen - 1])
					{
						// printf("ft_get: conversion found! the conv is %s\n", convs[z]);
						arr[i] = ft_extractor(ap, z, flags[i]);
						if (flags[i][strlen - 1] == 'c' && (ft_strcmp(arr[i], "zero") == 0))
						{
							arr[i] = ft_strdup("z");
							flags[i] = ft_strjoin(flags[i], "!");
						}
						// printf("ft_get: now arr[%d] is %s\n", i, arr[i]);
					}
			}
		}
	}
	// ft_putstr("ft_get: succesfully returns an array\n");
	return (arr);
}

char	**ft_convert(va_list ap, char **flags)
{
	char	**res;
	if (!(res = (char**)malloc(sizeof(char*) * (N_OF_F + 1))))
		return (NULL);
	res[N_OF_F] = NULL;
	res = ft_get(ap, flags, res);
	res = ft_fieldflags(res, flags);
	return (res);
}
