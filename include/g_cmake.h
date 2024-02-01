/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** g_cmake.h
*/

#ifndef G_CMAKE_H_
    #define G_CMAKE_H_

typedef struct targets_s {
    char *name;
    char *deps;
    char *cmds;
    struct targets_s *next;
} targets_t;

typedef struct vars_s {
    char *name;
    char *value;
    struct vars_s *next;
} vars_t;

typedef struct g_cmake_s {
    targets_t *targets;
    vars_t *vars;
    int multi;
    char *project_name;
    char *lang;
    char *exec;
    char **src_dir;
    char **cflags;
} g_cmake_t;

void get_name(g_cmake_t *project);
void set_src(g_cmake_t *project);

#endif /* !G_CMAKE_H_ */
