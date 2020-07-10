/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:19:31 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 22:26:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_free_head(t_header *head)
{
	t_header *cpy;

	cpy = head;
	free(cpy->prog_name);
	free(cpy->comment);
	free(cpy);
	cpy = NULL;
}

void				ft_free_list(t_list *list)
{
	t_list *cpy;
	t_list *temp;

	cpy = list;
	while (cpy)
	{
		temp = cpy;
		cpy = cpy->next;
		free(temp->content);
		free(temp);
		temp = NULL;
	}
}

void				ft_free_code_help(t_code *temp)
{
	free(temp->cmnd);
	if (temp->ar1)
		free(temp->ar1);
	if (temp->ar2)
		free(temp->ar2);
	if (temp->ar3)
		free(temp->ar3);
	if (temp->type_args)
		free(temp->type_args);
}

void				ft_free_code(t_code *code)
{
	t_code *cpy;
	t_code *temp;

	cpy = code;
	while (cpy)
	{
		temp = cpy;
		cpy = cpy->next;
		if (temp->label)
			free(temp->label);
		else
			ft_free_code_help(temp);
		free(temp);
		temp = NULL;
	}
}

void				ft_free(t_parce *pr)
{
	ft_free_list(pr->list);
	ft_free_code(pr->cd);
}
