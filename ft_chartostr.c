/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:38:02 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/20 19:38:05 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_chartostr(char c)
{
    char *res;

    res = (char*)malloc(sizeof(char) * 2);
    res[0] = c;
    res[1] = '\0';
    return (res);
}
