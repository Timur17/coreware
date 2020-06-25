/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/25 12:20:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				creat_list(t_parce *pr, t_code *new)
{
	t_code	*temp;

	temp = pr->cd;
	if (pr->cd == NULL)
		pr->cd = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void				ft_add_line(t_parce *pr)
{
	t_list			*temp;
	t_list			*new;

	new = init_list(pr->line);
	temp = pr->list;
	if (pr->list == NULL)
		pr->list = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void				check_line(t_parce *pr)
{
	int				i;

	i = 0;
	while (ft_space(pr->line[i]))
		i++;
	if (pr->line[i] == '\0' || pr->line[i] == '#')
		return ;
	while (pr->line[i])
		i++;
	if (pr->line[--i] != '\n')
		ft_error_pos("Line don't have newline", pr->row, -1);
}

int					read_file(t_parce *pr)
{
	int				n;

	if ((n = gnl(pr->fd, &pr->line)) == -1)
		ft_error("ERROR reading file");
	pr->row++;
	if (n > 0)
	{
		check_line(pr);
		ft_add_line(pr);
	}
	return (n);
}

void				parce(t_parce *pr, t_header *head)
{
	int				i;

	while (read_file(pr))
	{
		i = 0;
		pr->i = &i;
		ft_skip_space(pr);
		if (pr->line[*pr->i] == COMMENT_CHAR
		|| pr->line[*pr->i] == COMMENT_CHAR_ALT || pr->line[*pr->i] == '\0')
			continue ;
		else if (ft_strncmp(pr->line + *pr->i, NAME_CMD_STRING, 5) == 0)
			full_header(pr, head, 5, PROG_NAME_LENGTH);
		else if (ft_strncmp(pr->line + *pr->i, COMMENT_CMD_STRING, 8) == 0)
			full_header(pr, head, 8, COMMENT_LENGTH);
		else if (check_label(pr) && pr->comment == 1 && pr->name == 1)
			add_label(pr);
		else if (check_command(pr) && pr->comment == 1 && pr->name == 1)
			add_command(pr);
		else if (pr->line[*pr->i] != '\0')
			ft_error_pos("ERROR: Unexpected symvol", pr->row, *pr->i);
	}
	if (pr->comment == 0 || pr->name == 0)
		ft_error("ERROR: Lack of name or comment");
	error_size_code(pr);
}
