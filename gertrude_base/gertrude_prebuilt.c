/*
** EPITECH PROJECT, 2023
** Gertrude-CLI
** File description:
** Prebuilt Makefile creation
*/

#include <stdlib.h>

#include "../include/my.h"
#include "../include/text_mod.h"
#include "../include/gertrude.h"
#include "../include/ger_conf.h"

void base_mkf(gertrude_t *ger)
{
    my_printf("%sFinalising...%s\n", YELLOW, NC);
    if (HEADER == TRUE)
        print_header(ger);
    if (ger->variables != NULL)
        my_printf("%w", ger->dir, ger->variables);
    if (ger->rules != NULL)
        my_printf("%w", ger->dir, ger->rules);
    if (REMARKABLE == TRUE) {
        my_printf("%w", ger->dir, REM_ALL);
        my_printf("%w", ger->dir, REM_COMPILE);
        my_printf("%w", ger->dir, REM_CLEAN);
        my_printf("%w", ger->dir, REM_FCLEAN);
        my_printf("%w", ger->dir, REM_RE);
    }
    my_printf("%w", ger->dir, REM_GERTRUDE);
    if (AUTO_PHONY == TRUE && ger->phony != NULL)
        my_printf("%w", ger->dir, ger->phony);
}
