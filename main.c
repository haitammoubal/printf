#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>

int main()
{
    int k = 0;
    // printf("test 1 == 0-\n");
    // k = printf("%0-10s","hey");
    // printf(" type s k == %d\n",k);
    // k = printf("%0-10d",14);
    // printf(" type d k == %d\n",k);
    // k = printf("%0-10i",15);
    // printf(" type i k == %d\n",k);
    // k = printf("%0-10%");
    // printf(" type percent k == %d\n",k);
    // k = printf("%0-10c",'c');
    // printf(" type c k == %d\n",k);
    // k = printf("%0-10p",1489);
    // printf(" type p k == %d\n",k);
    // k = printf("%0-10x",1489);
    // printf(" type x k == %d\n",k);
    // k = printf("%0-10X",1489);
    // printf(" type X k == %d\n",k);
    // printf("\n\n");


    // printf("test 1 == 0.\n");
    // k = printf("%010.5s",NULL);
    // printf(" type s k == %d\n",k);
    // k = printf("%020.30d",15);
    // printf(" type d k == %d\n",k);
    // k = printf("%020.10i",0);
    // printf(" type i k == %d\n",k);
    // k = printf("%0.u",0);
    // printf(" type u k == %d\n",k);
    // k = printf("%010.0%");
    // printf(" type percent k == %d\n",k);
    // k = printf("%0.c",'c');
    // printf(" type c k == %d\n",k);
    // k = printf("%020.10p",&k);
    // printf(" type p k == %d\n",k);
    // k = printf("%020.30x",1489);
    // printf(" type x k == %d\n",k);
    // k = printf("%020.10X",1489);
    // printf(" type X k == %d\n",k);
    // printf("\n\n");


    // printf("test 1 == 0\n");
    // k = printf("%04s","haitam");
    // printf(" type s k == %d\n",k);
    // k = printf("%010d",15);
    // printf(" type d k == %d\n",k);
    // k = printf("%010i",0);
    // printf(" type i k == %d\n",k);
    // k = printf("%010u",0);
    // printf(" type u k == %d\n",k);
    // k = printf("%010%");
    // printf(" type percent k == %d\n",k);
    // k = printf("%010c",'c');
    // printf(" type c k == %d\n",k);
    // k = printf("%015p",&k);
    // printf(" type p k == %d\n",k);
    // k = printf("%010x",1489);
    // printf(" type x k == %d\n",k);
    // k = printf("%010X",1489);
    // printf(" type X k == %d\n",k);
    // printf("\n\n");



    // printf("test 1 == -\n");
    // k = printf("%6s","haitam");
    // printf(" type s k == %d\n",k);
    // k = printf("%-3d",-154567);
    // printf(" type d k == %d\n",k);
    // k = printf("%-10i",0);
    // printf(" type i k == %d\n",k);
    // k = printf("%-20u",1561);
    // printf(" type u k == %d\n",k);
    // k = printf("%-10%");
    // printf(" type percent k == %d\n",k);
    // k = printf("%-c",'c');
    // printf(" type c k == %d\n",k);
    // k = printf("%-15p",&k);
    // printf(" type p k == %d\n",k);
    // k = printf("%-10x",1489);
    // printf(" type x k == %d\n",k);
    // k = printf("%-10X",1489);
    // printf(" type X k == %d\n",k);
    // printf("\n\n");



    // printf("test 1 == .\n");
    // k = printf("%20.4s","haitam");
    // printf(" type s k == %d\n",k);
    // k = printf("%5.10d",-15);
    // printf(" type d k == %d\n",k);
    // k = printf("%5.20i",1415);
    // printf(" type i k == %d\n",k);
    // k = printf("%10.u",1561);
    // printf(" type u k == %d\n",k);
    // k = printf("%10.15%");
    // printf(" type percent k == %d\n",k);
    // k = printf("%.c",'c');
    // printf(" type c k == %d\n",k);
    // k = printf("%20.15p",&k);
    // printf(" type p k == %d\n",k);
    // k = printf("%10.15x",1489);
    // printf(" type x k == %d\n",k);
    // k = printf("%20.10X",1489);
    // printf(" type X k == %d\n",k);
    // printf("\n\n");

    k = ft_printf(" %.2u ", 10);
    printf("\n");
    printf("%d",k);
}

