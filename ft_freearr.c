/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:46:16 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/18 15:46:22 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_freeintarr(int **split, int len)
{
	int i;

	if (split == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_freestrarr(char **split)
{
	int i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
