/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:38 by hmoubal           #+#    #+#             */
/*   Updated: 2021/12/20 01:15:58 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>
# include <stdio.h>
# include <limits.h>
# include<string.h>

int		ft_printf(const char *str, ...);
void	cal(unsigned long n, unsigned long nb, char *base, int *count);
void	cal_int(long int n, long int nb, char *base, int *count);
void	cal_bonus(unsigned long n, unsigned long nb, char *base, int *count);
void	cal_int_bonus(long int n, long int nb, char *base, int *count);
void	ft_putstr(char *str, int *count);
void	ft_detect1(va_list hub, char *str, int *count);
void	ft_detect1_bonus(va_list hub, char *str, int *count);
void	ft_detect2(va_list hub, char *str, int *count);
void	ft_detect2_bonus(va_list hub, char *str, int *count);
void	ft_detect3(va_list hub, char *str, int *count);
void	ft_detect3_bonus(va_list hub, char *str, int *count);
void	ft_sep(va_list hub, char **str, int *count);
void	ft_sep_bonus(va_list hub, char **str, int *count);
void	ft_sep_main(va_list hub, char **str, int *count);
void	ft_detect_bonus4_all(va_list hub, char **str, int *count);
void	ft_space_flags(va_list hub, char **str, int *count);
void	ft_space_flags1(va_list hub, char *str, int *count);
void	ft_space_flags2(va_list hub, char *str, int *count);
void	ft_space_flags3(va_list hub, char *str, int *count);
void	ft_plus_flags(va_list hub, char **str, int *count);
void	ft_plus_flags1(va_list hub, char *str, int *count);
void	ft_plus_flags2(va_list hub, char *str, int *count);
void	ft_plus_flags3(va_list hub, char *str, int *count);
void	ft_sharp_flags(va_list hub, char **str, int *count);
void	ft_sharp_flags1(va_list hub, char *str, int *count);
void	ft_sharp_flags2(va_list hub, char *str, int *count);
void	ft_sharp_flags3(va_list hub, char *str, int *count);
#endif
