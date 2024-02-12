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
#include "../include/error_codes.h"

static int name_def(char **av, int i, gertrude_t *ger)
{
    int var_name_size;
    int ger_var_size = strlen(ger->variables);

    for (var_name_size = 0; av[i][var_name_size] != '=' &&
    av[i][var_name_size] != '\0'; var_name_size++);
    ger->variables = realloc(ger->variables,
    strlen(ger->variables) + var_name_size + 1);
    for (int j = 0 ; j < var_name_size; j++)
        ger->variables[j + ger_var_size] = av[i][j];
    ger->variables[var_name_size + ger_var_size] = '\0';
    return var_name_size;
}

static void value_def(char **av, int ac, int i, gertrude_t *ger, int index)
{
    int var_value_size;
    int ger_var_size = strlen(ger->variables);

    if (av[i][index] == '\0') {
        ger->variables = realloc(ger->variables, strlen(ger->variables) + 6);
        strcat(ger->variables, "\t=\t\\\n");
        return;
    }
    ger->variables = realloc(ger->variables, strlen(ger->variables) + 4);
    strcat(ger->variables, "\t=\t");
    index++;
    if (av[i][index] == '\0') {
        gertrude_errors(av, ac, i, VARWARN);
        ger->variables = realloc(ger->variables, strlen(ger->variables) + 3);
        strcat(ger->variables, "\\\n");
        return;
    }
    for (var_value_size = index; av[i][var_value_size] != '\0'; var_value_size++);
    var_value_size -= index;
    ger->variables = realloc(ger->variables, strlen(ger->variables) + var_value_size + 3);
    for (int j = 0; j < var_value_size; j++)
        ger->variables[j + ger_var_size + 3] = av[i][j + index];
    ger->variables[ger_var_size + var_value_size + 3] = '\n';
    ger->variables[ger_var_size + var_value_size + 4] = '\n';
    ger->variables[ger_var_size + var_value_size + 5] = '\0';
}

void variable_def(char **av, int ac, int i, gertrude_t *ger)
{
    int index;

    index = name_def(av, i, ger);
    value_def(av, ac, i, ger, index);
}
