/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_bonus2_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:13 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 23:05:57 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_detect_bonus2_all(va_list hub,char **str,int *count,int *max_width)
{
	if(*(*str) == '0')
	{
		while(*(*str) == '0')
			(*str)++;
		if(*(*str) >= '0' && *(*str) <= '9')
			max_width[0] = ft_max_width(str);
		if(*(*str) == '-' || (*(*str) == '.'))
			ft_comb1(hub,str,count,max_width);
		else
			ft_bonus_zero(hub,str,count,max_width[0]);
	}
	else if(*(*str) == '-')
	{
		while(*(*str) == '-')
			(*str)++;
		if(*(*str) >= '0' && *(*str) <= '9')
			max_width[0] = ft_max_width(str);
		if(*(*str) == '.' || *(*str) == '0')
			ft_comb2(hub,str,count,max_width);
		else
			ft_bonus_minus(hub,str,count,max_width);
	}
	else if(*(*str) == '.')
	{
		while(*(*str) == '.')
			(*str)++;
		/*if(*(*str) == '0' || (*(*str) == '-'))
			ft_comb3(hub,str,count,max_width);*/
		ft_bonus_dot(hub,str,count,max_width);
	}
}
