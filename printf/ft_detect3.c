/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:57:24 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 21:48:13 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_detect3(va_list hub,char *str,int *count,int *i)
{
    if(str[*i + 1] == 'p')
    {
        unsigned long a;
        a = va_arg(hub,unsigned long);
        *count += write(1,"0x",2);
        cal(16,a,"0123456789abcdef",count);
    }
    else if(str[*i + 1] == 'x')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        cal(16,a,"0123456789abcdef",count);
    }
    else if(str[*i + 1] == 'X')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        cal(16,a,"0123456789ABCDEF",count);
    }
}
