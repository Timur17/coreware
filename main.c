#include "asm.h"

t_list			*init_list(char *str)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		ft_error("ERROR malloc");
	new->content = str;
	new->content_size = 0;
	new->next = NULL;
	return (new);
}			

void	init(t_parce *pr)
{
	ft_bzero(pr, sizeof(pr));
	pr->cnt = 1;
	pr->line = NULL;
	pr->row = 0;
	pr->list = NULL;
	pr->cd = NULL;
	pr->cure = NULL;
	pr->size_code = 0;
}

t_code	*init_code()
{
	t_code	*code;

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

void		init_hd(header_t *head)
{
	ft_bzero(head->prog_name, sizeof(head->prog_name));
	ft_bzero(head->comment, sizeof(head->comment));
	head->magic = 0xea83f3;
}

int main(int ac, char **av) 
{
	t_parce			pr;
	header_t		head;

	init(&pr);
	init_hd(&head);
	if (ac != 2)
		ft_error("Usage : ./asm <filename>");
	if ((pr.fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Open error");
	parce(&pr, &head);
	if (close(pr.fd) < 0)
		ft_error("Close error");
	// int test = ft_valid_value("-65536", 2);
	// printf("test = %d\n", test);
	binary_code(&pr, av[1], &head);
	// char *num = ft_itoa_base('', 16);
	// printf ("------%s\n", num);
	// print_line(&pr.list);
	ft_free(&pr);
	return (0);
	// Не работает если команды в нчале или между именем и комментарием
	// выяснить макс и мин цифры
	// "Writing output program to %s\n", filename
	// non_printatble_char_in_name_VALID
}