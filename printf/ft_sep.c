/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:32:27 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/22 21:23:28 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
void ft_sep(const char *str, int *i,va_list hub,int *count)
{
	if(str[*i + 1] == 'c' || str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_detect1(hub,(char *)str,count,i);
	else if(str[*i + 1] == 's' || str[*i + 1] == 'u' || str[*i + 1] == '%')
		ft_detect2(hub,(char *)str,count,i);
	else if(str[*i + 1] == 'p' || str[*i + 1] == 'x' || str[*i + 1] == 'X')
		ft_detect3(hub,(char *)str,count,i);
	(*i)++;
}
