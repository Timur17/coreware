/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 22:26:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*get_code(t_code *cur, t_parce *pr)
{
	char			*str;
	int				i;

	i = 2;
	pr->cure = cur;
	str = ft_strnew(cur->size * i);
	ft_memcpy(str, command(cur->cmnd), i);
	if (cur->type_args)
	{
		ft_memcpy(str + i, cur->type_args, i);
		i = i + 2;
	}
	if (cur->ar1)
		get_code_args(pr, 1, str, &i);
	if (cur->ar2)
		get_code_args(pr, 2, str, &i);
	if (cur->ar3)
		get_code_args(pr, 3, str, &i);
	pr->cure = NULL;
	return (str);
}

void				full_command(t_parce *pr, char *str, int i)
{
	t_code			*cur;
	char			*cpy;

	cur = pr->cd;
	while (cur)
	{
		if (cur->cmnd)
		{
			cpy = get_code(cur, pr);
			ft_memcpy(str + i, cpy, ft_strlen(cpy));
			i += (int)ft_strlen(cpy);
			free(cpy);
		}
		cur = cur->next;
	}
}

void				command_to_byte(char *str, char *bytecode, int pos)
{
	char			*new;
	int				i;
	int				dec;

	i = 0;
	while (str[i])
	{
		new = ft_strnew(2);
		new[0] = str[i];
		new[1] = str[i + 1];
		i = i + 2;
		dec = ft_atoi_hec_to_decimal(new);
		int32_to_bytecode(bytecode, pos++, dec, 1);
		free(new);
	}
}

char				*transform(t_parce *pr, t_header *head, char *av)
{
	int32_t			len;
	int32_t			pos;
	char			*bytecode;
	char			*str;

	pos = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + pr->size_code;
	bytecode = ft_strnew(len);
	int32_to_bytecode(bytecode, pos, COREWAR_EXEC_MAGIC, 4);
	pos = pos + 4;
	ft_memcpy(&bytecode[pos], head->prog_name, ft_strlen(head->prog_name));
	pos = pos + PROG_NAME_LENGTH + 4;
	int32_to_bytecode(bytecode, pos, pr->size_code, 4);
	pos = pos + 4;
	ft_memcpy(&bytecode[pos], head->comment, ft_strlen(head->comment));
	pos = pos + COMMENT_LENGTH + 4;
	str = ft_strnew(pr->size_code * 2);
	ft_memset(str, '0', pr->size_code * 2);
	full_command(pr, str, 0);
	command_to_byte(str, bytecode, pos);
	free(str);
	return (bytecode);
}

void				binary_code(t_parce *pr, char *av, t_header *head)
{
	char			*name;
	char			*bytecode;
	int				len;

	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + pr->size_code;
	bytecode = transform(pr, head, av);
	name = replace_name(av, ft_strlen(av));
	if ((pr->fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		ft_error("Can't create file");
	write(pr->fd, bytecode, len);
	if (close(pr->fd))
		ft_error("Can't close file");
	printf("%s %s\n", "Writing output program to", name);
	free(name);
	free(bytecode);
}
