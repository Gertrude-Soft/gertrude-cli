/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** g_cmake.c
*/

#include "../include/text_mod.h"
#include "../include/g_cmake.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void set_exec(g_cmake_t *project)
{
    printf("%sWould you like to set the executable to %s? %s", GREEN, project->project_name,YELLOW);
}

void get_name(g_cmake_t *project)
{
    int size;

    project->project_name = malloc(32000);
    printf("%sWhat is your project's name?%s\n\n", GREEN, NC);
    size = read(0, project->project_name, 32000);
    project->project_name = realloc(project->project_name, size + 1);
    project->project_name[size] = '\0';
    printf("\n");
    set_exec(project);
}
