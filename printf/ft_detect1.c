/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:57:15 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/22 21:23:35 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void    ft_detect1(va_list hub, char *str, int *count,int *i)
{
    if(str[*i + 1] == 'c')
    {
        char a;
        a = va_arg(hub,int);
        *count += write(1,&a,1);
    }
    else if(str[*i + 1] == 'd' || str[*i + 1] == 'i')
    {
        int a;
        a = va_arg(hub,int);
        cal_int(10,a,"0123456789",count);
    }
}
