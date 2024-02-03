/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** g_cmake.c
*/

#include "../include/g_cmake.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void init_struct(g_cmake_t *project)
{
    project->exec = NULL;
    project->lang = NULL;
    project->vars = NULL;
    project->cflags = NULL;
    project->src_dir = NULL;
    project->targets = NULL;
    project->project_name = NULL;
    project->multi = 0;
}

int cmake_interactive(int advanced)
{
    g_cmake_t project;

    init_struct(&project);
    get_name(&project);
    set_src(&project);
    if (advanced) {
        printf("== ADVANCED SETTINGS ==\n\n");
        set_cflags(&project);
    }
    return 0;
}
