/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_bonus3_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:50:57 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 01:06:23 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_detect_bonus3_all(va_list hub,char **str,int *count,int *max_width)
{
	if(*(*str) == '-' && *(*str + 1) == '0' && *(*str + 2) == '.')
		ft_minus_zero_dot(hub,str,count,max_width);
	else if(*(*str) == '-' && *(*str + 1) == '.' && *(*str + 2) == '0')
		ft_minus_dot_zero(hub,str,count,max_width);
	else if(*(*str) == '0' && *(*str + 1) == '-' && *(*str + 2) == '.')
		ft_zero_minus_dot(hub,str,count,max_width);
	else if(*(*str) == '0' && *(*str + 1) == '.' && *(*str + 2) == '-')
		ft_zero_dot_minus(hub,str,count,max_width);
	else if(*(*str) == '.' && *(*str + 1) == '0' && *(*str + 2) == '-')
		ft_dot_zero_minus(hub,str,count,max_width);
	else if(*(*str) == '.' && *(*str + 1) == '-' && *(*str + 2) == '0')
		ft_dot_minus_zero(hub,str,count,max_width);
	else
		ft_detect_bonus2_all(hub,str,count,max_width);
}
