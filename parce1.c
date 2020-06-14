/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/13 12:17:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_add_line(t_parce *pr)
{
	t_list		*temp;
	t_list		*new;

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

void			check_line(t_parce *pr)
{
	int i;

	i = 0;
	while(ft_space(pr->line[i]))
	 	i++;
	 if (pr->line[i] == '\0')
	 	return ;
	while (pr->line[i])
		i++;
	if (pr->line[--i] != '\n')
	{
		printf("Line %d don't have newline\n", pr->row);
		exit (0);
	}
}

int				read_file(t_parce *pr)
{
	int			n;
	
	if ((n = gnl(pr->fd, &pr->line)) == -1)
		ft_error("Error reading file");
	pr->row++;
	if (n > 0)
	{
		check_line(pr);
		ft_add_line(pr);
	}
	return (n);
}

void	ft_skip_space(t_parce *pr)
{
	while (ft_space(pr->line[*pr->i]))
		(*pr->i)++;
}

void		skip_comment(t_parce *pr)
{
	while (pr->line[*pr->i])
		(*pr->i)++;
}

void	parce(t_parce *pr, header_t *head)
{
	int		i;
	char	*str;

	while (read_file(pr))
	{
		i = 0;
		pr->i = &i;
		ft_skip_space(pr);
		if (pr->line[*pr->i] == COMMENT_CHAR || pr->line[*pr->i] == COMMENT_CHAR_ALT 
		||  pr->line[*pr->i] == '\0')
			continue ;
		else if (ft_strncmp(pr->line + *pr->i, NAME_CMD_STRING, 5) == 0)
		{
			str = full_str(pr, head->prog_name, 5, PROG_NAME_LENGTH);
			ft_strcat(head->prog_name, str);
			pr->name = 1;
			free (str);
		}
		else if (ft_strncmp(pr->line + *pr->i, COMMENT_CMD_STRING, 8) == 0)
		{
			str = full_str(pr, head->comment, 8, COMMENT_LENGTH);
		 	ft_strcat(head->comment, str);
			pr->comment = 1;
			free (str);
		}
		else if (check_label(pr) && pr->comment == 1 && pr->name == 1)
			add_label(pr);
		else if (check_command(pr) && pr->comment == 1 && pr->name == 1)
		 	add_command(pr);
		else if (pr->line[*pr->i] != '\0')
		 	ft_error_pos("ERROR: Unexpected symvol", pr->row, *pr->i);
	}
	if (pr->comment == 0 || pr->name == 0)
		ft_error("Error file is emty");
//	 ft_error_head(head);
	//	error_size_code(pr);
//	printf("%s\n", pr->line);
//	printf ("header name=%s\n", head->prog_name);
//	printf ("header comment=%s\n", head->comment);

//	printt_code(pr->cd);
	// print_line(pr->list);
}