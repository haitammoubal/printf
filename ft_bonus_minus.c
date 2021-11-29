/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:18 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 21:09:03 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_bonus_minus(va_list hub, char **str,int *count,int *max_width)
{
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_bonus2_minus(hub,*str,count,max_width[0]);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_bonus2_minus(hub,*str,count,max_width[0]);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_bonus2_minus(hub,*str,count,max_width[0]);
}
void    ft_detect1_bonus2_minus(va_list hub, char *str,int *count,int r)
{
    if(*(str) == 'c')
    {
        char a;
        a = va_arg(hub,int);
        *count += write(1,&a,1);
        if(r > 0)
            ft_print_space(r - 1,count);
    }
    else if(*(str) == 'd' || *(str) == 'i')
    {
        long int a;
        a = va_arg(hub,int);
        cal_int(10,a,"0123456789",count);
        if(r > 0)
            ft_calc_width_int_minus(a,r,count);
    }
}

void ft_detect2_bonus2_minus(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        ft_putstr(a,count);
        if(r > 0)
            ft_calc_width_str_minus(a,r,count);
    }
    else if(*(str) == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        cal(10,a,"0123456789",count);
        if(r > 0)
            ft_calc_width_int_minus(a,r,count);
    }
    else if(*(str) == '%')
    {
        *count += write(1,"%",1);
        if(r > 0)
            ft_print_space(r - 1,count);
    }
}

void ft_detect3_bonus2_minus(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 'p')
    {
        unsigned long a;
        a = va_arg(hub,unsigned long);
        *count += write(1,"0x",2);
        cal(16,a,"0123456789abcdef",count);
        if(r > 0)
            ft_calc_width_unsign_long_minus(a,r - 2,count);
    }
    else
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(*(str) == 'x')
            cal(16,a,"0123456789abcdef",count);
        else if(*(str) == 'X')
            cal(16,a,"0123456789ABCDEF",count);
        if(r > 0)
            ft_calc_width_unsign_minus(a,r,count);
    }
}
