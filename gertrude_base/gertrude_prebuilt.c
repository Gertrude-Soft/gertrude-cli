/*
** EPITECH PROJECT, 2023
** Gertrude-CLI
** File description:
** Prebuilt Makefile creation
*/

#include <stdlib.h>
#include <stdio.h>

#include "../include/text_mod.h"

void base_mkf(void)
{
    int err;

    err = system("cp /opt/gertrude-cli/gertrude_prebuilt_mkf/Makefile ./");
    if (err != 0) {
        printf("%sYou need to run gertrude as sudo in order to generate \
    a Makefile%s", RED, NC);
        exit(84);
    }
}
