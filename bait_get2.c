#include "asm.h"

char    *get_reg(char *ar)
{
  char  *str;
  int   len;
  int   len_2;
  char   *type;

  type = ft_itoa_base(ft_atoi(ar), 16);
  len_2 = 1;
  len = (int)ft_strlen(type) - 1; 
  str = ft_memset(ft_strnew(2), '0', 2);
  while (len >= 0)
    str[len_2--] = type[len--];
  free (type);
  return (str);
}

int     get_label_neg(char *ar, t_code *cur, t_code *begin)
{
    int   size;
    t_code *temp;

    size = 0;
    temp = begin;
    while (temp)
  {
    if (ft_strequ(ar, temp->label))
        break ;
    temp = temp->next;
  }
    while (temp != cur && temp)
  {
    
    size = size + temp->size;
    temp = temp->next;
    if (temp == cur)
      return (size * (-1));
  }
  return (-1);
}

int     get_label(char *ar, t_code *cur, t_code *begin)
{
  int   size;
  t_code *temp;

  size = 0;
  temp = cur;
  while (temp)
  {
    if (ft_strequ(ar, temp->label))
      return (size);
    size = size + temp->size;
    temp = temp->next;
  }
  size = get_label_neg(ar, cur, begin);
    return (size);
}

char    *get_dir_ind(char *ar, t_code *begin, t_code *cur, int size)
{
  char          *str;
  long long     num;
  char          *leak;
 
  num = 0;
  if (ar[0] == LABEL_CHAR)
  {
    num = get_label(ar + 1, cur, begin);
    if (num == -1)
      return (NULL);
  }
  else
  {
    if (ft_valid_value(ar, size))
    {
      printf("ERROR: overflow value %s in %s at row %d\n", ar, cur->cmnd, cur->row);
      exit (0);
    }
    num = ft_atoi_long(ar);
  }
  str = ft_strnew(size * 2);
  ft_memset(str, '0', size * 2);
  if (num >= 0)
  {
    leak = ft_itoa_base_long(num, 16);
    full_code_size(leak, str, (size * 2) - 1);
    free (leak);
  }
  else
  {
    num = num * (-1);
    full_code_size_neg(ft_itoa_base(num, 2), str, size);
  }
  return (str); 
}
