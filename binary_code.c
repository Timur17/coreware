#include "asm.h"

char    *replace_name(char *av, int size)
{
  char *name;

  name = ft_strnew(size + 2);
  ft_strncpy(name,av, size -1);
  name[size - 1] = 'c';
  name[size++] = 'o';
  name[size] = 'r';
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
        //  printf("--------------------\n");
        //  printf("%s\n", str);
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
  {
    get_code_args(pr, 1, str, &i);
  }
  if (cur->ar2)
  {
    get_code_args(pr, 2, str, &i);
  }
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
 //   printf("test1\n");
//    printf("------%s %s %s %s\n", cur->cmnd, cur->ar1, cur->ar2, cur->ar3);
     if (cur->cmnd)
    {
      // if (ft_strnequ(cur->cmnd, "ld", 2) && ft_strnequ(cur->ar1, "-186", 4) && ft_strnequ(cur->ar2, "r14", 3))
      // {
    cpy = get_code(cur, pr);
    // printf("test111111111111\n");
    // printf("------%s\n", cpy);
    ft_memcpy(str + i, cpy, ft_strlen(cpy));
    i += (int)ft_strlen(cpy);
      // printf("------%s\n", cpy);
    free (cpy);
      // exit (0);
    //}
    
    }
  cur = cur->next;
  }
}

char    *transform(t_parce *pr, header_t *head)
{
    char *str;

    str = ft_strnew(4384 + (pr->size_code * 2));
    ft_memset(str, '0', 4384 + (pr->size_code * 2));
    printf("test\n");


    pr->leak = ft_itoa_base(head->magic, 16);
    ft_memcpy(str + 2, pr->leak, 6);
    free (pr->leak);
    
    full_name_coment(pr, head->prog_name, str, 8);
    

    pr->leak = ft_itoa_base(pr->size_code, 16);
    full_code_size(pr->leak, str, 279);
    free (pr->leak);


    full_name_coment(pr, head->comment, str, 280);
    full_command(pr, str, 4384);
    ft_putstr_fd(str, pr->fd);
    return (str);
}

void    binary_code(t_parce *pr, char *av, header_t *head)
{
  char  *name;
  char  *str;


  name = replace_name(av, ft_strlen(av));
  if ((pr->fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	 	ft_error("Can't create file");
  // printf ("fd=%d %s\n", fd, name);
  str = transform(pr, head);
  print_code(str);
  //  write_str(str, pr->fd);
  // ft_putstr_fd(str, pr->fd);
  free (str);
  free (name);
  // if (close(pr->fd))
	//  	ft_error("Can't close file");
}

