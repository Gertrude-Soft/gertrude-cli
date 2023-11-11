/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** printf("\nPrecision: %f\nIndex: %d\n\n", *precision, *i);
** my_get_precision
*/

#include "my.h"

static void parse_length_portion(const char *format, int *i, format_t *lp)
{
    int place = 1;

    *i += 1;
    while (format[*i] >= '0' && format[*i] <= '9') {
        *i += 1;
    }
    *i -= 1;
    while (format[*i] != '%' && format[*i] != '-' && format[*i] != '+') {
        lp->length += (format[*i] - 48) * place;
        place *= 10;
        *i -= 1;
    }
    *i += 1;
    while (format[*i] >= '0' && format[*i] <= '9') {
        *i += 1;
    }
    *i -= 1;
}

static void parse_precision_portion(const char *format, int *i, format_t *lp)
{
    int place = 1;

    *i += 1;
    if (format[*i] == '.') {
        *i += 1;
        while (format[*i] >= '0' && format[*i] <= '9') {
            lp->precision += (format[*i] - 48);
            lp->precision *= 10;
            *i += 1;
        }
        lp->precision /= 10;
    }
    *i -= 1;
}

void get_precision(const char *format, int *i, format_t *lp)
{
    int sign = 1;

    lp->length = 0;
    lp->precision = 0;
    if (format[*i + 1] == '-') {
        *i += 1;
        sign = -1;
    }
    if (format[*i + 1] == '+') {
        *i += 1;
    }
    parse_length_portion(format, i, lp);
    parse_precision_portion(format, i, lp);
    lp->length *= sign;
}
