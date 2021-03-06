/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <wtorwold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:41:35 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/16 20:18:02 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putchar_help(char c, int *count)
{
	while ((*count)-- > 0)
		ft_putchar(c);
}
