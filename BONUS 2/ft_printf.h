/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:38 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/24 22:06:41 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>
#include <stdio.h>
#include <limits.h>

int		ft_printf(const char *str, ...);
void	cal(unsigned long  n,unsigned long  nb,char *base,int *count);
void	cal_int(long int n,long int nb,char *base,int *count);
void	ft_putstr(char *str,int *count);
void	ft_detect1(va_list hub, char *str,int *count);
void	ft_detect1_width(va_list hub, char *str,int *count,int r);
void	ft_detect1_bonus(va_list hub,char *str, int *count,int r);
void	ft_detect2(va_list hub,char *str,int *count);
void	ft_detect2_bonus(va_list hub,char *str, int *count,int r);
void	ft_detect2_width(va_list hub,char *str,int *count,int r);
void	ft_detect3(va_list hub,char *str,int *count);
void	ft_detect3_bonus(va_list hub, int *count,int r);
void	ft_detect3_width(va_list hub,char *str,int *count,int r);
void	ft_sep(va_list hub,char **str,int *count);
void	ft_sep2_bonus(va_list hub,char **str,int *count);
void	ft_sep_main(va_list hub,char **str,int *count);
void	ft_detect_bonus(va_list hub,char **str,int *count,int r);
int		ft_width(char **str);
size_t	ft_strlen(char *str);
int		ft_size_int(long int n);
int		ft_size_hex(unsigned long n);
void	ft_print_space(int i,int *count);
void	ft_calc_width_int(int a, int r,int *count);
void	ft_calc_width_str(char *a, int r,int *count);
void	ft_calc_width_unsign(unsigned int a, int r,int *count);
void ft_calc_width_unsign_long(unsigned long a, int r,int *count);
#endif
