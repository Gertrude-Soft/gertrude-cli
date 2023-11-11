/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_flag_octal
*/

#include "my.h"
#include <stdio.h>

static void my_put_prec(unsigned int integer, int *count,
    format_t *lp, int len)
{
    if (lp->precision > len) {
        for (int i = 0; i < lp->precision - len; i++) {
            my_putchar('0');
            *count += 1;
        }
    }
    my_put_dec_to_octal(integer, count);
}

static void my_put_len_pos(unsigned int integer, int *count,
    format_t *lp, int len)
{
    int temp_len = 0;

    if (lp->precision > 0)
        temp_len = len;
    for (int i = 0; i < (lp->length - len) - lp->precision + temp_len; i++) {
        my_putchar(' ');
        *count += 1;
    }
    my_put_prec(integer, count, lp, len);
}

static void my_put_len_neg(unsigned int integer, int *count,
    format_t *lp, int len)
{
    int temp_len = 0;

    if (lp->precision > 0)
        temp_len = len;
    my_put_prec(integer, count, lp, len);
    for (int i = 0; i < ((lp->length) * -1 - len)
    - lp->precision + temp_len; i++) {
        my_putchar(' ');
        *count += 1;
    }
}

void my_flag_octal(unsigned int integer, int *count, format_t *lp)
{
    int len = places_from_int_to_base(integer, 8);

    if (lp->length > len) {
        my_put_len_pos(integer, count, lp, len);
        return;
    }
    if ((lp->length) * -1 > len) {
        my_put_len_neg(integer, count, lp, len);
        return;
    }
    my_put_prec(integer, count, lp, len);
}
