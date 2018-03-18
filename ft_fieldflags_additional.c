#include "header.h"

int	ft_isflag(char *flag, char x)
{
	char   *temp;
	int    i;
	int len;

	if ((temp = ft_strchr(flag, x)) == NULL)
		return (-1);
	else
	if (x == '0')
	{
		len = ft_strlen(flag) - ft_strlen(temp);
		i = -1;
		while (++i < len)
			if (ft_isdigit(flag[i]) != 0 || flag[i] == '.')
				return (-1);
	}
	return (1);
}

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

int *ft_setwp(void) {
	int *wp;

	wp = (int *) malloc(sizeof(int) * 3);
	wp[0] = -1;
	wp[1] = -1;
	wp[2] = 0;
	return(wp);
}

int	*ft_widthPres(char *flag, int zeroflag)
{
	int *wp;
	char *temp;
	int	i;
	int last_char;

	i = -1;
	last_char = ft_strlen(flag) - 1;
	wp = ft_setwp();
	if ((temp = ft_strstr(flag, ".")) != NULL)
		if (ft_isdigit(temp[1]))
			wp[1] = ft_atoi(temp + 1);
		else if (!(ft_isdigit(temp[1])))
			wp[1] = 0;
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

int *ft_findflag(char *flag)
{
	int *flgI;
	int i[2];
	char *flgs;
	char *works[2];

	flgs = "0# +-"; /*now 02 is 04*/
	works[1] = "oOxXaAeEfFgG";		/* for hash */
	works[0] = "%diouxXaAeEfFgGsc!Sp^";	/* for zero */
	flgI = (int *)malloc(sizeof(int) * 6);
	flgI[5] = 0;
	i[0] = -1;
	while (++i[0] < 5)
		flgI[i[0]] = ft_isflag(flag, flgs[i[0]]); /**/
	flgI[0] = ((flgI[0] == 1 && flgI[4] == 1) ? -1 : flgI[0]);
	flgI[2] = ((flgI[2] == 1 && flgI[3] == 1) ? -1 : flgI[2]);
	i[0] = -1;
	while (++i[0] < 2)
		if (flgI[i[0]] == 1)
		{
			i[1] = -1;
			flgI[i[0]] = -1;
			while (works[i[0]][++i[1]] != '\0')
				if(flag[ft_strlen(flag) - 1] == works[i[0]][i[1]])
					flgI[i[0]] = 1;
		}
	return (flgI);
}
