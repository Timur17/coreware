/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/21 12:12:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_separator(t_parce *pr)
{
	ft_skip_space(pr);
	if (pr->line[*pr->i] == SEPARATOR_CHAR)
		skip_separator(pr);
	else if (pr->line[*pr->i] == COMMENT_CHAR ||
	pr->line[*pr->i] == COMMENT_CHAR_ALT)
		skip_comment(pr);
	else
	{
		if (pr->line[*pr->i] != '\0')
			ft_error_pos("ERROR: miss separator", pr->row, *pr->i);
	}
}

void		check_reg(t_parce *pr, int *arg, t_code *new)
{
	char		*str;
	int			i;
	int			num;
	int			len;

	num = 0;
	len = 0;
	i = *pr->i;
	(*pr->i)++;
	while (ft_isdigit(pr->line[(*pr->i)]))
	{
		(*pr->i)++;
		len++;
	}
	if (len > 2 || len == 0)
		ft_error_pos("ERROR: invalid T_REG", pr->row, *pr->i);
	if ((str = ft_strsub(pr->line, i + 1, len)) == NULL)
		ft_error("ERROR: allocate memory");
	num = ft_atoi(str);
	if (num <= 0 || num > REG_NUMBER)
		ft_error_pos("ERROR: invalid T_REG", pr->row, *pr->i);
	free(str);
	if ((str = ft_strsub(pr->line, i, len + 1)) == NULL)
		ft_error("ERROR: allocate memory");
	add_arg(new, str, arg, REG);
	check_separator(pr);
}

void		check_dir(t_parce *pr, int *arg, t_code *new)
{
	char	*str;

	(*pr->i)++;
	if (pr->line[*pr->i] == LABEL_CHAR)
	{
		(*pr->i)++;
		str = add_arg_lable(pr);
	}
	else
		str = add_arg_digit(pr);
	add_arg(new, str, arg, DIR);
	check_separator(pr);
}

void		check_ind(t_parce *pr, int *arg, t_code *new)
{
	char *str;

	str = NULL;
	if (pr->line[*pr->i] == LABEL_CHAR)
	{
		(*pr->i)++;
		str = add_arg_lable(pr);
	}
	else
		str = add_arg_digit(pr);
	if (str == NULL)
		ft_error_pos("ERROR: invalid T_IND", pr->row, *pr->i);
	add_arg(new, str, arg, IND);
	check_separator(pr);
}

void		check_arg(t_parce *pr, t_code *new)
{
	int		*arg;
	int		temp;

	temp = 1;
	arg = &temp;
	while (pr->line[*pr->i] && *arg <= 3)
	{
		ft_skip_space(pr);
		if (pr->line[*pr->i] == COMMENT_CHAR ||
		pr->line[*pr->i] == COMMENT_CHAR_ALT)
			skip_comment(pr);
		if (pr->line[*pr->i] == 'r')
			check_reg(pr, arg, new);
		else if (pr->line[*pr->i] == '%')
			check_dir(pr, arg, new);
		else if (ft_isdigit(pr->line[*pr->i]) ||
		pr->line[*pr->i] == LABEL_CHAR || pr->line[*pr->i] == '-')
			check_ind(pr, arg, new);
		else if (pr->line[*pr->i] != '\0')
			ft_error_pos("ERROR: Unexpected symvol in arg", pr->row, *pr->i);
	}
	if (*arg == 1)
		ft_error_pos("EROR; miss arg", pr->row, *pr->i);
	if (pr->line[*pr->i])
		ft_error_pos("ERROR: Unexpected symvol in arg", pr->row, *pr->i);
}
