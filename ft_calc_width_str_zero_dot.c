/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_width_str_zero_dot.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:16 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 01:55:25 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_calc_width_str_zero_dot(char *a, int *max_width,int *count)
{
	int k;

	k = ft_strlen(a);
	if(max_width[1] < k)
		k = max_width[1];
	ft_print_zero(max_width[0] - k,count);
}
