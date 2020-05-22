#include "asm.h"

void    full_code_size(char *src, char *str, int temp)
{
  int    len;

  len = (int)ft_strlen(src);
  len--;
  while(len >= 0)
    str[temp--] = src[len--];
 // free (src);
}

void    ft_change(char *add)
{
  int i;

  i = 0;
  while (add[i])
  {
    if (add[i] == '0')
      add[i] = '1';
    else
      add[i] = '0';
    i++;
  }
}

char    *additinal_code(char *src, int size)
{
  char  *add;

  add = ft_strnew(size * 8);
  ft_memset(add, '0', size * 8);
  full_code_size(src, add, (size * 8) - 1);
  ft_change(add);
  return (add);
}

void    full_code_size_neg(char *src, char *str, int size)
{
  char *add;
  unsigned long   dec;
  char  *oct;

    // printf ("str %s %d\n", str, size);
    // printf ("src %s\n", src);
  add = additinal_code(src, size);
  //  printf ("add %s\n", add);
  dec = ft_atoi_base(add, 2) + 1;
  //  printf ("dec %ld\n", dec);
  oct = ft_itoa_base_long(dec, 16);
  //  printf ("oct %s\n", oct);
  full_code_size(oct, str, (size * 2) - 1);
    // printf ("str %s\n", str);
    // exit (0);
  free(add);
  free(src);
  free(oct);
}

char    *get_code_arg(char *type, char *ar, t_parce *pr)
{
  char  *str;
  int   size;

  str = NULL;
  if (!(ft_strcmp(type, REG)))
  {
    return (get_reg(ar + 1));
  }
  else
  {
  if (ft_strequ(type, DIR) == 1)
    size = pr->cure->size_dir;
  else
    size = 2;
  str = get_dir_ind(ar, pr->cd, pr->cure, size);
  return (str);
  }
  return (str);
}

void    choose_flag(char **ar, char **type, int flag, t_code *cur)
{
  if (flag == 1)
  {
    *ar = cur->ar1;
    *type = cur->type_ar1;
  }
  else if (flag == 2)
  {
    *ar = cur->ar2;
    *type = cur->type_ar2;
  }
  else
  {
    *ar = cur->ar3;
    *type = cur->type_ar3;
  }
}

void    get_code_args(t_parce *pr, int flag, char *str, int *i)
{
  char  *ar;
  char  *type;
  char  *cpy;

  choose_flag(&ar, &type, flag, pr->cure);
  cpy = get_code_arg(type, ar, pr);
  if (cpy == NULL)
    ft_error_label(ar, pr->cure->row);
  ft_memcpy(str + *i, cpy, ft_strlen(cpy));
  *i = *i + ft_strlen(cpy);
  free(cpy); // ошибка с файлом toto.s на 3 строке
}

