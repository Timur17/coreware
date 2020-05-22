/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:19:31 by wtorwold          #+#    #+#             */
/*   Updated: 2020/02/28 20:52:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		must_be_reg_dir(t_parce *pr, t_code *new, int arg)
{
	char *type;

	if (arg == 1)
		type = new->type_ar1;
	else if (arg == 2)
		type = new->type_ar2;
	else
		type = new->type_ar3;

	if (ft_strcmp(REG, type) && ft_strcmp(DIR, type))
		ft_error_arg(pr, arg, "T_DIR", "T_REG");
}

void		must_be_dir_ind(t_parce *pr, t_code *new, int arg)
{
	char *type;

	if (arg == 1)
		type = new->type_ar1;
	else if (arg == 2)
		type = new->type_ar2;
	else
		type = new->type_ar3;

	if (ft_strcmp(IND, type) && ft_strcmp(DIR, type))
		ft_error_arg(pr, arg, "T_DIR", "T_IND");
}


void		must_be_reg(t_parce *pr, t_code *new, int arg)
{
	char	*type;

	if (arg == 1)
		type = new->type_ar1;
	else if (arg == 2)
		type = new->type_ar2;
	else
		type = new->type_ar3;
	if (ft_strcmp(REG, type))
		ft_error_arg(pr, arg, "T_REG", NULL);
}

void		must_be_dir(t_parce *pr, t_code *new, int arg)
{
	if (ft_strcmp(DIR, new->type_ar1))
		ft_error_arg(pr, arg, "T_DIR", NULL);
}

void		must_be_reg_ind(t_parce *pr, t_code *new, int arg)
{
	char *type;

	if (arg == 1)
		type = new->type_ar1;
	else if (arg == 2)
		type = new->type_ar2;
	else
		type = new->type_ar3;

	if (ft_strcmp(IND, type) && ft_strcmp(REG, type))
		ft_error_arg(pr, arg, "T_REG", "T_IND");
}