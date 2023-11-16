/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-LAURENT.GONZALEZ
** File description:
** my_strlen
*/
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return 0;
    }
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
