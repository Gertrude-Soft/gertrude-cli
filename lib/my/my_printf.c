/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-miniprintf-laurent.gonzalez
** File description:
** mini_printf
*/

#include "my.h"
#include <stdlib.h>

static void switch_print_flags_d_i_o_u(const char c, va_list list, int *count,
    format_t *lp)
{
    switch (c) {
        case 'u':
        case 'i':
        case 'd':
            my_flag_integer(va_arg(list, int), count, lp);
            break;
        case 'o':
            my_flag_octal(va_arg(list, int), count, lp);
            break;
        case 'x':
            my_flag_hex_min(va_arg(list, unsigned long), count, lp);
            break;
        case 'X':
            my_flag_hex_maj(va_arg(list, unsigned long), count, lp);
            break;
    }
}

static void switch_print_flags_s_c(const char c, va_list list, int *count,
    format_t *lp)
{
    switch (c) {
        case 's':
            my_flag_string(va_arg(list, char *), count, lp);
            break;
        case 'c':
            my_flag_char(va_arg(list, int), count, lp);
            break;
        case '%':
            my_putchar('%');
            *count = *count + 1;
            break;
        case 'w':
            write_in_file(va_arg(list, const char *),
            va_arg(list, const char *), lp);
            break;
    }
}

static void switch_print_flags_f_g_p_n(const char c, va_list list, int *count,
    format_t *lp)
{
    switch (c) {
        case 'f':
            my_flag_float(va_arg(list, double), count, lp);
            break;
        case 'G':
        case 'g':
            my_flag_g(va_arg(list, double), count, lp);
            break;
        case 'p':
            my_flag_pointer(va_arg(list, void *), count, lp);
            break;
        case 'n':
            my_flag_n(va_arg(list, int *), count);
            break;
    }
}

static void print_chars(const char *format, va_list list, int *count)
{
    format_t *lp = malloc(sizeof(format_t));

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            *count = *count + 1;
            continue;
        }
        skip_spaces(format, &i);
        get_precision(format, &i, lp);
        switch_print_flags_d_i_o_u(format[i + 1], list, count, lp);
        switch_print_flags_s_c(format[i + 1], list, count, lp);
        switch_print_flags_f_g_p_n(format[i + 1], list, count, lp);
        i++;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    if (format[my_strlen(format) - 1] == '%' &&
    format[my_strlen(format) - 2] != '%') {
        return (-1);
    }
    print_chars(format, list, &count);
    va_end(list);
    return (count);
}
