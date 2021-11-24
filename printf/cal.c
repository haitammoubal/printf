/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:00:22 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/20 14:00:26 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


void cal(unsigned long n,unsigned long  nb,char *base,int *count)
{
    if(nb < 0)
    {
        *count += write(1,"-",1);
        nb = -1 * nb;
    }
    if(nb >= n)
        cal(n,nb / n,base,count);
    *count += write(1,base + (nb % n) , 1);
}
