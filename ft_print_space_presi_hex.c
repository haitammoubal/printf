/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_presi_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:49:46 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/29 01:37:43 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space_presi_hex(int *max_width,int *count,long int a)
{
	int k;

	k = ft_size_hex(a);
	if(k > max_width[1])
		ft_print_space(max_width[0] - k,count);
	else
		ft_print_space(max_width[0] - max_width[1],count);

}
