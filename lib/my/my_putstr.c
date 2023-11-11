/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-LAURENT.GONZALEZ
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
