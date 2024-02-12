/*
** EPITECH PROJECT, 2023
** gertrude-cli
** File description:
** my_write_in_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/text_mod.h"

int write_in_file(const char *filename, const char *string)
{
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        fprintf(stderr,
        "%sGertrude says: you need to give an existing file! (%s)%s\n",
        RED, filename, NC);
        return (84);
    }
    fprintf(file, "%s", string);
    fclose(file);
    return (0);
}
