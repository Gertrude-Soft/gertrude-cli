/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_put_pointer
*/

#include "my.h"

static void my_put_dec_to_hex_long(unsigned long dec, int ft, int *count)
{
    char temp_cl[17] = "0123456789abcdef";
    char temp_cu[17] = "0123456789ABCDEF";
    unsigned int temp = dec % 16;

    if (dec == 0) {
        return;
    } else if (ft == 0) {
        dec /= 16;
        my_put_dec_to_hex_long(dec, ft, count);
        my_putchar(temp_cl[temp]);
        *count = *count + 1;
    } else {
        dec /= 16;
        my_put_dec_to_hex_long(dec, ft, count);
        my_putchar(temp_cu[temp]);
        *count = *count + 1;
    }
}

void my_put_pointer(void *arg, int *count)
{
    my_putstr("0x");
    *count += 2;
    my_put_dec_to_hex_long((unsigned long)arg, 0, count);
}
