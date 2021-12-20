/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:48 by hmoubal           #+#    #+#             */
/*   Updated: 2021/12/20 01:09:38 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_detect1_bonus(va_list hub, char *str, int *count)
{
	char	a;
	int		k;

	k = 0;
	a = 0;
	if (*(str) == 'c')
	{
		a = va_arg(hub, int);
		*count += write(1, &a, 1);
	}
	else if (*(str) == 'd' || *(str) == 'i')
	{
		k = va_arg(hub, int);
		cal_int_bonus(10, k, "0123456789", count);
	}
}

void	ft_detect2_bonus(va_list hub, char *str, int *count)
{
	char			*a;
	unsigned int	k;

	k = 0;
	a = NULL;
	if (*(str) == 's')
	{
		a = va_arg(hub, char *);
		ft_putstr(a, count);
	}
	else if (*(str) == 'u')
	{
		k = va_arg(hub, unsigned int);
		cal_bonus(10, k, "0123456789", count);
	}
	else if (*(str) == '%')
		*count += write(1, "%%", 1);
}

void	ft_detect3_bonus(va_list hub, char *str, int *count)
{
	unsigned long	a;

	a = 0;
	if (*(str) == 'p')
	{
		a = va_arg(hub, unsigned long);
		*count += write(1, "0x", 2);
		cal_bonus(16, a, "0123456789abcdef", count);
	}
	else
	{
		a = va_arg(hub, unsigned int);
		if (*(str) == 'x')
			cal_bonus(16, a, "0123456789abcdef", count);
		else if (*(str) == 'X')
			cal_bonus(16, a, "0123456789ABCDEF", count);
	}
}

void	cal_bonus(unsigned long n, unsigned long nb, char *base, int *count)
{
	if (nb < 0)
	{
		*count += write(1, "-", 1);
		nb = -1 * nb;
	}
	if (nb >= n)
		cal_bonus(n, nb / n, base, count);
	*count += write(1, base + (nb % n), 1);
}

void	cal_int_bonus(long int n, long int nb, char *base, int *count)
{
	if (nb < 0)
	{
		*count += write(1, "-", 1);
		nb = -1 * nb;
	}
	if (nb >= n)
		cal_int_bonus(n, nb / n, base, count);
	*count += write(1, base + (nb % n), 1);
}
