/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:39:46 by wtorwold          #+#    #+#             */
/*   Updated: 2018/12/24 18:47:33 by wtorwold         ###   ########.fr       */
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
	while(str[i])
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
