/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_bonus4_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:38:53 by hmoubal           #+#    #+#             */
/*   Updated: 2021/12/20 00:43:37 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_detect_bonus4_all(va_list hub, char **str, int *count)
{
	if (*(*str) == ' ')
		ft_space_flags(hub, str, count);
	else if (*(*str) == '+')
		ft_plus_flags(hub, str, count);
	else if (*(*str) == '#')
		ft_sharp_flags(hub, str, count);
}
