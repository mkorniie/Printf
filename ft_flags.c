/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:32:10 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:32:14 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *ft_zero(char	*res, int wp[3], char x)
{
	char	*temp;
	size_t	len;
	int		f;

	if (res == NULL || wp[0] == -1)
		return (res);
	if (wp[1] != -1)
		if (ft_strchr("diouxX", x) != NULL)
			return (res);
	len = ft_strlen(res);
	if ((unsigned long)wp[0] > len)
		len = wp[0] - wp[2] - len + 1;
	else
		return (res);
	if (x == 'p')
    {
        temp = res;
        res = ft_strdup(res + 2);
        free(temp);
    }
	f = (res[0] == '-' ? 1 : 0);
	wp[2] = (len - 1) * (-1);
	if (f == 1)
    {
        temp = res;
        res = ft_strdup(res + 1);
        free(temp);
    }
	while (--len > 0)
		res = ft_strjoinfree("0", res, 2);
	if (f == 1)
		res =  ft_strjoinfree("-", res, 2);
	if (x == 'p')
		res = ft_strjoinfree("0x", res, 2);
	return(res);
}

char *ft_hash(char	*res, int wp[3], char x)
{
	char	*temp;
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	temp = res;
	if (x == 'o' || x == 'O')
	{
		if (ft_strlen(res) == 0 || res[adj] != '0')
		{
			temp = ft_strjoin("0", res);
		}
	}
	else if (x == 'x' || x == 'X')
	{
		if (ft_strlen(res) == 0)
			return (res);
		if (ft_atoi(res) != 0)
		{
			temp = ft_strjoin((x == 'x' ? "0x" : "0X"), res);
		}
	}
	return(temp);
}

char *ft_space(char	*res, int wp[3], char x)
{
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (res == NULL || ft_strchr("aAdeEfFgGi", x) == NULL)
			return (res);
	if (res[0] != '-')
		res = ft_strjoinfree(" ", res, 2);
	return(res);
}

char *ft_plus(char	*res, int wp[3], char x)
{
	char *temp;
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (res == NULL || ft_strchr("aAdeEfFgGi", x) == NULL)
			return (res);
	if (res[0] != '-')
		res = ft_strjoinfree("+", res, 2);
	return(res);
}

char *ft_leftadj(char	*res, int wp[3], char x)
{
	char *temp;
	size_t len;

	// printf("LEFTADJ CONV: res is [%s], wp is : [%d] [%d], x is %c\n", res, wp[0], wp[1], x);
	if (res == NULL || x == 'n' || wp[0] == -1)
	{
			// printf("LEFT ADJ: RES is returned!\n");
			return (res);
	}
	len = ft_strlen(res);
	// printf("LEFT ADJ: LEN is %lu\n", len);
	// printf("LEFT ADJ: wp[0] is %d\n", wp[0]);
	if ((unsigned long)wp[0] > len)
		len = wp[0] - len + 1;
	else
		return (res);
	while (--len > 0)
	{
		// printf("STUCK HERE!\n");
		temp = res;
		temp = ft_strjoin(temp, " ");
		// free(res);
		res = temp;
	}
	// wp[0]++;
	// x++;
	// temp = ft_strjoin("[- conv]", res);
	// free(res);
	return(temp);
}
