#include "asm.h"

int		check_command(t_parce *pr)
{
	if (!(ft_strncmp(pr->line + *pr->i, LIVE, 4)) ||
	!(ft_strncmp(pr->line + *pr->i, ZJMP, 4)) || !(ft_strncmp(pr->line + *pr->i, FORK, 4))
	|| !(ft_strncmp(pr->line + *pr->i, LLDI, 4)))
		return (4);
	if (!(ft_strncmp(pr->line + *pr->i, ADD, 3)) || !(ft_strncmp(pr->line + *pr->i, SUB, 3))
	|| !(ft_strncmp(pr->line + *pr->i, AND, 3)) || !(ft_strncmp(pr->line + *pr->i, XOR, 3))
	|| !(ft_strncmp(pr->line + *pr->i, LDI, 3)) || !(ft_strncmp(pr->line + *pr->i, STI, 3))
	|| !(ft_strncmp(pr->line + *pr->i, LLD, 3)) || !(ft_strncmp(pr->line + *pr->i, AFF, 3)))
		return (3);
	if (!(ft_strncmp(pr->line + *pr->i, LD, 2)) || !(ft_strncmp(pr->line + *pr->i, ST, 2))
	|| !(ft_strncmp(pr->line + *pr->i, OR, 2)))
		return (2);
	if (!(ft_strncmp(pr->line + *pr->i, LFORK, 5)))
		return (5);
	return (0);
}

void	add_command(t_parce *pr)
{
	int		i;
	t_code	*new;

	i = check_command(pr);
	new = init_code();
	new->cmnd = ft_strsub(pr->line, *pr->i, i);
	new->l_conect = pr->cnt++;
	*pr->i = *pr->i + i;
	new->row = pr->row;
	check_arg(pr, new);
	valid_args(pr, new);
	measure_size(new, pr);
	measure_typeargs(new);
	creat_list(pr, new);
}

void	creat_list(t_parce *pr, t_code *new)
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

void	add_label(t_parce *pr)
{
	int		i;
	t_code	*new;

	i = check_label(pr);

	new = init_code();
	new->label = ft_strsub(pr->line, *pr->i, i - *pr->i);
	new->l_conect = pr->cnt;
	new->row = pr->row;
	valid_labels(pr, new->label);
	creat_list(pr, new);
	*pr->i =  i + 1;
	ft_skip_space(pr);
	if (pr->line[*pr->i] && pr->line[*pr->i] != COMMENT_CHAR)
		{
			if (check_command(pr) == 0)
				ft_error_pos("ERROR: Unexpected symvol after label", pr->row, *pr->i);
			else
				add_command(pr);
		}
}

int		check_label(t_parce *pr)
{
	int i;

	i = *pr->i;
	while (ft_strchr(LABEL_CHARS, pr->line[i]))
		i++;
	if (pr->line[i] == LABEL_CHAR && i != *pr->i)
		return (i);
	return (0); 
}