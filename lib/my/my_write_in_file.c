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

#include "my.h"
#include "../../include/text_mod.h"

static void parse_buffer(char *buffer, format_t *lp, const char *string)
{
    int c = 0;
    int i = 0;

    for (i = 0; lp->precision - 1 > c && buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            c++;
    }
    if (c < lp->precision - 1) {
        my_printf("INVALID PRECISION: %%1.{x}w ==> %s",
        "x superior than maximum number of lines.");
        exit(84);
    }
    buffer[i] = '\0';
    strcat(buffer, string);
}

int write_in_file(const char *string, const char *filename, format_t *lp)
{
    FILE *fd = fopen(filename, "r+");
    char buffer[32000];

    if (string == NULL)
        return (1);
    if (fd == NULL) {
        my_printf("%sGertrude says: you need to give an existing file!%s\n",
        RED, NC);
        return (84);
    }
    fread(buffer, 1, sizeof(buffer), fd);
    if (lp->length == 0) {
        strcpy(buffer, string);
        fwrite(buffer, 1, strlen(buffer), fd);
    } else if (lp->length == 1) {
        parse_buffer(buffer, lp, string);
        fclose(fopen(filename, "w"));
        fseek(fd, 0, SEEK_SET);
        fwrite(buffer, 1, strlen(buffer), fd);
    }
    fclose(fd);
    return (0);
}
