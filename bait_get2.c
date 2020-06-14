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

long ft_change_size(long long num, int size, int neg)
{
  long long res;

  //printf("size %d num %lld\n", size, num);
  if (size == 4)
    res = (unsigned)(num * neg);
  if (size == 2)
    res = (unsigned short)(num * neg);
  // printf("end %lld\n",res);
  // exit (0);
  return (res);
}

long long		ft_atoi_long_new(const char *str, int size)
{
	unsigned int			i;
	int						neg;
	unsigned long long		num;
  long long int max = 922337203685477580;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = (-1) * neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
    if (num > 9223372036854775807)
    {
       if (neg == -1)
         return (0);
			num = 9223372036854775807;
   //   printf("2 %lld\n", num);
      break;
    }
    // else  if ((num > max || (num == max && str[i] - '0' > 7)) && neg == -1)
    // {
		// 	num = -9223372036854775807;
    //   break;
    // }
   // printf("1 %lld\n", num);
	}
  if ((size == 2 && num > 65535) || (size == 4 && num > 4294967295))
   return (ft_change_size(num, size, neg));
	return (num = num * neg);
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
    // if (ft_valid_value(ar, size))
    // {
    //   printf("ERROR: overflow value %s in %s at row %d\n", ar, cur->cmnd, cur->row);
    //   exit (0);
    // }
    // num = ft_atoi_long(ar);
    num = ft_atoi_long_new(ar, size);
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
