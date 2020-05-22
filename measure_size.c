#include "asm.h"

int  ft_size_dir(char *cmnd, t_code *new)
{
    if (!(ft_strcmp(cmnd, ZJMP)) ||
	!(ft_strcmp(cmnd, LDI)) || !(ft_strcmp(cmnd, STI))
    || !(ft_strcmp(cmnd, LLDI)) || !(ft_strcmp(cmnd, FORK)) 
    || !(ft_strcmp(cmnd, LFORK)))
    {
        new->size_dir = 2;
		return (2);
    }
    else
    {
        new->size_dir = 4;
        return (4);
    }
}

int   ft_full_size(char *type, t_code *new)
{
    if (ft_strcmp(type, DIR) == 0)
        return(ft_size_dir(new->cmnd, new));
    else if (ft_strcmp(type, IND) == 0)
        return(2);
    else
        return(1);
}

int  count_size(t_code *new)
{
     int  size;

     size = 0;
     if (new->type_ar1)
         size = size + ft_full_size(new->type_ar1, new);
     if (new->type_ar2)
         size = size + ft_full_size(new->type_ar2, new);
     if (new->type_ar3)
         size = size + ft_full_size(new->type_ar3, new);
     return (size);
}

int     type_code_args(t_code *new)
{
    if (!(ft_strcmp(new->cmnd, LIVE)) ||
	!(ft_strcmp(new->cmnd, ZJMP)) || !(ft_strcmp(new->cmnd, FORK))
	|| !(ft_strcmp(new->cmnd, LFORK)))
		return (0);
    return (1);
}

void    measure_size(t_code *new, t_parce *pr)
{
    int num;
    
    num = 0;
    num = type_code_args(new);
    new->size = 1 + num;
    new->size += count_size(new);
    pr->size_code += new->size;
}