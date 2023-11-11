/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_put_dec_to_octal
*/

#include "my.h"

void my_put_dec_to_octal(unsigned int dec, int *count)
{
    int octal = 0;
    int i = 1;

    while (dec != 0) {
        octal += (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }
    *count = *count + count_int_nbrs(octal);
    my_put_nbr(octal);
}
