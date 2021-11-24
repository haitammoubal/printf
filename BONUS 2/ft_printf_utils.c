/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:48 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 22:44:17 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_detect1(va_list hub, char *str,int *count)
{
    if(*(str) == 'c')
    {
        char a;
        a = va_arg(hub,int);
        *count += write(1,&a,1);
    }
    else if(*(str) == 'd' || *(str) == 'i')
    {
        int a;
        a = va_arg(hub,int);
        cal_int(10,a,"0123456789",count);
    }
}

void ft_detect2(va_list hub,char *str,int *count)
{
    if(*(str) == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        ft_putstr(a,count);
    }
    else if(*(str) == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        cal(10,a,"0123456789",count);
    }
    else if(*(str) == '%')
        *count += write(1,"%",1);
}

void ft_detect3(va_list hub,char *str,int *count)
{
    if(*(str) == 'p')
    {
        unsigned long a;
        a = va_arg(hub,unsigned long);
        *count += write(1,"0x",2);
        cal(16,a,"0123456789abcdef",count);
    }
    else if(*(str) == 'x')
    {
        unsigned int a;
        a = va_arg(hub,unsigned long);
        cal(16,a,"0123456789abcdef",count);
    }
    else if(*(str) == 'X')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
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
