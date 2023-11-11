/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday09-laurent.gonzalez
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int count_int_nbrs(int i);
int places_from_int_to_base(int number, int base);
void my_put_dec_to_octal(unsigned int dec, int *count);
void skip_spaces(const char *format, int *i);
void my_put_dec_to_hex(unsigned int dec, int ft, int *count);
void my_put_float(double nbr, char ft, int *count);
void my_put_pointer(void *arg, int *count);
void my_flag_n(int *number, int *count);
int my_printf(const char *format, ...);

struct format_s {
    int length;
    int precision;
};
typedef struct format_s format_t;

void get_precision(const char *format, int *i, format_t *lp);
void my_flag_integer(int integer, int *count, format_t *lp);
void my_flag_octal(unsigned int integer, int *count, format_t *lp);
void my_flag_hex_min(unsigned int integer, int *count, format_t *lp);
void my_flag_hex_maj(unsigned int integer, int *count, format_t *lp);
void my_flag_string(char *string, int *count, format_t *lp);
void my_flag_char(char string, int *count, format_t *lp);
void my_flag_float(double number, int *count, format_t *lp);
void my_flag_g(double number, int *count, format_t *lp);
void my_flag_pointer(void *pointer, int *count, format_t *lp);
int write_in_file(const char *string, const char *filename, format_t *lp);

#endif
