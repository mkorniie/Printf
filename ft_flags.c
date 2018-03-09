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
#include "stdio.h"

char *ft_zero(char	*res, int wp[3], char x)
{
	char	*temp;
	size_t	len;
	int		f;

	// printf("ZERO CONV: res is [%s], wp is : [%d] [%d], x is %c\n", res, wp[0], wp[1], x);
	if (res == NULL || wp[0] == -1)
		return (res);
	if (wp[1] != -1)
		if (ft_strchr("diouxX", x) != NULL)
			return (res);
	len = ft_strlen(res);
	// printf("LEN is %lu\n", len);
	if ((unsigned long)wp[0] > len)
		len = wp[0] - wp[2] - len + 1;
	else
		return (res);
	if (x == 'p')
		res = ft_strdup(res + 2);
	f = (res[0] == '-' ? 1 : 0);
	wp[2] = (len - 1) * (-1);
	if (f == 1)
		res = ft_strdup(res + 1);
	while (--len > 0)
	{
		// printf("Here!\n");
		temp = res;
		temp = ft_strjoin("0", temp);
		// free(res);
		res = temp;
	}
	if (f == 1)
		res =  ft_strjoin("-", res);
	if (x == 'p')
		res = ft_strjoin("0x", res);
	return(res);
}

char *ft_hash(char	*res, int wp[3], char x)
{
	char	*temp;
	int		adj;

// printf("ft_hash: we get %s\n", res);
	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	temp = res;
	if (x == 'o' || x == 'O')
	{
		// printf("At least we went here\n");
		if (ft_strlen(res) == 0 || res[adj] != '0')
		{
			temp = ft_strjoin("0", res);
			// free(res);
		}
	}
	else if (x == 'x' || x == 'X')
	{
		if (ft_strlen(res) == 0)
			return (res);
		if (ft_atoi(res) != 0)
		{
			temp = ft_strjoin((x == 'x' ? "0x" : "0X"), res);
			// free(res);
		}
	}
	// printf("ft_hash: we return %s\n", temp);
	return(temp);
}

char *ft_space(char	*res, int wp[3], char x)
{
	char *temp;
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (res == NULL || ft_strchr("aAdeEfFgGi", x) == NULL)
	{
			// printf("SPACE: RES is returned!\n");
			return (res);
	}
	if (res[0] != '-')
	{
		temp = res;
		res = ft_strjoin(" ", res);
		// free(temp);
	}
	return(res);
}

char *ft_plus(char	*res, int wp[3], char x)
{
	char *temp;
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (res == NULL || ft_strchr("aAdeEfFgGi", x) == NULL)
	{
			// printf("PLUS: RES is returned!\n");
			return (res);
	}
	if (res[0] != '-')
	{
		temp = res;
		res = ft_strjoin("+", res);
		// free(temp);
	}
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
