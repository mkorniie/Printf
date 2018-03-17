#include "header.h"

void ft_freeintarr(int **split, int len)
{
	int i;

	if (split == NULL)
		return ;
	i = 0;
	while(i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_freestrarr(char **split)
{
	int i;

	if (split == NULL)
		return ;
	i = 0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}