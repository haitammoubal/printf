/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:43:51 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 21:45:41 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_bonus_zero(va_list hub, char **str,int *count,int max_width)
{
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_bonus2_zero(hub,*str,count,max_width);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_bonus2_zero(hub,*str,count,max_width);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_bonus2_zero(hub,*str,count,max_width);
}

void    ft_detect1_bonus2_zero(va_list hub, char *str,int *count,int r)
{
    if(*(str) == 'c')
    {
        char a;
        a = va_arg(hub,int);
        if(r > 0)
            ft_print_zero(r - 1,count);
        *count += write(1,&a,1);
    }
    else if(*(str) == 'd' || *(str) == 'i')
    {
        long int a;
        a = va_arg(hub,int);
        if(r > 0 && a >= 0)
            ft_calc_width_int_zero(a,r,count);
		else if(r > 0 && a < 0)
		{
			*count += write(1,"-",1);
			ft_calc_width_int_zero(a,r,count);
			a = -a;
		}
        cal_int(10,a,"0123456789",count);
    }
}

void ft_detect2_bonus2_zero(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        if(r > 0)
            ft_calc_width_str_zero(a,r,count);
        ft_putstr(a,count);
    }
    else if(*(str) == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(r > 0)
            ft_calc_width_unsign_longr_printzero(a,r,count);
        cal(10,a,"0123456789",count);
    }
    else if(*(str) == '%')
    {
        if(r > 0)
            ft_print_zero(r - 1,count);
        *count += write(1,"%",1);
    }
}

void ft_detect3_bonus2_zero(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 'p')
    {
        int k = 0;
        k = ft_size_int(r);
        unsigned long a;
        a = va_arg(hub,unsigned long);
        *count += write(1,"0x",2);
        if(r > 0)
            ft_calc_width_unsign_long_zero(a,r - 2,count);
        cal(16,a,"0123456789abcdef",count);
    }
    else
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(r > 0)
            ft_calc_width_unsign_zero(a,r,count);
        if(*(str) == 'x')
            cal(16,a,"0123456789abcdef",count);
        else if(*(str) == 'X')
            cal(16,a,"0123456789ABCDEF",count);
    }
}
