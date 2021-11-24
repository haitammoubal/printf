/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:38 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/22 21:23:58 by hmoubal          ###   ########.fr       */
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
void	ft_detect1(va_list hub, char *str, int *count,int *i);
void	ft_detect2(va_list hub,char *str,int *count,int *i);
void	ft_detect3(va_list hub,char *str,int *count,int *i);
void	ft_sep(const char *str, int *i,va_list hub,int *count);
#endif
