/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_degree(int num, int degree)
{
	unsigned long long res;

	res = 1;
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
