/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:00:22 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 22:54:33 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_width(char **str)
{
	int	r;

	r = 0;
	while (*(*str) >= 48 && *(*str) <= 57)
	{
		r = (r * 10) + (*(*str) - 48);
		(*str)++;
	}
	return (r);
}

void ft_sep_main(va_list hub,char **str,int *count)
{
    if(*(*str) == ' ' || *(*str) == '#' || *(*str) == '+')
        ft_sep2_bonus(hub,str,count);
    else
        ft_sep(hub,str,count);
}

void ft_sep2_bonus(va_list hub,char **str,int *count)
{
    int r;

    r = 0;
	while(*(*str) == ' ' || *(*str) == '#' || *(*str) == '+')
		(*str)++;
    if(*(*str) >= '0' && *(*str) <= '9')
        r = ft_width(str);
	ft_detect_bonus(hub,str,count,r);
}

void ft_sep(va_list hub,char **str,int *count)
{
    int r;

    r = 0;
    if(*(*str) >= '0' && *(*str) <= '9')
        r = ft_width(str);
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_width(hub,*str,count,r);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_width(hub,*str,count,r);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_width(hub,*str,count,r);
}

int ft_printf(const char *str, ...)
{
    va_list hub;
    int     count;

    count = 0;
    va_start(hub,str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            ft_sep_main(hub,(char **)&str,&count);
        }
        else
            count += write(1,str,1);
        str++;
    }
    va_end(hub);
    return(count);
}
int main()
{
    int i = 0;
    i = ft_printf("%+10d\n",10);
    printf(" i == %d\n",i);
    int k = 0;
    k = printf("%+10d",10);
    printf(" k == %d\n",k);
}
