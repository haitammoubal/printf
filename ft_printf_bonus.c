/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:00:22 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/29 01:38:26 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_width(char **str)
{
	int	r;

	r = 0;
	while (*(*str) >= 48 && *(*str) <= 57)
	{
		r = (r * 10) + (*(*str) - 48);
		(*str)++;
	}
	return (r);
}

void ft_sep_main(va_list hub,char **str,int *count)
{
    int max_width[2];

    max_width[0] = 0;
    max_width[1] = 0;
	if(*(*str) >= '0' && *(*str) <= '9')
		max_width[0] = ft_max_width(str);
    if(*(*str) == ' ' || *(*str) == '#' || *(*str) == '+')
        ft_sep2_bonus(hub,str,count);
    else if(*(*str) == '0' || *(*str) == '-' || *(*str) == '.')
        ft_detect_bonus2_all(hub,str,count,max_width);
    else
        ft_sep_bonus(hub,str,count,max_width[0]);
}

void ft_sep2_bonus(va_list hub,char **str,int *count)
{
    int r;

    r = 0;
	while(*(*str) == ' ' || *(*str) == '#' || *(*str) == '+')
		(*str)++;
    if(*(*str) >= '0' && *(*str) <= '9')
        r = ft_width(str);
	ft_detect_bonus_all(hub,str,count,r);
}

void ft_sep_bonus(va_list hub,char **str,int *count,int max_width)
{
	if(*(*str) == 'c' || *(*str) == 'd' || *(*str) == 'i')
		ft_detect1_width(hub,*str,count,max_width);
	else if(*(*str) == 's' || *(*str) == 'u' || *(*str) == '%')
		ft_detect2_width(hub,*str,count,max_width);
	else if(*(*str) == 'p' || *(*str) == 'x' || *(*str) == 'X')
		ft_detect3_width(hub,*str,count,max_width);
}

