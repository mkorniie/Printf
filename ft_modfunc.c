#include "header.h"

int	ft_modifpart1(int mod, int cvs)
{
	if (mod == 0)
	{
		if (cvs == 3 || cvs == 5)
			return (44);
		if (cvs == 6 || cvs == 8 )
			return (cvs == 6 ? 23 : 24);
		if (cvs == 10 || cvs == 11)
			return (cvs == 10 ? 25 : 26);
		if (cvs == 1 || cvs == 13)
			return (cvs);
		return (-1);
	}
	if (mod == 1)
	{
		if (cvs == 3 || cvs == 5)
			return (27);
		if (cvs == 6 || cvs == 8 )
			return (cvs == 6 ? 28 : 29);
		if (cvs == 10 || cvs == 11)
			return (cvs == 10 ? 30 : 31);
		return (-1);
	}
	return (-1);
}

int	ft_modifpart2(int mod, int cvs)
{
	// ft_putstr("returns\n");
	// if (cvs == 4)
	// 		return (3);
	if (mod == 2)
	{
		// ft_putstr("returns\n");
		// printf("CVS is [%d]\n", cvs);
		if (cvs == 3 || cvs == 5)
			return (4);
		if (cvs == 6 || cvs == 8 )
			return (cvs == 6 ? 7 : 9);
		if (cvs == 10 || cvs == 11)
			return (cvs == 10 ? 32 : 33);
		if (cvs == 0 || ((cvs >= 12) && (cvs <= 20)))
		{
			// ft_putstr("Here!\n");
			return(cvs % 2 == 0 ? cvs + 1 : cvs - 1);
		}
		return (-1);
	}
	if (mod == 3 || mod == 4)
	{
		if (cvs == 3 || cvs == 5)
			return (34);
		if (cvs == 6 || cvs == 8 )
			return (cvs == 6 ? 35 : 36);
		if (cvs == 10 || cvs == 11)
			return (cvs == 10 ? 37 : 38);
		return (-1);
	}
	if (mod == 5)
	{
		if (cvs == 3 || cvs == 5)
			return (39);
		if (cvs == 6 || cvs == 8 )
			return (cvs == 6 ? 40 : 41);
		if (cvs == 10 || cvs == 11)
			return (cvs == 10 ? 42 : 43);
		return (-1);
	}
	return (-1);
}

int	ft_isMod(char *flag)
{
	size_t len;

	len = ft_strlen(flag);
	if (len < 2)
		return (-1);
	if (ft_strchr(flag, 'h') != NULL)
		return (ft_strstr(flag, "hh") != NULL ? 0 : 1);
	if (ft_strchr(flag,'l') != NULL)
		return (ft_strstr(flag, "ll") != NULL? 3 : 2);
	if (ft_strchr(flag,'j') != NULL)
		return (4);
	if (ft_strchr(flag,'z') != NULL)
		return (5);
	return (-1);
}
