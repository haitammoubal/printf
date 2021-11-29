/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:58:25 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/27 13:00:22 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_max_width(char **str)
{
	int max_width;

	max_width = 0;
	if(*(*str) >= '1' && *(*str) <= '9')
		max_width = ft_width(str);
	return(max_width);
}
