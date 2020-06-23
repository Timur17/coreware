/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinstr_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:35:21 by wtorwold          #+#    #+#             */
/*   Updated: 2020/06/22 23:54:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*joinstr_free(char *s1, char *s2)
{
	char *str;

	if ((str = ft_strjoin(s1, s2)) == NULL)
	{
		ft_putstr("ERROR: allocate memory\n");
		exit(0);
	}
	free(s1);
	free(s2);
	return (str);
}
