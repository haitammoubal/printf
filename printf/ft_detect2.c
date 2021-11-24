/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:57:20 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/22 18:44:29 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_detect2(va_list hub,char *str,int *count,int *i)
{
    if(str[*i + 1] == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        ft_putstr(a,count);
    }
    else if(str[*i + 1] == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        cal(10,a,"0123456789",count);
    }
    else if(str[*i + 1] == '%')
        *count += write(1,"%",1);
}
