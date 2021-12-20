/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:58:04 by hmoubal           #+#    #+#             */
/*   Updated: 2021/12/20 01:12:13 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_flags(va_list hub, char **str, int *count)
{
	while (*(*str) == ' ')
		(*str)++;
	if (*(*str) == 'x' || *(*str) == 'X')
		ft_space_flags1(hub, *str, count);
	else if (*(*str) == 'd' || *(*str) == 'i' || *(*str) == 'p')
		ft_space_flags2(hub, *str, count);
	else if (*(*str) == 's' || *(*str) == 'c' || *(*str) == '%')
		ft_space_flags3(hub, *str, count);
}

void	ft_space_flags1(va_list hub, char *str, int *count)
{
	unsigned int	a;

	a = va_arg(hub, unsigned int);
	if (*(str) == 'x')
		cal_bonus(16, a, "0123456789abcdef", count);
	else
		cal_bonus(16, a, "0123456789ABCDEF", count);
}

void	ft_space_flags2(va_list hub, char *str,
		int *count)
{
	int	a;

	a = 0;
	if (*str == 'i' || *str == 'd')
	{
		a = va_arg(hub, int);
		if (a >= 0)
			*count += write(1, " ", 1);
		cal_int_bonus(10, a, "0123456789", count);
	}
	else
		ft_detect3_bonus(hub, str, count);
}

void	ft_space_flags3(va_list hub, char *str, int *count)
{
	char	*a;

	a = NULL;
	if (*str == 's')
	{
		a = va_arg(hub, char *);
		ft_putstr(a, count);
	}
	else if (*str == 'c')
		ft_detect1_bonus(hub, str, count);
	else if (*str == '%')
		ft_detect2_bonus(hub, str, count);
}
