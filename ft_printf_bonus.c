/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:00:22 by hmoubal           #+#    #+#             */
/*   Updated: 2021/12/20 01:16:12 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sep_main(va_list hub, char **str, int *count)
{
	if (*(*str) == ' ' || *(*str) == '#' || *(*str) == '+')
		ft_detect_bonus4_all(hub, str, count);
	else
		ft_sep_bonus(hub, str, count);
}

void	ft_sep_bonus(va_list hub, char **str, int *count)
{
	if (*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_bonus(hub, *str, count);
	else if (*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_bonus(hub, *str, count);
	else if (*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_bonus(hub, *str, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	hub;
	int		count;

	count = 0;
	va_start(hub, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_sep_main(hub, (char **)&str, &count);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(hub);
	return (count);
}
// int main()
// {
// 	int i = 0;
// 	i = ft_printf("%+d",15);
// 	printf("\n%d",i);
// 	i = printf("%+d",15);
// 	printf("\n%d",i);
// }
