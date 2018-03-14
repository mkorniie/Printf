#include "header.h"

int	ft_isvalid(char x)
{
		// ft_putstr("ft_isvalid\n");
	char	*all;
	int		i;

	all = "sSpdDioOuUxXcCeEfFgGaAn%hljz#0-+ 123456789.";
	i = -1;
	while (all[++i] != '\0')
		if (x == all[i])
			return(i);
	return(-1);
}

int	ft_isspecifier(char x)
{
		// ft_putstr("ft_isspecifier\n");
	char	*all;
	int		i;

	all = "sSpdDioOuUxXcCeEfFgGaAn%";
	i = -1;
	while (all[++i] != '\0')
		if (x == all[i])
		{
			// ft_putstr("ft_isspecifier: return success!\n");
			return(i);
		}
		// ft_putstr("ft_isspecifier: return -1!\n");
	return(-1);
}

char *ft_validflag(char *temp)
{
	int		i;
	char	*res;
	int		val_index;

	// ft_putstr("Valid flag is: ");
	// ft_putstr(temp);
	// ft_putstr("\n");

// ft_putstr("19\n");
	i = 0;
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	// ft_putstr("20\n");
	while (temp[++i] != '\0')
	{
		// ft_putstr("21\n");
		if ((val_index = ft_isvalid(temp[i])) == -1)
		{
			int *wp;
			int zeroflag;

			wp = (int*)malloc(sizeof(int) * 2);
			if (i > 1)
			{
				res = ft_strndup(temp, i + 1);
				zeroflag = ft_isflag(res, '0');
				printf("We have res = [%s]\n", res);
				wp = ft_widthPres(res, zeroflag);
				if (wp[0] > 1)
				{
					res = ft_strjoin(res, "^");
					return(res);
				}
			}
			// ft_putstr("Valid flag: WE RETURN NULL");
			// if ((i > 1) && )
			return (NULL);
		}
		if (val_index < 24)
		{
			// ft_putstr("22\n");
			// ft_putchar(temp[i - 1]);
			// ft_putchar(temp[i]);
			// if ((temp[i] == 'c') && (temp[i - 1] == 'l'))
			// {
			// 	// printf("ft_strndup([%s], [%d])\n", temp, i - 1);
			// 	res = ft_strndup(temp, i - 1);
			// 	res = ft_strjoin(res, "C");
			// }
			// else
			res = ft_strndup(temp, i + 1);
			// ft_putstr("Valid flag: WE RETURN ");
			// ft_putstr(res);
			// ft_putstr("\n");
			return (res);
		}
	}
	// ft_putstr("Valid flag: WE RETURN NULL");
	return (NULL);
	// if (ft_strlen(temp) == 1)
	// {
	// 	// printf("WE RETURN NULL!\n");
	// 	return (NULL);
	// }
	// // printf("The FOUND Flag[%d] is \'%s\'\n", lim, temp);
	// if(temp[1] == '%')
	// 	flag = ft_strdup("%%");
	// 	i = 1;
	// printf("IN ELSE\n");
	// while(temp[i] != '\0' && (ft_isspecifier(temp[i])) < 0)
	// {
	// 	printf("IN ELSE: temp[%d] is %c\n", i, temp[i]);
	// 	i++;
	// }
	// if ((temp[i]) != '\0')
	// 	flag = ft_strndup(temp, i + 1);
	// else
	// 	flag = NULL;
}