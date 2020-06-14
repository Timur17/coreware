/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/09 20:31:14 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned long long ft_degree(int num, int degree)
{
  unsigned long long res = 1;
  if (num == 0)
    return (0);
  if (degree == 0)
    return (1);
  while (degree > 0)
  {
    res = res * num;
    degree--;
  }
  return (res);
}

int ft_helper(char c)
{
  if (c == 'a' || c == 'A')
    return (10);
  else  if (c == 'b' || c == 'B')
    return (11);
  else  if (c == 'c' || c == 'C')
    return (12);
  else  if (c == 'd' || c == 'D')
    return (13);
  else  if (c == 'e' || c == 'E')
    return (14);
  else
    return (15);
}

long long ft_atoi_decimal(char *str)
{
  long long num;
  int len;
  long long res;
  int i;


  i = 0;
  res = 0;
  num = 1;
  len = ft_strlen(str) - 1;
  while (0 <= len)
  {
     if (str[len] >= 'a' && str[len] <= 'f' || str[len] >= 'A' && str[len] <= 'F')
       num = ft_helper(str[len]) * ft_degree(16, i);
     else
      num = (str[len] - 48) * ft_degree(16, i);
    res += num;
    len--;
    i++; 
  }
  return (res);
}

char    *replace_name(char *av, int size)
{
   char *name;

  name = ft_strnew(size + 2);
  ft_strncpy(name,av, size -1);
  name[size - 1] = 'c';
  name[size++] = 'o';
  name[size] = 'r';


  // name = ft_strnew(size + 3);
  // ft_strncpy(name,av, size - 2);
  // name[size - 2] = 'm';
  // name[size - 1] = '.';
  // name[size++] = 'c';
  // name[size++] = 'o';
  // name[size] = 'r';

  return (name);
}

void    full_name_coment(t_parce *pr, char *src, char *str, int temp)
{
  int   i;
  char  *num;

  *pr->i = temp;
  i = 0;
  num = NULL;
  while(src[i])
  {
    num = ft_itoa_base(src[i++], 16);
    if (num[0])
      str[(*pr->i)++] = num[0];
    if (num[1])
      str[(*pr->i)++] = num[1];
    free(num);
  }
}

char    *get_code(t_code *cur, t_parce *pr)
{
  char    *str;
  int     i;

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

void    full_command(t_parce *pr, char *str, int i)
{
  t_code  *cur;
  char    *cpy;

  cur = pr->cd;
  
  while (cur)
  {
     if (cur->cmnd)
    {
    cpy = get_code(cur, pr);
    ft_memcpy(str + i, cpy, ft_strlen(cpy));
    i += (int)ft_strlen(cpy);
    free (cpy);   
    }
  cur = cur->next;
  }
}

void	write_bytes(int fd, __uintmax_t num, u_int8_t bytes)
{
	if (bytes >= 8)
		ft_putchar_fd(((num >> 56) & 0xFF), fd);
	if (bytes >= 7)
		ft_putchar_fd(((num >> 48) & 0xFF), fd);
	if (bytes >= 6)
		ft_putchar_fd(((num >> 40) & 0xFF), fd);
	if (bytes >= 5)
		ft_putchar_fd(((num >> 32) & 0xFF), fd);
	if (bytes >= 4)
		ft_putchar_fd(((num >> 24) & 0xFF), fd);
	if (bytes >= 3)
		ft_putchar_fd(((num >> 16) & 0xFF), fd);
	if (bytes >= 2)
		ft_putchar_fd(((num >> 8) & 0xFF), fd);
	if (bytes >= 1)
		ft_putchar_fd((num & 0xFF), fd);
}

void	int32_to_bytecode(char *data,
							int32_t pos,
							int32_t value,
							size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (u_int8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void command_to_byte(char *str, char *bytecode, int pos)
{
  char *new; 
  int i;
  int dec;

  i = 0;
  while (str[i])
{
  new = ft_strnew(2);
  new[0] = str[i];
  new[1] = str[i + 1];
  i = i + 2;
  dec = ft_atoi_decimal(new);
  int32_to_bytecode(bytecode, pos++, dec, 1);
  free(new);
}
 
 
}

char    *transform(t_parce *pr, header_t *head, char *av)
{

  int32_t	len;
	int32_t	pos;
	char	*bytecode;
  char *str;

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
  pos = pos + COMMENT_LENGTH + 4;//COMMENT_LENGTH + 4; //948 
  str = ft_strnew(pr->size_code * 2);
  ft_memset(str, '0', pr->size_code * 2);
  full_command(pr, str, 0);
  command_to_byte(str, bytecode, pos);
  free (str);
  return (bytecode);
}

void    binary_code(t_parce *pr, char *av, header_t *head)
{
  //  long d =  (unsigned)-9223372036854775;
  // printf("%ld\n", d);
  // exit(0);
    char  *name;
    char  *bytecode;

    int len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + pr->size_code;

    bytecode = transform(pr, head, av);


  name = replace_name(av, ft_strlen(av));
  if ((pr->fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	 	ft_error("Can't create file");
  
  write(pr->fd, bytecode, len);
 // printf("%s %s\n", "Writing output program to", name);  

    //write_str(str, pr->fd);
    if (close(pr->fd))
	  	ft_error("Can't close file");
  // free (str);
  printf("%s %s\n", "Writing output program to", name);  
  free (name);
  free (bytecode);

 //   return (str);
     
 // print_code(str);

}

