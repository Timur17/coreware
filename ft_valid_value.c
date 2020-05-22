/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:22:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/03 17:14:49 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_valid_value(const char *str, int size)
{
    unsigned long long max;
    unsigned long long num;
    int          i;

    i = 0;
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









	// unsigned int			i;
	// int						neg;
	// unsigned long long		num;

	// i = 0;
	// num = 0;
	// neg = 1;
	// while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	// 	i++;
	// if (str[i] == '-' || str[i] == '+')
	// {
	// 	if (str[i] == '-')
	// 		neg = (-1) * neg;
	// 	i++;
	// }
	// while (str[i] >= '0' && str[i] <= '9')
	// {
	// 	num = num * 10 + (str[i] - 48);
	// 	i++;
	// 	if ((num > MAX || (num == MAX && str[i] - '0' > 7)) && neg == 1)
	// 		return (-1);
	// 	if ((num > MAX || (num == MAX && str[i] - '0' > 7)) && neg == -1)
	// 		return (0);
	// }
	// return (num * neg);
}
