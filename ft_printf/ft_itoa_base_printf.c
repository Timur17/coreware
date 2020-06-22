/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:05:41 by skrystin          #+#    #+#             */
/*   Updated: 2020/06/19 10:28:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_helpitoa(uintmax_t value, uintmax_t base,
uintmax_t len, uintmax_t nbr)
{
	char		*res;
	char		*basestr;

	basestr = "0123456789abcdef";
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	if (nbr == ULLONG_MAX && base == 8)
		return (res = "1777777777777777777777");
	if (nbr == ULLONG_MAX && base == 16)
		return (res = "ffffffffffffffff");
	while (nbr)
	{
		res[--len] = basestr[nbr % base];
		nbr = nbr / base;
	}
	return (res);
}

char			*ft_itoa_base_printf(uintmax_t value, long int base)
{
	uintmax_t		len;
	uintmax_t		nbr;

	if (!value)
		return ("0");
	nbr = value;
	len = 0;
	while (nbr)
	{
		nbr = nbr / base;
		len++;
	}
	nbr = value;
	return (ft_helpitoa(value, base, len, nbr));
}
