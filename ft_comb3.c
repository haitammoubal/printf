/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:59 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 03:00:18 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_comb3(va_list hub,char **str, int *count,int *max_width)
{
	(*str)++;
	if(*(*str) == '0')
	{
		(*str)++;
		ft_bonus_dotzero(hub,str,count,max_width);
	}
	else if(*(*str) == '-')
	{
		(*str)++;
		ft_bonus_dotminus(hub,str,count,max_width);
	}
}
