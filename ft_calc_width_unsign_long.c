/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_width_unsign_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:16 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 02:31:41 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_calc_width_unsign_long(unsigned long a, int *max_width,int *count)
{
	int k;

	k = ft_size_hex(a);
	if(k >= max_width[1])
		k = 0;
	else
		k = max_width[1] - k;
	ft_print_space(k,count);
}
