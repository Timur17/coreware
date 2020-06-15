/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:39:02 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/15 23:52:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdel_char(char *str, char c)
{
	size_t		len;
	int			i;
	char		*new;

	new = NULL;
	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == c)
			len--;
		i++;
	}
	new = ft_strnew(len);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			new[len++] = str[i];
		i++;
	}
	ft_strdel(&str);
	return (new);
}
