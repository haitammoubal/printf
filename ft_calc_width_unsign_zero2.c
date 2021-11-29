/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_width_unsign_zero2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:16 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 20:58:16 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_calc_width_unsign_zero2(unsigned int a, int r,int *count)
{
	int k;

	k = ft_size_int(a);
	if(k >= r)
		k = 0;
	else
		k = r - k;
	ft_print_zero(k,count);
}
