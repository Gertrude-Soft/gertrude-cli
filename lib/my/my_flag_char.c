/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_flag_char
*/

#include "my.h"
#include <stdio.h>

static void my_put_len_pos(char string, int *count,
    format_t *lp, int len)
{
    for (int i = 0; i < (lp->length - len); i++) {
        my_putchar(' ');
        *count += 1;
    }
    my_putchar(string);
}

static void my_put_len_neg(char string, int *count,
    format_t *lp, int len)
{
    my_putchar(string);
    for (int i = 0; i < ((lp->length) * -1 - len); i++) {
        my_putchar(' ');
        *count += 1;
    }
}

void my_flag_char(char string, int *count, format_t *lp)
{
    int len = 1;

    *count += len;
    if (lp->length > len) {
        my_put_len_pos(string, count, lp, len);
        return;
    }
    if ((lp->length) * -1 > len) {
        my_put_len_neg(string, count, lp, len);
        return;
    }
    my_putchar(string);
}
