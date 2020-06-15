/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 23:40:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_skip_space(t_parce *pr)
{
	while (ft_space(pr->line[*pr->i]))
		(*pr->i)++;
}

void				skip_comment(t_parce *pr)
{
	while (pr->line[*pr->i])
		(*pr->i)++;
}

void				skip_separator(t_parce *pr)
{
	int		i;

	i = *pr->i + 1;
	while (ft_space(pr->line[i]))
		i++;
	if (pr->line[i] != '\0')
		(*pr->i)++;
}
