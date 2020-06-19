/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/18 23:47:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

	unsigned int			g_i;
	unsigned long long		g_num;

void						check_filename(char *name)
{
	int						len;

	len = ft_strlen(name);
	if (len < 2 || name[len - 1] != 's' || name[len - 2] != '.')
		ft_error("ERROR: file extension is wrong");
}

char						*replace_name(char *av, int size)
{
	char					*name;

	name = ft_strnew(size + 2);
	ft_strncpy(name, av, size - 1);
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

void						int32_to_bytecode(char *data, int32_t pos,
							int32_t value, size_t size)
{
	int8_t					i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (u_int8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

long			ft_change_size(long long num, int size, int neg)
{
	long long				res;

	if (size == 4)
		res = (unsigned)(num * neg);
	if (size == 2)
		res = (unsigned short)(num * neg);
	return (res);
}

long long		ft_atoi_long_new(const char *str, int size)
{
	int						neg;

	g_i = 0;
	g_num = 0;
	neg = 1;
	while ((str[g_i] >= 9 && str[g_i] <= 13) || str[g_i] == ' ')
		g_i++;
	if (str[g_i] == '-' || str[g_i] == '+')
		if (str[g_i++] == '-')
			neg = (-1) * neg;
	while (str[g_i] >= '0' && str[g_i] <= '9')
	{
		g_num = g_num * 10 + (str[g_i] - 48);
		g_i++;
		if (g_num > 9223372036854775807)
		{
			if (neg == -1)
				return (0);
			g_num = 9223372036854775807;
			break ;
		}
	}
	if ((size == 2 && g_num > 65535) || (size == 4 && g_num > 4294967295))
		return (ft_change_size(g_num, size, neg));
	return (g_num = g_num * neg);
}
