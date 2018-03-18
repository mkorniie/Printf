#include "header.h"

void	ft_addustring(void)
{
    int** temp;
    int len;
    int i;

    len = 0;
    i = 0;
    temp = UNISTRINGS;
    if (UNISTRINGS != NULL)
        while (UNISTRINGS[i])
            i++;
    len += i;
    UNISTRINGS = (int**)malloc(sizeof(int*) * (len + 2));
    UNISTRINGS[len + 1] = 0;
    i = -1;
    if (temp != NULL)
        while (temp[++i])
            UNISTRINGS[i] = temp[i];
    ft_freeintarr(temp, 0);
    UNISTRINGS[CURR] = NULL;
}