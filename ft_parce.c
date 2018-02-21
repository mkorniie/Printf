/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:32:50 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:32:52 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <stdio.h>

static	int	ft_n_of_f(const char * restrict s, char *c)
{
	// printf("ft_n_of_f\n");
	char *temp;
	int n_of_flags;

	n_of_flags = 0;
	temp = (char *)s;
	while((temp = ft_strstr(temp, c)) != NULL)
	{
		n_of_flags++;
		// if(temp[1] == *c)
		// 	temp = temp + 2;
		// else
		temp = temp + 1;
	}
	// printf("NUMBER OF WORDS is: %d\n", n_of_flags);
	return (n_of_flags);
}

char *ft_writeflag(const char * restrict s, int lim, char *c)
{
	// printf("ft_writeflag\n");
	char *flag;
	char *temp;
	int i;

	i = -1;
	temp = (char *)s;
	while(++i < lim)
	{
		temp = ft_strstr(temp, c);
		// printf("TEMP is %s\n", temp);
		// printf("ft_strlen(temp) = %zu\n", ft_strlen(temp));
		// if((ft_strlen(temp) > 1) && (temp[1] == *c))
		// {
		// 	printf("HERE!1\n");
		// 	temp = temp + 2;
		// }
		// else
		// {
			// printf("HERE!2\n");
		temp = temp + 1;
		// }
	}
	temp = ft_strstr(temp, c);
	// printf("ft_writeflag: TEMP fin is %s\n", temp);
	flag = ft_validflag(temp);
	// printf("The Flag[%d] is \'%s\'\n", lim, flag);
	return (flag);
}

char **ft_flag_array(const char * restrict s, char *c, int *flag)
{
	// printf("ft_flag_array\n");
	int		i;
	char 	**arr;
	size_t	last_char;

	N_OF_F = ft_n_of_f(s, c);
	if (N_OF_F == 0)
	{
		*flag = 0;
		return (NULL);
	}
	if ((arr = (char**)malloc(sizeof(char*) * (N_OF_F + 1))) == NULL)
		return (NULL);
	arr[N_OF_F] = NULL;
	i = -1;
	while(++i < N_OF_F)
	{
		arr[i] = ft_writeflag(s, i, c);
		if (arr[i] != NULL)
		{
			last_char = ft_strlen(arr[i]) - 1;
			if (arr[i][last_char] == '%')
			{
				// printf("arr[%i] is NULL\n", i + 1);
				arr[++i] = NULL;
			}
		}
		// printf("NOW arr[%d] is %s\n", i, arr[i]);
	}
	// printf("return arr\n");
	return (arr);
}

int	ft_parce(const char * restrict s, char *c, char ***flags)
{
	int flag;

	if (s == NULL || flags == NULL)
		return (-1);
	flag = 1;
	if ((*flags = ft_flag_array(s, c, &flag)) == NULL)
	{
		if (flag == 0)
			return(-3);
		return (-1);
	}
	return(0);
}
