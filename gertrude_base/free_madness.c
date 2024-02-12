/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** free_madness
*/

#include <stdlib.h>
#include <unistd.h>

#include "../include/gertrude.h"

void free_gaza(gertrude_t *ger)
{
    free(ger->dir);
    free(ger->variables);
    free(ger->deps);
    free(ger->cmds);
    free(ger->rules);
    free(ger->phony);
    if (ger->rule_names != NULL) {
        for (int i = 0; ger->rule_names[i] != NULL; i ++)
            free(ger->rule_names[i]);
        free(ger->rule_names);
    }
    ger->header = malloc(1);
    free(ger->header);
}
