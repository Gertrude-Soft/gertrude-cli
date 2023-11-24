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

#include "../include/gertrude.h"
#include "../include/my.h"
#include "../include/text_mod.h"

// Modify ger->variables to store variables
// gertrude --var example=gertrude
// test    =    gertrude\n\ntest2    =  test2\n\n
// my_printf("%w", ger->dir, ger->variables);

static void name_def(char **av, int i, gertrude_t *ger)
{
    int var_name_size;
    int ger_var_size = my_strlen(ger->variables);

    for (var_name_size = 0; av[i][var_name_size] != '='; var_name_size++)
        if (av[i][var_name_size] ==  '\0')
            help(84);
    if (ger->variables == NULL)
        ger->variables = malloc(var_name_size + 1);
    else
        ger->variables = realloc(ger->variables, sizeof(ger->variables) + var_name_size);
    for (int j = 0 ; j < var_name_size + ger_var_size; j++)
        ger->variables[j + ger_var_size] = av[i][j];
    ger->variables[var_name_size + ger_var_size] = '\0';
}

static void value_def(char **av, int i, gertrude_t *ger)
{
    return;
}

void variable_def(char **av, int i, gertrude_t *ger)
{
    name_def(av, i, ger);
    value_def(av, i, ger);
}
