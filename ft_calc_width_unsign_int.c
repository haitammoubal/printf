/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_width_unsign_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:16 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 22:28:39 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_calc_width_unsign_int(unsigned int a, int r,int *count)
{
	unsigned int k;

	k = ft_size_int(a);
	if(k >= (unsigned int)r)
		k = 0;
	else
		k = r - k;
	ft_print_space(k,count);
}
