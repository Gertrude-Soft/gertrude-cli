/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Phony handling
*/

#include "../include/gertrude.h"
#include "../include/ger_conf.h"

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
    if (REMARKABLE == true) {
        phony = realloc(phony, strlen(phony) + strlen("all\tclean\tfclean\tre") + 1);
        strcat(phony, "all\tclean\tfclean\tre");
        if (ger->rule_names == NULL) {
            phony = realloc(phony, strlen(phony) + 2);
            strcat(phony, "\n");
        } else {
            phony = realloc(phony, strlen(phony) + 2);
            strcat(phony, "\t");
        }
    }
    for (int i = 0; ger->rule_names[i] != NULL; i ++) {
        phony = realloc(phony, strlen(phony) + strlen(ger->rule_names[i]) + 2);
        strcat(phony, ger->rule_names[i]);
        if (ger->rule_names[i + 1] != NULL)
            strcat(phony, "\t");
    }
    phony = realloc(phony, strlen(phony) + strlen("\tgertrude\n") + 1);
    strcat(phony, "\tgertrude\n");
    return phony;
}
