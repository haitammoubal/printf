/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:00:22 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 17:15:26 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_sep2_bonus(va_list hub,char *str,int *i,int *count)
{
	while(str[*i + 1] == ' ' || str[*i + 1] == '#' || str[*i + 1] == '+')
		(*i)++;
	while(str[*i + 1] >= '0' && str[*i + 1] <= '9')
		(*i)++;
	ft_detect_bonus(hub,str,i,count);
}

void ft_sep(va_list hub,char *str, int *i,int *count)
{
	if(str[*i + 1] == 'c' || str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_detect1(hub,str,i,count);
	else if(str[*i + 1] == 's' || str[*i + 1] == 'u' || str[*i + 1] == '%')
		ft_detect2(hub,str,i,count);
	else if(str[*i + 1] == 'p' || str[*i + 1] == 'x' || str[*i + 1] == 'X')
		ft_detect3(hub,str,i,count);
	(*i)++;
}

int ft_printf(const char *str, ...)
{
    va_list hub;
    int     i;
    int     count;

    i = 0;
    count = 0;
    va_start(hub,str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            if(str[i + 1] == ' ' || str[i + 1] == '#' || str[i + 1] == '+')
                ft_sep2_bonus(hub,(char *)str,&i,&count);
            else
                ft_sep(hub,(char *)str,&i,&count);
        }
        else
            count += write(1,&str[i],1);
        i++;
    }
    va_end(hub);
    return(count);
}
