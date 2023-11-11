/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-laurent.gonzalez
** File description:
** my_put_nbr
*/

#include "my.h"

static void put_min(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        put_min();
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
        return (0);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}
