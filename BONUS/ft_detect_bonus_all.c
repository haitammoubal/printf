/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_bonus_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:05 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 21:50:46 by hmoubal          ###   ########.fr       */
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

void ft_detect_bonus(va_list hub,char *str,int *i,int *count)
{
	if(str[*i + 1] == 'x' || str[*i + 1] == 'X')
		ft_detect1_bonus(hub,str,i,count);
	else if(str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_detect2_bonus(hub,str,i,count);
	else if(str[*i + 1] == 's')
		ft_detect3_bonus(hub,count);
	(*i)++;
}

void ft_detect1_bonus(va_list hub,char *str,int *i, int *count)
{
	unsigned int a;
	a = va_arg(hub,unsigned int);
	if(str[*i + 1] == 'x')
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

void ft_detect2_bonus(va_list hub, char *str, int *i ,int *count)
{
	int a;
	a = va_arg(hub,int);
	if(a >= 0 && str[*i] == '+')
		*count += write(1,"+",1);
	else if(a >= 0 && str[*i] == ' ')
		*count += write(1," ",1);
	cal_int(10,a,"0123456789",count);
}

void ft_detect3_bonus(va_list hub, int *count)
{
	char *a;
	a = va_arg(hub,char *);
	ft_putstr(a,count);
}
