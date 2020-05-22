#include "asm.h"

void		valid_3_args(t_parce *pr, t_code *new, int arg)
{
	if ((arg == 1 && (!(ft_strcmp(new->cmnd, ADD)) || !(ft_strcmp(new->cmnd, SUB)) 
	|| !(ft_strcmp(new->cmnd, STI)))) 
	|| (arg == 3 && (!(ft_strcmp(new->cmnd, ADD)) || !(ft_strcmp(new->cmnd, SUB))
	|| !(ft_strcmp(new->cmnd, AND)) || !(ft_strcmp(new->cmnd, OR)) || !(ft_strcmp(new->cmnd, XOR)) 
	|| !(ft_strcmp(new->cmnd, LDI)) || !(ft_strcmp(new->cmnd, LLDI)))) 
	|| (arg == 2 && (!(ft_strcmp(new->cmnd, ADD)) || !(ft_strcmp(new->cmnd, SUB)))))
		must_be_reg(pr, new, arg);
	else if ((arg == 2 && (!(ft_strcmp(new->cmnd, LDI)) || !(ft_strcmp(new->cmnd, LLDI)))) 
	|| (arg == 3 && (!(ft_strcmp(new->cmnd, STI)))))
		must_be_reg_dir(pr, new, arg);
}

void		valid_2_args(t_parce *pr, t_code *new, int arg)
{
	if ((arg == 1 && (!(ft_strcmp(new->cmnd, LD)) || !(ft_strcmp(new->cmnd, LLD))))) 
		must_be_dir_ind(pr, new, arg);
	else if ((arg == 2 && (!(ft_strcmp(new->cmnd, LD)) || !(ft_strcmp(new->cmnd, LLD)))) 
	||  (arg == 1 && (!(ft_strcmp(new->cmnd, ST))))) 
		must_be_reg(pr, new, arg);
	else if (arg == 2 && (!(ft_strcmp(new->cmnd, ST))))
		must_be_reg_ind(pr, new, arg);
}

void		valid_arg(t_parce *pr, t_code *new)
{
	if (!(ft_strcmp(new->cmnd, LIVE)) || !(ft_strcmp(new->cmnd, ZJMP)) 
	|| !(ft_strcmp(new->cmnd, FORK)) || !(ft_strcmp(new->cmnd, LFORK))) 
		must_be_dir(pr, new, 1);
	else if (!(ft_strcmp(new->cmnd, AFF)))
		must_be_reg(pr, new, 1);
}

void	valid(t_parce *pr, t_code *new, int flag)
{
	if (flag == 3)
	{
		if (ft_strcmp(new->cmnd, ADD) && ft_strcmp(new->cmnd, SUB) && ft_strcmp(new->cmnd, AND) 
 	&& ft_strcmp(new->cmnd, OR) && ft_strcmp(new->cmnd, XOR) && ft_strcmp(new->cmnd, LDI) 
 	&& ft_strcmp(new->cmnd, STI) && ft_strcmp(new->cmnd, LLDI))
 		ft_error_pos("ERROR: invalid number of args", pr->row, -1);
	}
	else if (flag == 2)
	{
		if (ft_strcmp(new->cmnd, LD) && ft_strcmp(new->cmnd, ST) && ft_strcmp(new->cmnd, LLD))
	ft_error_pos("ERROR: invalid number of args", pr->row, -1);
	}
	else
	{
		if (ft_strcmp(new->cmnd, LIVE) && ft_strcmp(new->cmnd, ZJMP) && ft_strcmp(new->cmnd, FORK) 
	&& ft_strcmp(new->cmnd, LFORK) && ft_strcmp(new->cmnd, AFF))
	ft_error_pos("ERROR: invalid number of args", pr->row, -1);
	}
}

void		valid_args(t_parce *pr, t_code *new)
{
	if (new->ar1 && new->ar2 && new->ar3)
	{
		valid(pr, new, 3);
		valid_3_args(pr, new, 1);
		valid_3_args(pr, new, 2);
		valid_3_args(pr, new, 3);
	}
	else if (new->ar1 && new->ar2)
	{
		valid(pr, new, 2);
		valid_2_args(pr, new, 1);
		valid_2_args(pr, new, 2);
	}
	else
	{
		valid(pr, new, 1);
		valid_arg(pr, new);
	}

}