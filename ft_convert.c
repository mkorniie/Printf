/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:30:55 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:56 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_getcvsindex(int mod, char *flag)
{
	int		cvs;
	size_t	len;

	len = ft_strlen(flag);
	cvs = ft_isspecifier(flag[len - 1]);
	if (cvs == 2)
		return (2);
	if (cvs == 7 || cvs == 9)
		return ((cvs == 7 ? 7 : 9));
	if (cvs == 4)
        return (3);
	if (mod == 0 || mod == 1)
		return (ft_modifpart1(mod, cvs));
	if (mod >= 2 && mod <= 5)
		return (ft_modifpart2(mod, cvs));
	return (-1);
}

char	*ft_extractor(va_list ap, int z, char *flag)
{
	int hasmod;

	if ((hasmod = ft_isMod(flag)) == -1)
		return (ft_cvs[z](ap));
	else
		z = ft_getcvsindex(hasmod, flag);
	return (ft_cvs[z](ap));
}

char    *ft_findconv(va_list ap, char **flag)
{
    int		z;
    char	*res;
	char 	*temp;
    int		strlen;

    z = -1;
    strlen = ft_strlen(*flag);
    while (convs[++z])
        if (convs[z][0] == (*flag)[strlen - 1])
        {
            res = ft_extractor(ap, z, *flag);
            if (ft_strchr("Cc", (*flag)[strlen - 1]) != NULL)
                if (ft_strcmp(res, "zero") == 0)
                {
					temp = res;
                    res = ft_strdup("z");
					free(temp);
                    (*flag) = ft_strjoinfree(*flag, "!", 1);
                }
        }
    return (res);
}

char	**ft_get(va_list ap, char **flags, char **arr)
{
	int i;
	int strlen;

	i = -1;
	while (++i < N_OF_F)
		if (flags[i] == NULL)
			arr[i] = NULL;
		else
		{
			strlen = ft_strlen(flags[i]);
			if (flags[i][strlen - 1] == '%')
				arr[i] = ft_strdup("%");
			else if (flags[i][strlen - 1] == '^')
                arr[i] = ft_strndup(flags[i] + strlen - 2, 1);
			else
                arr[i] = ft_findconv(ap, &(flags[i]));
		}
	return (arr);
}

char	**ft_convert(va_list ap, char **flags)
{
	char	**res;
	if (!(res = (char**)malloc(sizeof(char*) * (N_OF_F + 1))))
		return (NULL);
	res[N_OF_F] = NULL;
	CURR = 0;
	res = ft_get(ap, flags, res);
	res = ft_fieldflags(res, flags);
	return (res);
}
