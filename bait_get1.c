/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bait_get1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/21 12:17:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*get_reg(char *ar)
{
	char		*str;
	int			len;
	int			len_2;
	char		*type;

	type = ft_itoa_base(ft_atoi(ar), 16);
	len_2 = 1;
	len = (int)ft_strlen(type) - 1;
	str = ft_memset(ft_strnew(2), '0', 2);
	while (len >= 0)
		str[len_2--] = type[len--];
	free(type);
	return (str);
}

char			*get_code_arg(char *type, char *ar, t_parce *pr)
{
	char			*str;
	int				size;

	str = NULL;
	if (!(ft_strcmp(type, REG)))
	{
		return (get_reg(ar + 1));
	}
	else
	{
		if (ft_strequ(type, DIR) == 1)
			size = pr->cure->size_dir;
		else
			size = 2;
		str = get_dir_ind(ar, pr->cd, pr->cure, size);
		return (str);
	}
	return (str);
}

void			choose_flag(char **ar, char **type, int flag, t_code *cur)
{
	if (flag == 1)
	{
		*ar = cur->ar1;
		*type = cur->type_ar1;
	}
	else if (flag == 2)
	{
		*ar = cur->ar2;
		*type = cur->type_ar2;
	}
	else
	{
		*ar = cur->ar3;
		*type = cur->type_ar3;
	}
}

void			get_code_args(t_parce *pr, int flag, char *str, int *i)
{
	char			*ar;
	char			*type;
	char			*cpy;

	choose_flag(&ar, &type, flag, pr->cure);
	cpy = get_code_arg(type, ar, pr);
	if (cpy == NULL)
		ft_error_label(ar, pr->cure->row);
	ft_memcpy(str + *i, cpy, ft_strlen(cpy));
	*i = *i + ft_strlen(cpy);
	free(cpy);
}
