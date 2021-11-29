/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:59 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 21:09:46 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_comb2(va_list hub,char **str, int *count,int *max_width)
{
	if(*(*str) == '0')
	{
		while(*(*str) == '0')
			(*str)++;
		ft_bonus_minus(hub,str,count,max_width);
	}
	else if(*(*str) == '.')
	{
		while(*(*str) == '.')
			(*str)++;
		ft_bonus_dotminus(hub,str,count,max_width);
	}
}
