/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:38 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/29 01:37:53 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>
#include <stdio.h>
#include <limits.h>
#include<string.h>

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
void	ft_detect3_bonus(va_list hub,char *str,int *count,int r);
void	ft_detect3_width(va_list hub,char *str,int *count,int r);
void	ft_sep(va_list hub,char **str,int *count);
void	ft_sep_bonus(va_list hub,char **str,int *count,int max_width);
void	ft_sep2_bonus(va_list hub,char **str,int *count);
void	ft_sep_main(va_list hub,char **str,int *count);
void	ft_detect_bonus_all(va_list hub,char **str,int *count,int r);
int		ft_width(char **str);
size_t	ft_strlen(char *str);
int		ft_size_int(long int n);
int		ft_size_hex(unsigned long n);
void	ft_print_space(int i,int *count);
void	ft_calc_width_int(int a, int r,int *count);
void	ft_calc_width_str(char *a, int r,int *count);
void	ft_calc_width_unsign(unsigned int a, int r,int *count);
void	ft_calc_width_unsign_long(unsigned long a, int *max_width,int *count);
void	ft_detect_bonus2_all(va_list hub,char **str,int *count,int *max_width);
void	ft_bonus_zero(va_list hub, char **str,int *count,int max_width);
void	ft_detect1_bonus2_zero(va_list hub, char *str,int *count,int r);
void	ft_detect2_bonus2_zero(va_list hub, char *str,int *count,int r);
void	ft_detect3_bonus2_zero(va_list hub, char *str,int *count,int r);
void	ft_bonus_minus(va_list hub, char **str,int *count,int *max_width);
void	ft_detect1_bonus2_minus(va_list hub, char *str,int *count,int r);
void	ft_detect2_bonus2_minus(va_list hub, char *str,int *count,int r);
void	ft_detect3_bonus2_minus(va_list hub, char *str,int *count,int r);
void	ft_bonus_dot(va_list hub, char **str,int *count,int *max_width);
void	ft_detect1_bonus2_dot(va_list hub, char *str,int *count,int *max_width);
void	ft_detect2_bonus2_dot(va_list hub, char *str,int *count,int *max_width);
void	ft_detect3_bonus2_dot(va_list hub, char *str,int *count,int *max_width);
void	ft_print_zero(int i,int *count);
void	ft_calc_width_int_zero(long int a, int r,int *count);
void	ft_calc_width_str_zero(char *a, int r,int *count);
void	ft_calc_width_unsign_zero(unsigned int a, int r,int *count);
void	ft_calc_width_unsign_long_space(unsigned long a, int *max_width,int *count);
int		ft_size_unsign(unsigned int n);
void	ft_calc_width_int_minus(long int a, int r,int *count);
void	ft_calc_width_str_minus(char *a, int r,int *count);
void	ft_calc_width_unsign_long_minus(unsigned long a, int r,int *count);
void	ft_calc_width_unsign_minus(unsigned int a, int r,int *count);
int		ft_dot_detect(char *str);
void	ft_putstr_dot(char *str,int *count, int r);
void	ft_comb1(va_list hub,char **str, int *count,int *max_width);
void	ft_comb2(va_list hub,char **str, int *count,int *max_width);
void	ft_comb3(va_list hub,char **str, int *count,int *max_width);
int		ft_max_width(char **str);
void	ft_bonus_dotzero(va_list hub,char **str,int *count,int *max_width);
void	ft_detect1_bonus2_dotzero(va_list hub, char *str,int *count,int *max_width);
void	ft_detect2_bonus2_dotzero(va_list hub, char *str,int *count,int *max_width);
void	ft_detect3_bonus2_dotzero(va_list hub, char *str,int *count,int *max_width);
void	ft_bonus_dotminus(va_list hub, char **str,int *count,int *max_width);
void	ft_detect1_bonus2_dotminus(va_list hub, char *str,int *count,int *max_width);
void	ft_detect2_bonus2_dotminus(va_list hub, char *str,int *count,int *max_width);
void	ft_detect3_bonus2_dotminus(va_list hub, char *str,int *count,int *max_width);
void	ft_minus_zero_dot(va_list hub,char **str,int *count);
void	ft_minus_dot_zero(va_list hub,char **str,int *count);
void	ft_zero_minus_dot(va_list hub,char **str,int *count);
void	ft_zero_dot_minus(va_list hub,char **str,int *count);
void	ft_dot_zero_minus(va_list hub,char **str,int *count);
void	ft_dot_minus_zero(va_list hub,char **str,int *count);
void	ft_detect_bonus3_all(va_list hub,char **str,int *count,int *max_width);
void    ft_minus_zero_dot1(va_list hub, char *str,int *count,int r);
void    ft_minus_zero_dot2(va_list hub, char *str,int *count,int r);
void    ft_minus_zero_dot3(va_list hub, char *str,int *count,int r);
void	ft_calc_width_str_zero_dot(char *a, int *max_width,int *count);
void	ft_calc_width_unsign_long_zero(unsigned long a, int r,int *count);
void	ft_print_space_presi(int *max_width,int *count,long int a);
void	ft_calc_width_unsign_longr(unsigned long a, int r,int *count);
void	ft_calc_width_unsign_zero2(unsigned int a, int r,int *count);
void	ft_calc_width_unsign_longr_printzero(unsigned long a, int r,int *count);
void	ft_calc_width_unsign_int(unsigned int a, int r,int *count);
void	ft_str_space(char *a,int r,int *count);
void	ft_print_space_presi_hex(int *max_width,int *count,long int a);
#endif
