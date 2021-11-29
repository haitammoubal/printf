/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_zero_dot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:13:52 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/27 19:38:56 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_minus_zero_dot(va_list hub,char **str,int *count,int max_width)
{
	int r;

	r = 0;
	while(*(*str) == '0' || *(*str) == '-' || *(*str) == '.')
		*(*str)++;
	if(*(*str) >= '0' && *(*str) <= '9')
		r = ft_width(str);
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_minus_zero_dot1(hub,*str,count,r);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_minus_zero_dot2(hub,*str,count,r);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_minus_zero_dot2(hub,*str,count,r);
}
void    ft_minus_zero_dot1(va_list hub, char *str,int *count,int r)
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

void ft_minus_zero_dot2(va_list hub,char *str,int *count,int r)
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
            ft_calc_width_int_zero(a,r,count);
        cal(10,a,"0123456789",count);
    }
    else if(*(str) == '%')
    {
        if(r > 0)
            ft_print_zero(r - 1,count);
        *count += write(1,"%",1);
    }
}

void ft_minus_zero_dot3(va_list hub,char *str,int *count,int r)
{
    if(*(str) == 'p')
    {
        int k = 0;
        k = ft_size_int(r);
        unsigned long a;
        a = va_arg(hub,unsigned long);
        *count += write(1,"0x",2);
        if(r > 0)
            ft_calc_width_unsign_long_zero(a,r,count);
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
