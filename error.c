/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 22:25:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_error_arg(t_parce *pr, int arg, char *type1, char *type2)
{
	printf("ERROR: Invalid type of arg %d at row %d\n", arg, pr->row);
	printf("Type must be %s", type1);
	if (type2)
		printf(" or %s", type2);
	printf("\n");
	exit(EXIT_FAILURE);
}

void		ft_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void		ft_error_label(char *str, int row)
{
	printf("ERROR: Invalid label -  %s at row %d\n", str, row);
	exit(EXIT_FAILURE);
}

void		ft_error_pos(char *str, int row, int col)
{
	if (col == -1)
		printf("%s at row %d\n", str, row);
	else if (row != 0)
		printf("%s at row %d collum %d\n", str, row, ++col);
	else
		printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void		error_size_code(t_parce *pr, t_header *head)
{
    //  if (pr->size_code > CHAMP_MAX_SIZE)
    //    ft_error("Size of code is too big");
	if (pr->size_code == 0)
		ft_error("ERROR:there are no commands");
	if (ft_strlen(head->prog_name) > PROG_NAME_LENGTH)
		ft_error("ERROR:Too big name");
	if (ft_strlen(head->comment) > COMMENT_LENGTH)
		ft_error("ERROR:Too big comment");
}
