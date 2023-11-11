/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_flag_pointer
*/

#include "my.h"
#include <stdio.h>

static void my_put_len_pos(void *pointer, int *count, format_t *lp, int len)
{
    int temp_len = 0;

    if (lp->precision > 0)
        temp_len = len;
    for (int i = 0; i < (lp->length - len) - lp->precision + temp_len; i++) {
        my_putchar(' ');
        *count += 1;
    }
    my_put_pointer(pointer, count);
}

static void my_put_len_neg(void *pointer, int *count, format_t *lp, int len)
{
    int temp_len = 0;

    if (lp->precision > 0)
        temp_len = len;
    my_put_pointer(pointer, count);
    for (int i = 0; i < ((lp->length) * -1 - len)
    - lp->precision + temp_len; i++) {
        my_putchar(' ');
        *count += 1;
    }
}

void my_flag_pointer(void *pointer, int *count, format_t *lp)
{
    int len = 14;

    if (lp->length > len) {
        my_put_len_pos(pointer, count, lp, len);
        return;
    }
    if ((lp->length) * -1 > len) {
        my_put_len_neg(pointer, count, lp, len);
        return;
    }
    my_put_pointer(pointer, count);
}
