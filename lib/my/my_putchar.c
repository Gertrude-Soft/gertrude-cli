/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-laurent.gonzalez
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
