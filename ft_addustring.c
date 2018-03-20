/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addustring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:37:40 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/20 19:37:44 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_addustring(void)
{
    int** temp;
    int len;
    int i;

    len = 0;
    i = 0;
    temp = UNISTRINGS;
    if (UNISTRINGS != NULL)
        while (UNISTRINGS[i])
            i++;
    len += i;
    UNISTRINGS = (int**)malloc(sizeof(int*) * (len + 2));
    UNISTRINGS[len + 1] = 0;
    i = -1;
    if (temp != NULL)
        while (temp[++i])
            UNISTRINGS[i] = temp[i];
    ft_freeintarr(temp, 0);
    UNISTRINGS[CURR] = NULL;
}
