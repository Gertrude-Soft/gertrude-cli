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
#include <string.h>

// This is fucking shit but idk how to make it efficient also I'm lazy
// (malloc(32000))
static void different_exec(g_cmake_t *project)
{
    char *buf = malloc(32000);
    int size;

    printf("%sWhat do you want to name your executable? %s", GREEN, YELLOW);
    size = read(0, buf, 32000);
    buf[size] = '\0';
    printf("%s", NC);
    if (strcmp(buf, "\n") == 0) {
        fprintf(stderr, "%sWARNING: No executable name defined, defaulting to './a.out'%s\n", YELLOW, NC);
        buf = strdup("./a.out");
    }
    project->exec = strdup(buf);
    free(buf);
}

static void set_exec(g_cmake_t *project)
{
    char *buf = malloc(32000);
    int size;

    printf("%sWould you like to set the executable to %s? (y/any) %s", GREEN, project->project_name,YELLOW);
    size = read(0, buf, 1);
    buf[size] = '\0';
    printf("%s", NC);
    if (strcmp(buf, "y") == 0) {
        project->exec = strdup(project->project_name);
        printf("%sExecutable name set: %s.\n%s", GREEN, project->exec, NC);
        free(buf);
        return;
    } else {
        different_exec(project);
        printf("%sExecutable set to %s.%s\n", GREEN, project->exec, NC);
    }
    free(buf);
}

void get_name(g_cmake_t *project)
{
    int size;
    char *buf = malloc(32000);

    printf("%sWhat is your project's name?%s\n\n", GREEN, NC);
    size = read(0, buf, 32000);
    buf[size] = '\0';
    project->project_name = strdup(buf);
    printf("\n");
    set_exec(project);
}
