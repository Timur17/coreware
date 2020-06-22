/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:39:46 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/22 23:04:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_search_end2(t_parce *pr, char *str)
{
	char	*end;
	char	*temp;

	while (read_file(pr) > 0)
	{
		if ((end = ft_strchr(pr->line, '\"')))
		{
			valid_end_line(pr, end - pr->line);
			if ((temp = ft_strsub(pr->line, 0, end - pr->line)) == NULL)
				ft_error("ERROR: allocate memory");
			str = joinstr_free(str, temp);
			return (str);
		}
		pr->leak = str;
		if ((str = ft_strjoin(str, pr->line)) == NULL)
			ft_error("ERROR: allocate memory");
		free(pr->leak);
	}
	free(str);
	return (NULL);
}

char	*ft_search_end(t_parce *pr)
{
	int		begin;
	char	*str;

	begin = ++(*pr->i);
	str = NULL;
	while (pr->line[*pr->i] != '\"' && pr->line[*pr->i] != '\0')
		(*pr->i)++;
	if ((str = ft_strsub(pr->line, begin, *pr->i - begin)) == NULL)
		ft_error("ERROR: allocate memory");
	if (pr->line[*pr->i] == '\"')
	{
		valid_end_line(pr, *pr->i);
		return (str);
	}
	if ((str = ft_search_end2(pr, str)) == NULL)
		ft_error("ERROR: miss ends quotes in name or comment");
	return (str);
}

char	*add_name_comment(t_parce *pr)
{
	char *str;

	ft_skip_space(pr);
	if (pr->line[*pr->i] == '\"')
		str = ft_search_end(pr);
	else
		ft_error_pos("EROOR: miss quotes", pr->row, *pr->i);
	return (str);
}

void	ft_full_name_com(t_parce *pr, t_header *head, int d)
{
	char	*str;

	str = add_name_comment(pr);
	if (d == 5)
	{
		if (ft_strlen(str) > PROG_NAME_LENGTH)
			ft_error("ERROR:Too big name");
		pr->name = 1;
		ft_strcat(head->prog_name, str);
	}
	if (d == 8)
	{
		if (ft_strlen(str) > COMMENT_LENGTH)
			ft_error("ERROR:Too big comment");
		pr->comment = 1;
		ft_strcat(head->comment, str);
	}
	free(str);
}

void	full_header(t_parce *pr, t_header *head, int d, int len)
{
	char	*str;
	int		length;
	char	*dst;

	dst = (d == 5) ? head->prog_name : head->comment;
	*pr->i = *pr->i + d;
	if (!(*dst))
		ft_full_name_com(pr, head, d);
	else if (d == 5)
		ft_error_pos("ERROR: unnecessary name", pr->row, -1);
	else
		ft_error_pos("ERROR: unnecessary comment", pr->row, -1);
}
