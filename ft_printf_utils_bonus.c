/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:48 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 22:36:54 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_detect1_width(va_list hub, char *str,int *count,int r)
{
    if(*(str) == 'c')
    {
        char a;
        a = va_arg(hub,int);
        if(r > 0)
            ft_print_space(r - 1,count);
        *count += write(1,&a,1);
    }
    else if(*(str) == 'd' || *(str) == 'i')
    {
        int a;
        a = va_arg(hub,int);
        if(r > 0)
            ft_calc_width_int(a,r,count);
        cal_int(10,a,"0123456789",count);
    }
}

void ft_detect2_width(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        if(r > 0)
            ft_str_space(a,r,count);
        ft_putstr(a,count);
    }
    else if(*(str) == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(r > 0)
            ft_calc_width_unsign_int(a,r,count);
        cal(10,a,"0123456789",count);
    }
    else if(*(str) == '%')
    {
        if(r > 0)
            ft_print_space(r - 1,count);
        *count += write(1,"%",1);
    }
}

void ft_detect3_width(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 'p')
    {
        unsigned long a;
        a = va_arg(hub,unsigned long);
        if(r > 0)
            ft_calc_width_unsign_longr(a,r - 2,count);
        *count += write(1,"0x",2);
        cal(16,a,"0123456789abcdef",count);
    }
    else
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(r > 0)
            ft_calc_width_unsign(a,r,count);
        if(*(str) == 'x')
            cal(16,a,"0123456789abcdef",count);
        else if(*(str) == 'X')
            cal(16,a,"0123456789ABCDEF",count);
    }
}

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

void    cal_int(long int n,long int nb,char *base,int *count)
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
