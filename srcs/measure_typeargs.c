/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_typeargs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/21 12:06:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_full(char *type)
{
	char		*temp;

	if ((temp = ft_strnew(2)) == NULL)
		ft_error("ERROR: allocate memory");
	if (ft_strcmp(type, DIR) == 0)
		return (ft_strcat(temp, "10"));
	else if (ft_strcmp(type, IND) == 0)
		return (ft_strcat(temp, "11"));
	else if (ft_strcmp(type, REG) == 0)
		return (ft_strcat(temp, "01"));
	return ("00");
}

void			full_type_args(t_code *new, int flag, char *type_args)
{
	char		*str;

	if (flag == 1 && new->type_ar1)
	{
		str = ft_full(new->type_ar1);
		ft_memcpy(type_args, str, 2);
		free(str);
	}
	else if (flag == 2 && new->type_ar2)
	{
		str = ft_full(new->type_ar2);
		ft_memcpy(type_args + 2, str, 2);
		free(str);
	}
	else if (flag == 3 && new->type_ar3)
	{
		str = ft_full(new->type_ar3);
		ft_memcpy(type_args + 4, str, 2);
		free(str);
	}
}

void			measure_typeargs(t_code *new)
{
	char *type_args;
	long num;

	num = 0;
	num = type_code_args(new);
	if (num == 1)
	{
		type_args = ft_strnew(8);
		ft_memset(type_args, '0', 8);
		full_type_args(new, 1, type_args);
		full_type_args(new, 2, type_args);
		full_type_args(new, 3, type_args);
		num = ft_atoi_base(type_args, 2);
		new->type_args = ft_itoa_base(num, 16);
		free(type_args);
	}
}
