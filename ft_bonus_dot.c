/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:14 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/29 01:37:11 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_bonus_dot(va_list hub, char **str,int *count,int *max_width)
{
	while(*(*str) == '.')
		(*str)++;
	if(*(*str) >= '0' && *(*str) <= '9')
		max_width[1] = ft_width(str);
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_bonus2_dot(hub,*str,count,max_width);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_bonus2_dot(hub,*str,count,max_width);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_bonus2_dot(hub,*str,count,max_width);
}
void    ft_detect1_bonus2_dot(va_list hub, char *str,int *count,int *max_width)
{
    if(*(str) == 'c')
    {
        char a;
        a = va_arg(hub,int);
        if(max_width[0] > 0)
            ft_print_space(max_width[0] - 1,count);
        *count += write(1,&a,1);
    }
    else if(*(str) == 'd' || *(str) == 'i')
    {
        long int a;
        a = va_arg(hub,int);
        if(a == 0)
        {
            ft_print_zero(max_width[1],count);
            return ;
        }
        if(a > 0)
        {
            if(max_width[0] > max_width[1])
                ft_print_space_presi(max_width,count,a);
            ft_calc_width_int_zero(a,max_width[1],count);
        }
		else if(a < 0)
		{
            if(max_width[0] > max_width[1])
                ft_print_space_presi(max_width,count,a);
			*count += write(1,"-",1);
			a = -a;
            ft_calc_width_int_zero(a,max_width[1],count);
		}
        cal_int(10,a,"0123456789",count);
    }
}

void ft_detect2_bonus2_dot(va_list hub,char *str,int *count,int *max_width)
{
    if(*(str) == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        if(max_width[0] > 0)
            ft_print_space(max_width[0] - max_width[1],count);
        ft_putstr_dot(a,count,max_width[1]);
    }
    else if(*(str) == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(a == 0)
        {
            ft_print_zero(max_width[1],count);
            return ;
        }
        if(max_width[0] > max_width[1])
            ft_print_space_presi(max_width,count,a);
        if(max_width[1] > 0)
            ft_calc_width_unsign_zero2(a,max_width[1],count);
        cal(10,a,"0123456789",count);
    }
    else if(*(str) == '%')
    {
        if(max_width[0] > 0)
            ft_print_space(max_width[0] - 1,count);
        *count += write(1,"%",1);
    }
}

void ft_detect3_bonus2_dot(va_list hub,char *str,int *count,int *max_width)
{
    if(*(str) == 'p')
    {
        unsigned long a;
        a = va_arg(hub,unsigned long);
        if(max_width[0] > max_width[1])
        {
            max_width[0] = max_width[0] - 2;
            ft_print_space_presi_hex(max_width,count,a);
        }
        *count += write(1,"0x",2);
        if(max_width[1] > 0)
            ft_calc_width_unsign_long_zero(a,max_width[1],count);
        cal(16,a,"0123456789abcdef",count);
    }
    else
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(a == 0)
        {
            ft_print_zero(max_width[1],count);
            return ;
        }
        if(max_width[0] > max_width[1])
            ft_print_space_presi_hex(max_width,count,a);
        if(max_width[1] > 0)
            ft_calc_width_unsign_zero(a,max_width[1],count);
        if(*(str) == 'x')
            cal(16,a,"0123456789abcdef",count);
        else if(*(str) == 'X')
            cal(16,a,"0123456789ABCDEF",count);
    }
}
