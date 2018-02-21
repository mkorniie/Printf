#include "header.h"

void	ft_freearr(char **split)
{
	int i;

	i = 0;
	if (split == NULL)
		return ;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}