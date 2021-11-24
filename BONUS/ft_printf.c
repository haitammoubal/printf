/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:28 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 17:13:36 by hmoubal          ###   ########.fr       */
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
            ft_sep(hub,(char *)str,&i,&count);
        else
            count += write(1,&str[i],1);
        i++;
    }
    va_end(hub);
    return(count);
}
// int main()
// {
//     ft_printf("%d",5);
// }
