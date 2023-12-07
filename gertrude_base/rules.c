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
#include <stdlib.h>

void rule_def(char **av, int ac, int *i, gertrude_t *ger)
{
    int index = 0;

    if (ger->rule_names == NULL) {
        ger->rule_names = malloc(strlen(av[*i]) + sizeof(NULL) + 10);
        ger->rule_names[0] = NULL;
    }
    else
        ger->rule_names = realloc(ger->rule_names, sizeof(ger->rule_names) + sizeof(NULL) + 10);
    for (; ger->rule_names[index] != NULL; index++);
    ger->rule_names[index] = malloc(strlen(av[*i]) + 1);
    strcpy(ger->rule_names[index], av[*i]);
    ger->rule_names[index + 1] = NULL;
    *i += 1;
    while (*i < ac && (strcmp(av[*i], "--deps") == 0 || strcmp(av[*i], "-D") == 0 || strcmp(av[*i], "--cmd") == 0 || strcmp(av[*i], "-c") == 0)) {
        if (strcmp(av[*i], "--deps") == 0 || strcmp(av[*i], "-D") == 0) {
            if (*i == ac - 1) {
                gertrude_errors(av, ac, *i, DEPWARN);
                *i += 1;
                continue;
            }
            if (av[*i + 1][0] == '-') {
                gertrude_errors(av, ac, *i, DEPWARN);
                *i += 1;
                continue;
            }
            *i += 1;
            if (ger->deps == NULL) {
                ger->deps = malloc(strlen(av[*i]) + 2);
                strcpy(ger->deps, "\t");
                strcat(ger->deps, av[*i]);
            } else {
                ger->deps = realloc(ger->deps, strlen(ger->deps) + strlen(av[*i]) + 2);
                strcat(ger->deps, "\t");
                strcat(ger->deps, av[*i]);
            }
            if (*i + 1 != ac)
                *i += 1;
            continue;
        }
        if (strcmp(av[*i], "--cmd") == 0 || strcmp(av[*i], "-c") == 0) {
            if (*i == ac - 1) {
                gertrude_errors(av, ac, *i, CMDWARN);
                *i += 1;
                continue;
            }
            if (av[*i + 1][0] == '-') {
                gertrude_errors(av, ac, *i, CMDWARN);
                *i += 1;
                continue;
            }
            *i += 1;
            if (ger->cmds == NULL) {
                ger->cmds = malloc(strlen(av[*i]) + 3);
                strcpy(ger->cmds, "\n\t");
                strcat(ger->cmds, av[*i]);
            } else {
                ger->cmds = realloc(ger->cmds, strlen(ger->cmds) + strlen(av[*i]) + 2);
                strcat(ger->cmds, "\n");
                strcat(ger->cmds, av[*i]);
            }
            *i += 1;
            continue;
        }
    }
    if (ger->rules == NULL) {
        ger->rules = malloc(strlen(ger->rule_names[index]) + strlen(ger->deps) + strlen(ger->cmds) + 4);
        strcpy(ger->rules, ger->rule_names[index]);
    }
    else {
        ger->rules = realloc(ger->rules, strlen(ger->rules) + strlen(ger->deps) + strlen(ger->rule_names[index]) + strlen(ger->cmds) + 4);
        strcat(ger->rules, ger->rule_names[index]);
    }
    strcat(ger->rules, ":");
    strcat(ger->rules, ger->deps);
    strcat(ger->rules, ger->cmds);
    strcat(ger->rules, "\n\n");
    free(ger->deps);
    free(ger->cmds);
    ger->deps = NULL;
    ger->cmds = NULL;
    *i -= 1;
}
