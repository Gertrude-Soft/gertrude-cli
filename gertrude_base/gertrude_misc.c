/*
** EPITECH PROJECT, 2023
** gertrude-cli
** File description:
** Miscellaneous functions
*/

#include <stdlib.h>

#include "../include/my.h"
#include "../include/text_mod.h"

void help(int ret)
{
    my_printf("\n%sGertrude HELP!\n", RED);
    my_printf("\n%sGertrude-CLI, a Makefile tool%s\n", GREEN, NC);
    my_printf("\n%sUSAGE:\n\n\
    %sgertrude%s [ -d directory ] [--var variable[=value]]* [[-r rule] [--deps dependencies]* [--cmd command]*]* [-epi]\n\n\n", YELLOW, GREEN, NC);
    my_printf("%sDESCRIPTION:%s\n\n\
    DIRECTORY : Directory to the Makefile. No Makefile should exist there.\n\n\
    --var : Define %svariable%s using %svalue%s. If %svalue%s is not provided, it will be initialised to 42.\n\n\
    -r : Define %srule%s. By default, the rule created runs 'echo New Rule'. C.F. --deps, --cmd\n\n\
    --deps : %srule%s will run %sdependencies%s. Each --deps argument can only name one dependecy.\n\n\
    --cmd : %srule%s will run %scommand%s. Each --cmd argument can only state one command.\n\n\
    -epi : Preprends the Epitech Header (2023 style).\n", YELLOW, NC, UL, NC, UL, NC, UL, NC, UL, NC, UL, NC, UL, NC, UL, NC, UL, NC);
    exit(ret);
}
