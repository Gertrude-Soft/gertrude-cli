/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Rules
*/

#include "../include/gertrude.h"
#include "../include/my.h"
#include "../include/error_codes.h"

#include <string.h>
#include <stdlib.h>

int tab_len(char **tab)
{
    int count = 0;

    while (tab[count] != NULL)
        count++;
    return (count);
}

int update_rule_name_list(char **av, int ac, int *i, gertrude_t *ger)
{
    int index = 0;

    ger->rule_names = realloc(ger->rule_names,
    sizeof(char *) * tab_len(ger->rule_names) + sizeof(char *) + sizeof(NULL));
    for (; ger->rule_names[index] != NULL; index += 1);
    ger->rule_names[index] = malloc(strlen(av[*i]) + 1);
    strcpy(ger->rule_names[index], av[*i]);
    ger->rule_names[index + 1] = NULL;
    *i += 1;
    ger->cmds = malloc(1);
    ger->deps = malloc(1);
    strcpy(ger->cmds, "\0");
    strcpy(ger->deps, "\0");
    return (index);
}

void handle_deps(char **av, int ac, int *i, gertrude_t *ger)
{
    if (*i == ac - 1) {
        gertrude_errors(av, ac, *i, DEPWARN);
        *i += 1;
        return;
    }
    if (av[*i + 1][0] == '-') {
        gertrude_errors(av, ac, *i, DEPWARN);
        *i += 1;
        return;
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
    return;
}

void handle_cmds(char **av, int ac, int *i, gertrude_t *ger)
{
    if (*i == ac - 1) {
        gertrude_errors(av, ac, *i, CMDWARN);
        *i += 1;
        return;
    }
    if (av[*i + 1][0] == '-') {
        gertrude_errors(av, ac, *i, CMDWARN);
        *i += 1;
        return;
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
    return;
}

void bufferize(char **av, int ac, int *i, gertrude_t *ger, int index)
{
    ger->rules = realloc(ger->rules, strlen(ger->rules) +
    strlen(ger->rule_names[index]) + strlen(ger->deps) +
    strlen(ger->cmds) + 1 + 2 + 1);
    strcat(ger->rules, ger->rule_names[index]);
    strcat(ger->rules, ":");
    if (ger->deps != NULL) {
        strcat(ger->rules, ger->deps);
        free(ger->deps);
    }
    if (ger->cmds != NULL) {
        strcat(ger->rules, ger->cmds);
        free(ger->cmds);
    }
    strcat(ger->rules, "\n\n");
    ger->deps = NULL;
    ger->cmds = NULL;
    *i -= 1;
}

void rule_def(char **av, int ac, int *i, gertrude_t *ger)
{
    int index = update_rule_name_list(av, ac, i, ger);

    while (*i < ac && (strcmp(av[*i], "--deps") == 0 ||
    strcmp(av[*i], "-D") == 0 || strcmp(av[*i], "--cmd") == 0 ||
    strcmp(av[*i], "-c") == 0)) {
        if (strcmp(av[*i], "--deps") == 0 || strcmp(av[*i], "-D") == 0) {
            handle_deps(av, ac, i, ger);
        }
        if (strcmp(av[*i], "--cmd") == 0 || strcmp(av[*i], "-c") == 0) {
            handle_cmds(av, ac, i, ger);
        }
    }
    bufferize(av, ac, i, ger, index);
}
