/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** g_cmake.c
*/

#include "../include/g_cmake.h"
#include "../include/ger_conf.h"
#include "../include/text_mod.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void set_suf(char *suffix, int i)
{
    if (i % 10 == 1) {
        suffix = strdup("st");
        return;
    }
    if (i % 10 == 2) {
        suffix = strdup("nd");
        return;
    }
    if (i % 10 == 3) {
        suffix = strdup("rd");
        return;
    }
    suffix = strdup("th");
}

void sing_dir(g_cmake_t *project)
{
    int size;
    char *buf = malloc(32000);

    printf("%sEnter the relative path to source (from project root): %s", GREEN, YELLOW);
    size = read(0, buf, 32000);
    buf[size] = '\0';
    printf("%s", NC);
    if (strcmp(buf, "\n") == 0) {
        fprintf(stderr, "%sWARNING: No source directory set!\n%s", YELLOW, NC);
        free(buf);
        return;
    }
    project->src_dir = malloc(sizeof(char *) + sizeof(NULL));
    project->src_dir[0] = strdup(buf);
    project->src_dir[1] = NULL;
}

void mult_dir(g_cmake_t *project)
{
    int i = 1;
    int size;
    char *suffix;
    char *buf = malloc(32000);

    project->multi = 1;
    while (TRUE) {
        set_suf(suffix, i);
        printf("%s%d%s directory: (leave empty to finish)%s", GREEN, i, suffix, YELLOW);
        size = read(0, buf, 32000);
        buf[size] = '\0';
        printf("%s", NC);
        if (strcmp(buf, "\n") == 0)
            break;
        project->src_dir = realloc(project->src_dir, i * sizeof(char *) + sizeof(NULL));
        project->src_dir[i - 1] = strdup(buf);
        project->src_dir[i] = NULL;
        i ++;
    }
    if (project->src_dir == NULL) {
        project->multi = 0;
        fprintf(stderr, "%sWARNING: No source directory set!\n%s", YELLOW, NC);
        free(buf);
        free(suffix);
        return;
    }
    printf("%sTotal directories: %d%s\n", GREEN, i - 1, NC);
    free(buf);
    free(suffix);
}

void set_src(g_cmake_t *project)
{
    int size;
    char *buf = malloc(32000);

    printf("%sDo you have multiple source directories? (y/any)%s ", YELLOW, NC);
    size = read(0, buf, 1);
    buf = realloc(buf, size + 1);
    buf[size] = '\0';
    if (strcmp(buf, "y") == 0)
        mult_dir(project);
    else
        sing_dir(project);
    return;
}
