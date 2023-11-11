/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_put_dec_to_hex
*/

/*
int ft, in my_put_dec_to_hex() is short for flag_type.
It can be one of two values:
- 0 if conversion letters are lower case.
- 1 if conversion letters are uppoer case.
*/

#include <stdlib.h>
#include "my.h"

void my_put_dec_to_hex(unsigned int dec, int ft, int *count)
{
    char temp_cl[17] = "0123456789abcdef";
    char temp_cu[17] = "0123456789ABCDEF";
    unsigned int temp = dec % 16;

    if (dec == 0) {
        return;
    } else if (ft == 0) {
        dec /= 16;
        my_put_dec_to_hex(dec, ft, count);
        my_putchar(temp_cl[temp]);
        *count = *count + 1;
    } else {
        dec /= 16;
        my_put_dec_to_hex(dec, ft, count);
        my_putchar(temp_cu[temp]);
        *count = *count + 1;
    }
}