int ft_printf(const char *str, ...)
{
    va_list hub;
    int     count;

    count = 0;
    va_start(hub,str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            ft_sep_main(hub,(char **)&str,&count);
        }
        else
            count += write(1,str,1);
        str++;
    }
    va_end(hub);
    return(count);
}
// int main()
// {
//     int i;
//     int k;
//     k = ft_printf(", %42.5X", -1);
//     printf(" k == %d\n",k);
//     i = printf(", %42.5X", -1);
//     printf(" i == %d\n",i);
// }
/*int main()
{
    // test 1 and test 2 and test 3 are all the same
    // test 4 and test 5 and test 6 are all the same
    int k = 0;
    printf("test 1 == -0.\n");
    k = printf("%-0.2s","hey"); // limit the string with the width
    printf(" type s k == %d\n",k);
    k = printf("%-0.10d",14); // like flag 0
    printf(" type d k == %d\n",k);
    k = printf("%-0.10i",15); // same as d
    printf(" type i k == %d\n",k);
    k = printf("%-0.10%"); // only type %
    printf("type percent k == %d\n",k);
    k = printf("%-0.10c",'c'); // same as %
    printf(" type c k == %d\n",k);
    k = printf("%-0.10p",1489); // does the same as flag 0
    printf("type p k == %d\n",k);
    k = printf("%-0.10x",1489); // does the same as flag 0
    printf("type x k == %d\n",k);
    k = printf("%-0.10X",1489); // does the same as flag 0
    printf("type X k == %d\n",k);
    printf("\n\n\n\n\n");
    printf("test 2 == -.0\n");
    k = printf("%-.02s","hey"); // limit the string with the width
    printf(" type s k == %d\n",k);
    k = printf("%-.010d",14); // like flag 0
    printf(" type d k == %d\n",k);
    k = printf("%-.010i",15); // same as d
    printf(" type i k == %d\n",k);
    k = printf("%-.010%"); // only type %
    printf("type percent k == %d\n",k);
    k = printf("%-.010c",'c'); // same as %
    printf(" type c k == %d\n",k);
    k = printf("%-.010p",1489); // does the same as flag 0
    printf("type p k == %d\n",k);
    k = printf("%-.010x",1489); // does the same as flag 0
    printf("type x k == %d\n",k);
    k = printf("%-.010X",1489); // does the same as flag 0
    printf("type X k == %d\n",k);
    printf("\n\n\n\n\n");
    printf("test 3 == 0-.\n");
    k = printf("%0-.2s","hey"); // limit the string with the width
    printf(" type s k == %d\n",k);
    k = printf("%0-.10d",14); // like flag 0
    printf(" type d k == %d\n",k);
    k = printf("%0-.10i",15); // same as d
    printf(" type i k == %d\n",k);
    k = printf("%0-.10%"); // only type %
    printf("type percent k == %d\n",k);
    k = printf("%0-.10c",'c'); // same as %
    printf(" type c k == %d\n",k);
    k = printf("%0-.10p",1489); // does the same as flag 0
    printf("type p k == %d\n",k);
    k = printf("%0-.10x",1489); // does the same as flag 0
    printf("type x k == %d\n",k);
    k = printf("%0-.10X",1489); // does the same as flag 0
    printf("type X k == %d\n",k);
    printf("\n\n\n\n\n");
    printf("test 4 == 0.-\n");
    k = printf("%0.-10s","hey i ate lunch today"); // only prints space from width
    printf(" type s k == %d\n",k);
    k = printf("%0.-10d",14); // like flag -
    printf(" type d k == %d\n",k);
    k = printf("%0.-10i",15); // same as d
    printf(" type i k == %d\n",k);
    k = printf("%0.-10%"); // type % and space from width
    printf("type percent k == %d\n",k);
    k = printf("%0.-10c",'c'); // same as %
    printf(" type c k == %d\n",k);
    k = printf("%0.-10p",1489); // does the same as flag -
    printf("type p k == %d\n",k);
    k = printf("%0.-10x",1489); // does the same as flag -
    printf("type x k == %d\n",k);
    k = printf("%0.-10X",1489); // does the same as flag -
    printf("type X k == %d\n",k);
    printf("\n\n\n\n\n");
    printf("test 5 == .0-\n");
    k = printf("%.0-2s","hey"); // limit the string with the width
    printf(" type s k == %d\n",k);
    k = printf("%.0-10d",14); // like flag 0
    printf(" type d k == %d\n",k);
    k = printf("%.0-10i",15); // same as d
    printf(" type i k == %d\n",k);
    k = printf("%.0-10%"); // only type %
    printf("type percent k == %d\n",k);
    k = printf("%.0-10c",'c'); // same as %
    printf(" type c k == %d\n",k);
    k = printf("%.0-10p",1489); // does the same as flag 0
    printf("type p k == %d\n",k);
    k = printf("%.0-10x",1489); // does the same as flag 0
    printf("type x k == %d\n",k);
    k = printf("%.0-10X",1489); // does the same as flag 0
    printf("type X k == %d\n",k);
    printf("\n\n\n\n\n");
    printf("test 6 == .-0\n");
    k = printf("%.-02s","hey"); // limit the string with the width
    printf(" type s k == %d\n",k);
    k = printf("%.-010d",14); // like flag 0
    printf(" type d k == %d\n",k);
    k = printf("%.-010i",15); // same as d
    printf(" type i k == %d\n",k);
    k = printf("%.-010%"); // only type %
    printf("type percent k == %d\n",k);
    k = printf("%.-010c",'c'); // same as %
    printf(" type c k == %d\n",k);
    k = printf("%.-010p",1489); // does the same as flag 0
    printf("type p k == %d\n",k);
    k = printf("%.-010x",1489); // does the same as flag 0
    printf("type x k == %d\n",k);
    k = printf("%.-010X",1489); // does the same as flag 0
    printf("type X k == %d\n",k);
    printf("\n");
}
*/


