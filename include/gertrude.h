/*
** EPITECH PROJECT, 2023
** gertrude-cli
** File description:
** gertrude
*/

#ifndef GERTRUDE_H_
    #define GERTRUDE_H_

typedef struct g_tools_s {
    int epitech;
    char *dir;
    char *variables;
} gertrude_t;

void help(int);
void parse_args(int ac, char **av, gertrude_t *ger);
void variable_def(char **av, int ac, int i, gertrude_t *ger);
void directory_def(gertrude_t *ger, char **av, int i);
void gertrude_errors(char **av, int ac, int i, int error);

#endif /* !GERTRUDE_H_ */
