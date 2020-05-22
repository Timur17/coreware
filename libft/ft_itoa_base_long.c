/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:39:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/21 20:01:15 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      digit_len(long long num, int base, int len)
{
    while(num != 0)
    {
        num = num/base;
        len++;
    }
    return(len);
}

static  void    ft_transform(long long num, int base, int  len, char *str)
{
        while (num != 0)
        {
                if (num % base < 10)
                         str[len] = num % base + 48;
                else
                        str[len] = num % base + 'a' - 10;
                num = num / base;
                len--;
        }
}


char            *ft_itoa_base_long(long long value, int base)
{
        char *str;
        int len = 0;
        int     sign = 0;

        if (value == 0)
        {
                str = ft_strnew(1);
                ft_memset(str, '0', 1);
                return(str);
        }
        if(base == 10 && value < 0)
        {
                value =  value * (-1);
                len++;
                sign = -1;
        }
        len = digit_len(value, base, len);
        // if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL); //sega
        //         return (NULL);
        str = (char *)malloc(sizeof(char) * (len + 1));
        str[len--] = '\0';
        ft_transform(value, base, len, str);
        if(base == 10 && sign == -1)
                str[0] = '-';
        return(str);
}