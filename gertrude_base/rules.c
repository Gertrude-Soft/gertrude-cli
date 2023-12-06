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
    // ADD RULE NAME
    *i += 1;
    while (*i < ac && (strcmp(av[*i], "--deps") == 0 || strcmp(av[*i], "-D") == 0 || strcmp(av[*i], "--cmd") == 0 || strcmp(av[*i], "-c") == 0)) {
        // CHECK IF MULTIPLE DEPENDENCIES GIVEN AND ORDER
        // CMDS -> DEPS : WARN || CRASH? OR REFACTOR TO SUPPORT INVERTED RULES
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
            // ADD RULE DEPENDENCY
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
            // ADD RULE COMMANDS
        }
    }
}
