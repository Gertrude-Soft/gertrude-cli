/*
** EPITECH PROJECT, 2023
** Gertrude-CLI
** File description:
** Manages directory definition
*/
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "../include/gertrude.h"
#include "../include/text_mod.h"
#include "../include/my.h"

int is_dir(char *av)
{
    struct stat *statbuf = (struct stat *) malloc(sizeof(struct stat));

    if (av[0] != '-') {
        statbuf->st_mode = 0;
        stat(av, statbuf);
        switch (statbuf->st_mode & S_IFMT) {
        case S_IFDIR:
            free(statbuf);
            return 1;
        default:
            free(statbuf);
            return 0;
        }
    }
    free(statbuf);
    return 0;
}

void directory_def(gertrude_t *ger, char **av, int i)
{
    int fd;

    if (is_dir(av[i])) {
        ger->dir = malloc(my_strlen(av[i]) + 10);
        my_printf("%sChanging directory...%s\n", YELLOW, NC);
        strcpy(ger->dir, av[i]);
        strcat(ger->dir, "/Makefile");
    } else {
        my_printf("\n%sGertrude says: please enter a valid\
        directory!%s\n", RED, NC);
        exit(84);
    }
    if (access(ger->dir, F_OK) == -1) {
        fd = open(ger->dir, O_CREAT);
        close(fd);
    }
}
