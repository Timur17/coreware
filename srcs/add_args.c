/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/22 23:53:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_arg(t_code *new, char *str, int *arg, char *type)
{
	if (*arg == 1)
	{
		new->ar1 = str;
		new->type_ar1 = type;
	}
	if (*arg == 2)
	{
		new->ar2 = str;
		new->type_ar2 = type;
	}
	if (*arg == 3)
	{
		new->ar3 = str;
		new->type_ar3 = type;
	}
	(*arg)++;
}

char		*add_arg_lable(t_parce *pr)
{
	int		i;
	char	*str;
	int		len;
	char	*leak;

	i = *pr->i;
	len = 0;
	while (ft_strchr(LABEL_CHARS, pr->line[*pr->i]))
	{
		len++;
		(*pr->i)++;
	}
	if (len == 0)
		ft_error_pos("ERROR: invalid label", pr->row, *pr->i);
	if ((str = ft_strsub(pr->line, i, len)) == NULL)
		ft_error("ERROR: allocate memory");
	if ((leak = ft_strjoin(":", str)) == NULL)
		ft_error("ERROR: allocate memory");
	free(str);
	str = leak;
	return (str);
}

char		*add_arg_digit(t_parce *pr)
{
	int		num;
	char	*str;
	int		i;
	int		neg;

	num = 0;
	neg = 0;
	i = *pr->i;
	if (pr->line[*pr->i] == '-')
	{
		neg = 1;
		(*pr->i)++;
	}
	while (ft_isdigit(pr->line[*pr->i]))
	{
		num++;
		(*pr->i)++;
	}
	if (num == 0)
		ft_error_pos("ERROR: invalid digit", pr->row, *pr->i);
	if ((str = ft_strsub(pr->line, i, num + neg)) == NULL)
		ft_error("ERROR: allocate memory");
	return (str);
}
