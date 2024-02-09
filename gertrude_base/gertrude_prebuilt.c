/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Prebuilt Makefile creation
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

#include "../include/my.h"
#include "../include/text_mod.h"
#include "../include/gertrude.h"
#include "../include/ger_conf.h"

static char *file_extension(char *file)
{
    int right = strlen(file) - 1;

    for (; right >= 0 && file[right] != '.'; right--);
    return file + right;
}

static bool isdir(const char *path) {
    struct stat st;

    if (path == NULL) {
        return false;
    }
    stat(path, &st);
    return S_ISDIR(st.st_mode) == 1 ? true : false;
}

void append_file(gertrude_t *ger, char *file_name)
{
    my_printf("%w", ger->dir, "\t");
    my_printf("%w", ger->dir, file_name);
    my_printf("%w", ger->dir, "\t\t\t\n");
}

void append_src(gertrude_t *ger, char *directory)
{
    DIR *dir = opendir(directory);
    struct dirent *content;

    if (dir == NULL)
        return;
    while (true) {
        content = readdir(dir);
        if (content == NULL)
            return;
        if (isdir(content->d_name))
            append_src(ger, content->d_name);
        if (strcmp(file_extension(content->d_name), ".c"))
            append_file(ger, content->d_name);
    }
}

void base_mkf(gertrude_t *ger)
{
    my_printf("%sFinalising...%s\n", YELLOW, NC);
    if (HEADER == true)
        print_header(ger);
    // if (ger->variables != NULL)
    //     my_printf("%w", ger->dir, ger->variables);
    append_src(ger, "./");
    // if (ger->rules != NULL)
    //     my_printf("%w", ger->dir, ger->rules);
    if (REMARKABLE == true) {
        my_printf("%w", ger->dir, REM_ALL);
        my_printf("%w", ger->dir, REM_COMPILE);
        my_printf("%w", ger->dir, REM_CLEAN);
        my_printf("%w", ger->dir, REM_FCLEAN);
        my_printf("%w", ger->dir, REM_RE);
    }
    my_printf("%w", ger->dir, REM_GERTRUDE);
    if (AUTO_PHONY == true && ger->phony != NULL)
        my_printf("%w", ger->dir, ger->phony);
}
