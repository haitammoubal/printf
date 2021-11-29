/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:35:32 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/28 22:38:08 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_str_space(char *a,int r,int *count)
{
	if(!a)
	{
		r = r - 6;
		ft_print_space(r,count);
	}
	else
	{
		r = r - ft_strlen(a);
		ft_print_space(r,count);
	}
}
