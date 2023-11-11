/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_flag_string
*/

#include "my.h"
#include <stdio.h>

static void my_put_prec_pos(char *string, format_t *lp, int len)
{
    if (len > lp->precision && lp->precision != 0) {
        for (int i = 0; i < (len - lp->precision); i++) {
            my_putchar(' ');
        }
        for (int i = 0; i < lp->precision; i++) {
            my_putchar(string[i]);
        }
        return;
    }
    my_putstr(string);
}

static void my_put_prec_neg(char *string, format_t *lp, int len)
{
    if (len > lp->precision && lp->precision != 0) {
        for (int i = 0; i < lp->precision; i++) {
            my_putchar(string[i]);
        }
        for (int i = 0; i < (len - lp->precision); i++) {
            my_putchar(' ');
        }
        return;
    }
    my_putstr(string);
}

static void my_put_len_pos(char *string, int *count,
    format_t *lp, int len)
{
    for (int i = 0; i < (lp->length - len); i++) {
        my_putchar(' ');
        *count += 1;
    }
    my_put_prec_pos(string, lp, len);
}

static void my_put_len_neg(char *string, int *count,
    format_t *lp, int len)
{
    my_put_prec_neg(string, lp, len);
    for (int i = 0; i < ((lp->length) * -1 - len); i++) {
        my_putchar(' ');
        *count += 1;
    }
}

void my_flag_string(char *string, int *count, format_t *lp)
{
    int len = my_strlen(string);

    *count += len;
    if (lp->length > len) {
        my_put_len_pos(string, count, lp, len);
        return;
    }
    if ((lp->length) * -1 > len) {
        my_put_len_neg(string, count, lp, len);
        return;
    }
    my_put_prec_neg(string, lp, len);
}
