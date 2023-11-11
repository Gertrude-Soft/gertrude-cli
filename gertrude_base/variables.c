/*
** EPITECH PROJECT, 2023
** Gertrule-CLI
** File description:
** Handles variable definition
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "../include/my.h"

void variable_def(char **av, int i)
{
    int j = 0;
    int k = 0;
    char *name = malloc(sizeof(char *));
    char *value = malloc(sizeof(char *));
    char *final = malloc(sizeof(char *));

    while (av[i][j] != '=' && av[i][j] != ' ') {
        name[k] = av[i][j];
        j ++;
        k ++;
    }
    if (av[i][j] == '=') {
        j ++;
        k = 0;
        while (av[i][j] != ' ' && av[i][j] != '\0') {
            value[k] = av[i][j];
            j ++;
            k ++;
        }
    }
    strcat(final, name);
    strcat(final, "\t=\t");
    strcat(final, value);
    if (access("Makefile", F_OK) == -1) {
        open("Makefile", O_CREAT);
    }
    my_printf("%w", "Makefile", final);
    free(name);
    free(value);
    free(final);
}
