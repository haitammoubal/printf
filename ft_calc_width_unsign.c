/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_width_unsign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:16 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 22:42:23 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_calc_width_unsign(unsigned int a, int r,int *count)
{
	unsigned int k;

	k = ft_size_hex(a);
	if(k >= (unsigned int)r)
		k = 0;
	else
		k = r - k;
	ft_print_space(k,count);
}
