/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_dotzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:37:13 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/29 01:31:15 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_bonus_dotzero(va_list hub,char **str,int *count,int *max_width)
{
	if(*(*str) >= '0' && *(*str) <= '9')
		max_width[1] = ft_width(str);
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_bonus2_dotzero(hub,*str,count,max_width);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_bonus2_dotzero(hub,*str,count,max_width);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_bonus2_dotzero(hub,*str,count,max_width);
}

void    ft_detect1_bonus2_dotzero(va_list hub, char *str,int *count,int *max_width)
{
    if(*(str) == 'c')
    {
        char a;
        a = va_arg(hub,int);
        if(max_width[1] > 0)
            ft_print_zero(max_width[1] - 1,count);
        *count += write(1,&a,1);
    }
    else if(*(str) == 'd' || *(str) == 'i')
    {
        long int a;
        a = va_arg(hub,int);
        if(a == 0)
        {
            ft_print_zero(max_width[1],count);
            if(max_width[0] > max_width[1])
                ft_print_space(max_width[0],count);
            return ;
        }
        else if(a > 0)
        {
            if(max_width[1] > ft_size_int(a) && max_width[0] > max_width[1])
                ft_print_space(max_width[0] - max_width[1],count);
            else if(max_width[1] < ft_size_int(a) && max_width[0] > max_width[1])
                ft_print_space(max_width[0] - ft_size_int(a),count);
            ft_calc_width_int_zero(a,max_width[1],count);
            cal_int(10,a,"0123456789",count);
        }
		else if(a < 0)
		{
            if(max_width[1] > ft_size_int(a))
                ft_print_space((max_width[0] - max_width[1] - 1),count);
            else if(max_width[1] <= ft_size_int(a))
                ft_print_space((max_width[0] - ft_size_int(a)),count);
			*count += write(1,"-",1);
			a = -a;
			ft_calc_width_int_zero(a,max_width[1],count);
            cal_int(10,a,"0123456789",count);
		}
    }
}

void ft_detect2_bonus2_dotzero(va_list hub,char *str,int *count,int *max_width)
{
    if(*(str) == 's')
    {
        char *a;
        a = va_arg(hub,char *);
        if(max_width[1] > 0 && max_width[0] > 0)
        {
            ft_calc_width_str_zero_dot(a,max_width,count);
            ft_putstr_dot(a,count,max_width[1]);
        }
        else if(max_width[1] == 0 && max_width[0] == 0)
            return ;
    }
    else if(*(str) == 'u')
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(a == 0)
        {
            if(max_width[0] > max_width[1])
                ft_print_space(max_width[0],count);
            ft_print_zero(max_width[1],count);
            return ;
        }
        if(a > 0)
        {
            if(max_width[1] > ft_size_int(a) && max_width[0] > max_width[1])
                ft_print_space(max_width[0] - max_width[1],count);
            else if(max_width[1] < ft_size_int(a) && max_width[0] > max_width[1])
                ft_print_space(max_width[0] - ft_size_int(a),count);
            ft_calc_width_int_zero(a,max_width[1],count);
            cal_int(10,a,"0123456789",count);
        }
    }
    else if(*(str) == '%')
    {
        if(max_width[0] > 0)
            ft_print_zero(max_width[0] - 1,count);
        *count += write(1,"%",1);
    }
}

void ft_detect3_bonus2_dotzero(va_list hub,char *str,int *count,int *max_width)
{
    if(*(str) == 'p')
    {
        unsigned long a;
        a = va_arg(hub,unsigned long);
        if(max_width[0] == 0 && max_width[1] == 0)
        {
            *count += write(1,"0x",2);
            cal(16,a,"0123456789abcdef",count);
        }
        else if(max_width[1] > 0 && max_width[0] > max_width[1])
        {
            ft_print_space(max_width[0] - 2,count);
            *count += write(1,"0x",2);
            ft_calc_width_unsign_long_space(a,max_width,count);
            cal(16,a,"0123456789abcdef",count);
        }
        else if(max_width[0] > 0 && max_width[0] < max_width[1])
        {
            *count += write(1,"0x",2);
            ft_calc_width_unsign_long_space(a,max_width,count);
            cal(16,a,"0123456789abcdef",count);
        }
    }
    else
    {
        unsigned int a;
        a = va_arg(hub,unsigned int);
        if(a == 0)
        {
            if(max_width[0] > max_width[1])
                ft_print_space(max_width[0],count);
            ft_print_zero(max_width[1],count);
            return ;
        }
        if(a > 0)
        {
            if(max_width[1] > ft_size_hex(a) && max_width[0] > max_width[1])
                ft_print_space(max_width[0] - max_width[1],count);
            else if(max_width[1] < ft_size_hex(a) && max_width[0] > max_width[1])
                ft_print_space(max_width[0] - ft_size_hex(a),count);
            ft_calc_width_unsign_zero(a,max_width[1],count);
            if(*(str) == 'x')
                cal(16,a,"0123456789abcdef",count);
            else if(*(str) == 'X')
                cal(16,a,"0123456789ABCDEF",count);
        }
    }
}
