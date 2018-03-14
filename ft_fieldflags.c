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
// #include <stdio.h>

int ft_changewidth(int *flg, char	*res, char x)
{
	int adj;

	adj = 0;
	if (flg[1] != -1)
	{
		if (x == 'o')
		{
			if (res[0] != '0')
				adj++;
		}
		else if (x == 'x' || x == 'X')
			if (res[0] != '0')
				adj += 2;
	}
	if (flg[2] != -1 || flg[3] != -1)
	{
		if (ft_strchr("aAdeEfFgGi", x) != NULL)
			if (res[0] != '-')
				adj++;
	}
	return (adj);
}

int	*ft_widthPres(char *flag, int zeroflag)
{
	int *wp;
	char *temp;
	int	i;
	int last_char;

	i = -1;
	last_char = ft_strlen(flag) - 1;
	wp = (int *)malloc(sizeof(int) * 3);
	wp[0] = -1;
	wp[1] = -1;
	wp[2] = 0;
	if ((temp = ft_strstr(flag, ".")) != NULL)
	{
		if (ft_isdigit(temp[1]))
			wp[1] = ft_atoi(temp + 1);
		else
			wp[1] = 0;
	}
	while (flag[++i] != '.' && flag[i] != '\0')
		if (ft_isdigit(flag[i]))
		{
			if (flag[i] == '0' && zeroflag != -1)
				zeroflag = -1;
			else
				wp[0] = (ft_atoi(flag + i) > wp[0] ? ft_atoi(flag + i) : wp[0]);
		}
	if (flag[last_char] == 'p')
		wp[1] += 2;
	return (wp);
}

int	ft_isflag(char *flag, char x)
{
	char *temp;
	int i;
	int len;

	if ((temp = ft_strchr(flag, x)) == NULL)
		return (-1);
	else
		if (x == '0')
		{
			// printf("ft_isflag: x is 0 and it is present!\n");
			len = ft_strlen(flag) - ft_strlen(temp);
			// printf("ft_isflag: temp is [%s]\n", temp);
			i = -1;
			while (++i < len)
			{
				// printf("I is [%d] and flag[i] is [%c]\n", i, flag[i]);
				if (ft_isdigit(flag[i]) != 0 || flag[i] == '.')
				{
					// printf("%s\n", "Resturns -1!!!");
					return (-1);
				}
			}
		}
		// printf("RETURNS 1! for x [%c]\n", x);
	return (1);
}

int *ft_findflag(char *flag)
{
	int *flgI;
	int i;
	char *flgs;
	char *works[2];
	int x;
	
	flgs = "0# +-"; /*now 02 is 04*/
	works[1] = "oOxXaAeEfFgG";		/* for hash */
	works[0] = "%diouxXaAeEfFgGsc!Sp^";	/* for zero */
	flgI = (int *)malloc(sizeof(int) * 5);
	i = -1;
	while (++i < 5)
	{
		flgI[i] = ft_isflag(flag, flgs[i]); /**/
		// printf("FLAG for [%c] is %d\n", flgs[i], flgI[i]);
	}
	flgI[0] = ((flgI[0] == 1 && flgI[4] == 1) ? -1 : flgI[0]);
	flgI[2] = ((flgI[2] == 1 && flgI[3] == 1) ? -1 : flgI[2]);
	// printf("\nFLAG for [%c] is %d\n", flgs[0], flgI[0]);
	i = -1;
	while (++i < 2)
		if (flgI[i] == 1)
		{
			x = -1;
			flgI[i] = -1;
			while (works[i][++x] != '\0')
				if(flag[ft_strlen(flag) - 1] == works[i][x])
					flgI[i] = 1;
		}
		i = -1;
	// while (++i < 5)
	// {
	// 	printf("FLAG for [%c] is %d\n", flgs[i], flgI[i]);
	// }
	return (flgI);
}

