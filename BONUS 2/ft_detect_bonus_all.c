/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_bonus_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:05 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 22:57:36 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putstr(char *str,int *count)
{
    int i;

    i = 0;
    if(!str)
    {
        *count += write(1,"(null)",6);
        return ;
    }
    while(str[i])
    {
        *count += write(1,&str[i],1);
        i++;
    }
    return ;
}

void ft_detect_bonus(va_list hub,char **str,int *count,int r)
{
	if(*(*str) == 'x' || *(*str + 1) == 'X')
		ft_detect1_bonus(hub,*str,count,r);
	else if(*(*str) == 'd' || *(*str + 1) == 'i')
		ft_detect2_bonus(hub,*str,count,r);
	else if(*(*str) == 's')
		ft_detect3_bonus(hub,count,r);
	(*str)++;
}

void ft_detect1_bonus(va_list hub,char *str, int *count,int r)
{
	unsigned int a;
	a = va_arg(hub,unsigned long);
	if(r > 0)
		ft_calc_width_unsign(a,r,count);
	if(*(str) == 'x')
	{
		if(a != 0)
			*count += write(1,"0x",2);
		cal(16,a,"0123456789abcdef",count);
	}
	else
	{
		if(a != 0)
			*count += write(1,"0X",2);
		cal(16,a,"0123456789ABCDEF",count);
	}
}

void ft_detect2_bonus(va_list hub, char *str ,int *count,int r)
{
	int a;
	a = va_arg(hub,int);
	if(r > 0 && *(str - ft_size_int(r) - 1) == '+')
		ft_calc_width_int(a,r - 1,count);
	else
		ft_calc_width_int(a,r,count);
	if(a >= 0 && *(str - ft_size_int(r) - 1) == '+')
		*count += write(1,"+",1);
	/*else if(a >= 0 && *(str - 1) == ' ')
		*count += write(1," ",1);*/
	cal_int(10,a,"0123456789",count);
}

void ft_detect3_bonus(va_list hub, int *count,int r)
{
	char *a;
	a = va_arg(hub,char *);
	if(r > 0)
		ft_calc_width_str(a,r,count);
	ft_putstr(a,count);
}
