/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:59:47 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/20 13:59:51 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_putstr(char *str,int *count)
{
    int i;

    i = 0;
    if(!str)
    {
        *count += write(1,"(null)",6);
        return ;
    }
    while(str[i])
    {
        *count += write(1,&str[i],1);
        i++;
    }
    return ;
}
