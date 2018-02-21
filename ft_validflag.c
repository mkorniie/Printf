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

	i = 0;
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	while (temp[++i] != '\0')
	{
		if ((val_index = ft_isvalid(temp[i])) == -1)
		{
			// ft_putstr("Valid flag: WE RETURN NULL");
			return (NULL);
		}
		if (val_index < 24)
		{
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