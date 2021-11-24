/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:28 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 21:48:35 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
            ft_sep(str,&i,hub,&count);
        else
            count += write(1,&str[i],1);
        i++;
    }
    va_end(hub);
    return(count);
}
// int main()
// {
//    // int i = 0;;
//   int a = 0;
//     //i = ft_printf("%#x",0);
//     a = ft_printf("%x",15);
//     ft_printf("%d",a);
//     //a = printf("%#x",10);
//    //printf("%d\n",i);
//     //printf("%d",a);
// }
