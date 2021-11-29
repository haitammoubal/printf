/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:48:42 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 23:02:44 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putstr_dot(char *str,int *count, int r)
{
    int i;

    i = 0;
    if(!str && r > 6)
    {
        *count += write(1,"(null)",6);
        return ;
    }
    else if (!str)
    {
        *count += write(1,"(null)",r);
        return ;
    }
    while(str[i] && r)
    {
        *count += write(1,&str[i],1);
		r--;
        i++;
    }
    return ;
}
