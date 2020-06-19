/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:39:46 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/19 00:00:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	valid_end_line(t_parce *pr, int i)
{
	i++;
	while (ft_space(pr->line[i]))
		i++;
	if (pr->line[i] && pr->line[i] != '#')
		ft_error_pos("ERROR: unexpected symbol", pr->row, *pr->i);
}

char	*ft_search_end2(t_parce *pr, char *str)
{
	char	*end;
	char	*temp;

	while (read_file(pr) > 0)
	{
		if ((end = ft_strchr(pr->line, '\"')))
		{
			valid_end_line(pr, end - pr->line);
			temp = ft_strsub(pr->line, 0, end - pr->line);
			str = joinstr_free(str, temp);
			return (str);
		}
		pr->leak = str;
		str = ft_strjoin(str, pr->line);
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

void	full_header(t_parce *pr, t_header *head, int d, int len)
{
	char	*str;
	int		length;
	char	*dst;

	dst = (d == 5) ? head->prog_name : head->comment;
	*pr->i = *pr->i + d;
	if (!(*dst))
	{
		str = add_name_comment(pr);
		if (d == 5)
		{
			pr->name = 1;
			ft_strcat(head->prog_name, str);
		}
		if (d == 8)
		{
			pr->comment = 1;
			ft_strcat(head->comment, str);
		}
		free(str);
	}
	else if (d == 5)
		ft_error_pos("ERROR: unnecessary name", pr->row, -1);
	else
		ft_error_pos("ERROR: unnecessary comment", pr->row, -1);
}
