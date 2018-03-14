#include "header.h"

char	*ft_chartostr(char c)
{
    char *res;

    res = (char*)malloc(sizeof(char) * 2);
    res[0] = c;
    res[1] = '\0';
    return (res);
}