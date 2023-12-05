/*
** EPITECH PROJECT, 2023
** gertrude-cli
** File description:
** rules
*/

#include "../include/gertrude.h"
#include "../include/my.h"
#include "../include/text_mod.h"
#include "../include/error_codes.h"

#include <string.h>

void rule_def(char **av, int ac, int *i, gertrude_t *ger)
{
    int deps = 0;

    while (strcmp(av[*i], "--deps") == 0 || strcmp(av[*i], "--cmd") == 0) {
        return;
    }
}
