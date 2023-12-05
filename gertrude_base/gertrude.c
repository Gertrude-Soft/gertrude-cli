/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Point of Entry
*/

#include <stdlib.h>

#include "../include/my.h"
#include "../include/text_mod.h"
#include "../include/gertrude.h"

int main(int ac, char **av)
{
    gertrude_t ger;

    ger.dir = "./Makefile";
    ger.epitech = 0;
    ger.variables = NULL;
    my_printf("\n%sGertrude says Welcome!%s\n\n", GREEN, NC);
    if (ac == 1) {
        base_mkf();
        exit(0);
    }
    parse_args(ac, av, &ger);
    my_printf("%sFinalising...%s\n", YELLOW, NC);
    // my_printf("%w", ger.dir, ger.variables);
    my_printf("\n%sGood Plant%s\n", GREEN, NC);
}
