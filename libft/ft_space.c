/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:39:02 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 23:55:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
