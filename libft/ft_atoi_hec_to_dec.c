/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hec_to_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 17:01:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_helper(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else
		return (15);
}

long long		ft_atoi_hec_to_decimal(char *str)
{
	long long	num;
	int			len;
	long long	res;
	int			i;

	i = 0;
	res = 0;
	num = 1;
	len = ft_strlen(str) - 1;
	while (0 <= len)
	{
		if ((str[len] >= 'a' && str[len] <= 'f') ||
		(str[len] >= 'A' && str[len] <= 'F'))
			num = ft_helper(str[len]) * ft_degree(16, i);
		else
			num = (str[len] - 48) * ft_degree(16, i);
		res += num;
		len--;
		i++;
	}
	return (res);
}
