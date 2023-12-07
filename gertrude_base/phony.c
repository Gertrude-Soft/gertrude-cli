/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Phony handling
*/

#include "../include/gertrude.h"

#include <stdlib.h>
#include <string.h>

char *set_phony(gertrude_t *ger)
{
    char *phony = malloc(strlen(".PHONY:\t") + 1);

    if (ger->rule_names == NULL) {
        free(phony);
        return NULL;
    }
    strcpy(phony, ".PHONY:\t");
    for (int i = 0; ger->rule_names[i] != NULL; i ++) {
        phony = realloc(phony, sizeof(phony) + strlen(ger->rule_names[i]) + 2);
        strcat(phony, ger->rule_names[i]);
        if (ger->rule_names[i + 1] != NULL)
            strcat(phony, "\t");
        else
            strcat(phony, "\n\0");
    }
    return phony;
}
