#include "asm.h"
#define MAX 922337203685477580

int		ft_valid_value(const char *str, int size)
{
    unsigned long long max;
    unsigned long long num;
    int          i;

    num = 0;
    i = 0;
    if (str[0] == '-')
      i++;
    if (size == 2)
        max = 65535;
    else if (size == 4)
        max = 4294967295;
    else
        return (1);
    while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if (num > max)    
			return (1);
	}
    return (0);
}

void    print_code(char *str)
{
  int i;
  int f;

  i = 0;
  f = 0;
  while (str[i] && str[i + 1] && str[i + 2] && str[i + 3])
  {
    if (f == 8)
    {
      printf("\n");
      f = 0;
    }
    printf("%c", str[i++]);
    printf("%c", str[i++]);
    printf("%c", str[i++]);
    printf("%c", str[i++]);
    if (f < 7)
    printf(" ");
    f++;
  }
      if (f == 8)
      printf("\n");
  printf("%s\n", str + i);
}

void            write_str(char *str, int fd)
{
  int   i = 0;
  int   f = 0;
  char  n = '\n';

    while (str[i] && str[i + 1] && str[i + 2] && str[i + 3])
  {
    if (f == 8)
    {
      ft_putchar_fd(n, fd);
      f = 0;
    }
    ft_putchar_fd(str[i++], fd);
    ft_putchar_fd(str[i++], fd);
    ft_putchar_fd(str[i++], fd);
    ft_putchar_fd(str[i++], fd);
    if (f < 7)
    ft_putchar_fd(' ', fd);
    f++;
  }
  if (f == 8)
  ft_putchar_fd(n, fd);
  ft_putstr_fd(str + i, fd);
}


void						print_line(t_list *list)
{
	t_list		*temp;

	temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

void	printt_code(t_code *cd)
{
	t_code	*temp;

	temp = cd;
	while (temp)
	{
		printf("%s %s row = %d\n", temp->label, temp->cmnd, temp->row);
		printf("ar1=%s ar2=%s ar3=%s\n", temp->ar1, temp->ar2, temp->ar3);
		printf("t_ar1=%s t_ar2=%s t_ar3=%s\n", temp->type_ar1, temp->type_ar2, temp->type_ar3);
		printf("size=%d type_args=%s %d\n", temp->size, temp->type_args, temp->size_dir);
		printf("-------\n");
		temp = temp->next;
	}
}	
