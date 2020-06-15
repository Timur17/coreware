/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 22:04:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				get_label_neg(char *ar, t_code *cur, t_code *begin)
{
	int			size;
	t_code		*temp;

	size = 0;
	temp = begin;
	while (temp)
	{
		if (ft_strequ(ar, temp->label))
			break ;
		temp = temp->next;
	}
	while (temp != cur && temp)
	{
		size = size + temp->size;
		temp = temp->next;
		if (temp == cur)
			return (size * (-1));
	}
	return (-1);
}

int				get_label(char *ar, t_code *cur, t_code *begin)
{
	int			size;
	t_code		*temp;

	size = 0;
	temp = cur;
	while (temp)
	{
		if (ft_strequ(ar, temp->label))
			return (size);
		size = size + temp->size;
		temp = temp->next;
	}
	size = get_label_neg(ar, cur, begin);
	return (size);
}
