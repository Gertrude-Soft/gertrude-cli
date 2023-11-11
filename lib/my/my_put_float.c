/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_put_float
*/

#include "my.h"

static int custom_round(int number)
{
    if (number % 10 > 5) {
        number += 10;
    }
    number /= 10;
    return (number);
}

static void set_format(char ft, int *format)
{
    if (ft == 'f') {
        *format = 10000000;
    } else if (ft == 'g') {
        *format = 10000;
    }
}

static void my_put_flag_g(int *int_nbr)
{
    for (int i = 1; i <= 3; i++) {
        if (*int_nbr % 10 == 0) {
            *int_nbr /= 10;
        }
    }
}

void my_put_float(double nbr, char ft, int *count)
{
    int int_nbr = 0;
    int format;

    set_format(ft, &format);
    *count = *count + count_int_nbrs((int)nbr);
    my_put_nbr((int)nbr);
    int_nbr = custom_round((int)((nbr - (int)nbr) * format));
    if (ft == 'g' && int_nbr == 0)
        return;
    my_putchar('.');
    *count = *count + count_int_nbrs(int_nbr) + 1;
    for (int i = 0; i < (count_int_nbrs(format) - 2)
    - count_int_nbrs(int_nbr); i++) {
        my_putchar('0');
    }
    if (ft == 'g') {
        my_put_flag_g(&int_nbr);
    }
    my_put_nbr(int_nbr);
}
