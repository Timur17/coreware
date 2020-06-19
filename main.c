/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/18 23:33:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list					*init_list(char *str)
{
	t_list				*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		ft_error("ERROR malloc");
	new->content = str;
	new->content_size = 0;
	new->next = NULL;
	return (new);
}

void					init(t_parce *pr)
{
	ft_bzero(pr, sizeof(pr));
	pr->cnt = 1;
	pr->line = NULL;
	pr->row = 0;
	pr->list = NULL;
	pr->cd = NULL;
	pr->cure = NULL;
	pr->size_code = 0;
	pr->comment = 0;
	pr->name = 0;
}

t_code					*init_code(void)
{
	t_code				*code;

	if (!(code = (t_code *)ft_memalloc(sizeof(t_code))))
		ft_error("ERROR malloc");
	code->label = NULL;
	code->cmnd = NULL;
	code->ar1 = NULL;
	code->ar2 = NULL;
	code->ar3 = NULL;
	code->type_ar1 = NULL;
	code->type_ar2 = NULL;
	code->type_ar3 = NULL;
	code->type_args = NULL;
	code->size = 0;
	code->l_conect = 0;
	code->next = NULL;
	code->size_dir = 0;
	code->row = 0;
	return (code);
}

void					init_hd(t_header *head)
{
	ft_bzero(head->prog_name, sizeof(head->prog_name));
	ft_bzero(head->comment, sizeof(head->comment));
	head->magic = 0xea83f3;
}

int						main(int ac, char **av)
{
	t_parce				pr;
	t_header			head;

	init(&pr);
	init_hd(&head);
	if (ac != 2)
		ft_error("Usage : ./asm <filename>");
	if ((pr.fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Open error");
	check_filename(av[1]);
	parce(&pr, &head);
	if (close(pr.fd) < 0)
		ft_error("Close error");
	binary_code(&pr, av[1], &head);
	ft_free(&pr);
	return (0);
}
