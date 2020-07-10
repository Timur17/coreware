/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bait_get2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/22 23:44:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_change(char *add)
{
	int			i;

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

char			*additinal_code(char *src, int size)
{
	char		*add;

	if ((add = ft_strnew(size * 8)) == NULL)
		ft_error("ERROR: allocate memory");
	ft_memset(add, '0', size * 8);
	full_code_size(src, add, (size * 8) - 1);
	ft_change(add);
	return (add);
}

void			full_code_size(char *src, char *str, int temp)
{
	int			len;

	len = (int)ft_strlen(src);
	len--;
	while (len >= 0)
		str[temp--] = src[len--];
}

void			full_code_size_neg(char *src, char *str, int size)
{
	char			*add;
	unsigned long	dec;
	char			*oct;

	add = additinal_code(src, size);
	dec = ft_atoi_base(add, 2) + 1;
	if ((oct = ft_itoa_base_long(dec, 16)) == NULL)
		ft_error("ERROR: allocate memory");
	full_code_size(oct, str, (size * 2) - 1);
	free(add);
	free(src);
	free(oct);
}

char			*get_dir_ind(char *ar, t_code *begin, t_code *cur, int size)
{
	char			*str;
	long long		num;
	char			*leak;

	num = 0;
	if (ar[0] == LABEL_CHAR)
	{
		num = get_label(ar + 1, cur, begin);
		if (num == -1)
			return (NULL);
	}
	else
		num = ft_atoi_long_new(ar, size);
	if ((str = ft_strnew(size * 2)) == NULL)
		ft_error("ERROR: allocate memory");
	ft_memset(str, '0', size * 2);
	if (num >= 0)
	{
		leak = ft_itoa_base_long(num, 16);
		full_code_size(leak, str, (size * 2) - 1);
		free(leak);
	}
	else
		full_code_size_neg(ft_itoa_base((num * (-1)), 2), str, size);
	return (str);
}
