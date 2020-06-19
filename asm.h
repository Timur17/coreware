/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:19:31 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/18 23:51:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "op.h"
# include "command.h"

# define DIR			"DIR"
# define IND			"IND"
# define REG			"REG"

typedef struct			s_code
{
	int					l_conect;
	char				*label;
	char				*cmnd;
	char				*ar1;
	char				*ar2;
	char				*ar3;
	char				*type_ar1;
	char				*type_ar2;
	char				*type_ar3;
	char				*type_args;
	int					row;
	int					size_dir;
	int					size;
	struct s_code		*next;
}						t_code;

typedef struct			s_parce
{
	int					cnt;
	int					fd;
	char				*line;
	int					row;
	int					*i;
	char				*leak;
	t_list				*list;
	t_code				*cd;
	t_code				*cure;
	unsigned			size_code;
	int					name;
	int					comment;
}						t_parce;

void					parce(t_parce *pr, t_header *head);
void					full_header(t_parce *pr, t_header *head, int d, int len);
int						read_file(t_parce *pr);
void					ft_error(char *str);
void					ft_error_pos(char *str, int row, int col);
void					ft_error_head(t_header *head);
void					ft_error_arg
						(t_parce *pr, int arg, char *type1, char *type2);
void					error_size_code(t_parce *pr, t_header *head);
void					ft_error_label(char *str, int flag);
int						check_label(t_parce *pr);
int						check_command(t_parce *pr);
void					check_arg(t_parce *pr, t_code *new);
void					add_label(t_parce *pr);
void					add_command(t_parce *pr);
void					valid_args(t_parce *pr, t_code *new);
void					must_be_reg_dir(t_parce *pr, t_code *new, int arg);
void					must_be_dir_ind(t_parce *pr, t_code *new, int arg);
void					must_be_reg(t_parce *pr, t_code *new, int arg);
void					must_be_dir(t_parce *pr, t_code *new, int arg);
void					must_be_reg_ind(t_parce *pr, t_code *new, int arg);
t_code					*init_code();
void					creat_list(t_parce *pr, t_code *new);
void					ft_skip_space(t_parce *pr);
void					skip_comment(t_parce *pr);
void					skip_separator(t_parce *pr);
void					add_arg(t_code *new, char *str, int *arg, char *type);
char					*add_arg_lable(t_parce *pr);
char					*add_arg_digit(t_parce *pr);
void					binary_code(t_parce *pr, char *av, t_header *head);
void					full_command(t_parce *pr, char *str, int i);
char					*get_dir_ind
						(char *ar, t_code *begin, t_code *cur, int size);
char					*get_reg(char *ar);
char					*get_dir_ind
						(char *ar, t_code *begin, t_code *cur, int size);
char					*get_reg(char *ar);
char					*get_dir_ind
						(char *ar, t_code *begin, t_code *cur, int size);
void					get_code_args(t_parce *pr, int flag, char *str, int *i);
char					*replace_name(char *av, int size);
void					int32_to_bytecode
						(char *data, int32_t pos, int32_t value, size_t size);
void					full_code_size_neg(char *src, char *str, int temp);
void					full_code_size(char *src, char *str, int temp);
long long				ft_atoi_long_new(const char *str, int size);
int						get_label(char *ar, t_code *cur, t_code *begin);
void					measure_size(t_code *new, t_parce *pr);
void					measure_typeargs(t_code *new);
int						type_code_args(t_code *new);
char					*command(char *s);
t_list					*init_list(char *str);
void					ft_free(t_parce *pr);
void					ft_skip_space(t_parce *pr);
void					skip_comment(t_parce *pr);
void					print_line(t_list *list);
void					printt_code(t_code *cd);
void					print_code(char *str);
void					write_str(char *str, int fd);
int						ft_valid_value(const char *str, int size);
void					check_filename(char *name);
#endif