char	*ft_presicion(char *res, int pres, char x)
{
	// ft_putstr("ft_presicion\n");
	int len;
	char *temp;
	int	 sign;
	int ulen;

	// printf("RES is %s\n", res);
	if (res == NULL || pres == -1)
		return (res);
	sign = (res[0] == '-' ? 1 : 0);
	len = ft_strlen(res) - sign;
	if (ft_strchr("dioOuxXp", x) != NULL)
	{
		if (x == 'p')
			res = ft_strdup(res + 2);
		// ft_putstr("ft_presicion: enters if 2 if\n");
		// if (x == 'O' && pres == 0)
		// 	return (ft_strjoin(res[0] == '0'? "" : "0", res));
		if (x == 'p' && pres == 2)
			return (ft_strdup("0x"));
		if (pres == 0 && res[0] == '0')
			return(ft_strdup(""));
		if (pres > len)
		{
			temp = (sign == 1? res + 1 : res);
			while((--pres - len + 1) > 0)
			{
				temp = ft_strjoin("0", temp);
				// free (temp);
			}
			if (sign == 1)
				res = ft_strjoin(ft_chartostr(res[0]), temp);
			else
				res = temp;
		}
	}
	else if (x == 's' || x == 'g' || x == 'G')
	{
		// ft_putstr("ft_presicion: enters if 2 else\n");
		if (pres < len)
		{
			temp = res;
			res = ft_strndup(res, pres);
		}
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
		res = ft_strjoin("0x", res);
	return (res);
}

char	*ft_Fwidth(char *res, int width, int *flg)
{
	char *temp;
	size_t len;

	if (res == NULL || width == -1)
		return (res);
	if (/*flg[1] == 1 ||*/ flg[4] == 1)
	{
		// ft_putstr("ft_Fwidth: wrong flag!\n");
		return (res);
	}
	len = ft_strlen(res);
		// ft_putstr("ft_Fwidth: strlen is ");
		// ft_putstr(ft_itoa(len));
				// ft_putstr("ft_Fwidth: width is ");
		// ft_putstr(ft_itoa(width));
	if ((unsigned long)width > len)
	{
		// ft_putstr("ft_Fwidth: The len is ");
		// ft_putstr(ft_itoa(width - len + 1));
		len = width - len + 1;
	}
	else
	{
		// ft_putstr("ft_Fwidth: width > len!\n");
		return (res);
	}
	while (--len > 0)
	{
		// ft_putstr();
		temp = res;
		temp = ft_strjoin(" ", temp);
		// free(res);
		res = temp;
	}
	return(res);
}

char	**ft_fieldflags(char **res, char **flags)
{
	// ft_putstr("ft_fieldflags\n");
	int *flg;
	int i;
	int x;
	int *wp;
	int len;

	i = -1;
	while (++i < N_OF_F)
	{
		// printf("ft_fieldflags: i is [%d]\n", i);
		if (flags[i] == NULL)
		{
			// ft_putstr("ft_fieldflags: flags[i] is NULL!!!\n");
			res[i] = NULL;
		}
		else
		{
			// ft_putstr("ft_fieldflags: flags[i] != NULL. Goes onward\n");
			len = ft_strlen(flags[i]);
			// ft_putstr("ft_fieldflags: 1\n");
			flg = ft_findflag(flags[i]);
			// ft_putstr("ft_fieldflags: 2\n");
			wp = ft_widthPres(flags[i], flg[0]);
			wp[2] = ft_changewidth(flg, res[i], flags[i][len - 1]);
			// printf("ft_fieldflags: Width is [%d], precision is [%d]\n", wp[0], wp[1]);
			// ft_putstr("ft_fieldflags: 3\n");
			x = -1;
			// printf("ft_fieldflags: RES[%d] is %s\n", i, res[i]);
			// printf("Before ft_presicion: Now res is %s\n", res[i]);
			res[i] = ft_presicion(res[i], wp[1], flags[i][len - 1]);
			// printf("After ft_presicion: Now res is %s\n", res[i]);
			// ft_putstr("ft_fieldflags: 4\n");
			// printf("ft_fieldflags: Width is [%d], precision is [%d]\n", wp[0], wp[1]);
			while (++x < 5)
				if (flg[x] != -1)
					res[i] = ft_flags[x](res[i], wp, flags[i][len - 1]);
			// ft_putstr("ft_fieldflags: 5: loop successful\n");
			res[i] = ft_Fwidth(res[i], wp[0], flg);
			// ft_putstr("ft_fieldflags: 6: ft_Fwidth successful\n");
		}
	}
	return (res);
}
