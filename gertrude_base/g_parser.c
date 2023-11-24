/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** A CLI-based Makefile Tool
*/

#include <stdlib.h>
#include <string.h>

#include "../include/gertrude.h"

void parse_args(int ac, char **av, gertrude_t *ger)
{
    for (int i = 0; i < ac; i ++) {
        if (strcmp(av[i], "-h") == 0) {
            help(0);
        } else if (strcmp(av[i], "--var") == 0) {
            i ++;
            variable_def(av, i, ger);
        } else if (strcmp(av[i], "-d") == 0) {
            i ++;
            directory_def(ger, av, i);
        }
    }
}
