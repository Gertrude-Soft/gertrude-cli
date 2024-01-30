/*
** GERTRUDE PROJECT, 2023;
** gertrude-cli
** File description:
** gertrude
*/

#ifndef GERTRUDE_H_
    #define GERTRUDE_H_

typedef struct g_tools_s {
    char *dir;
    char *variables;
    char *deps;
    char *cmds;
    char **rule_names;
    char *rules;
    char *header;
    char *phony;
} gertrude_t;

void help(int);
void parse_args(int ac, char **av, gertrude_t *ger);
void variable_def(char **av, int ac, int i, gertrude_t *ger);
void directory_def(gertrude_t *ger, char **av, int i);
void rule_def(char **av, int ac, int *i, gertrude_t *ger);
void base_mkf(void);
void gertrude_errors(char **av, int ac, int i, int error);
void print_header(gertrude_t *ger);
char *set_phony(gertrude_t *gertrude);


void free_gaza(gertrude_t *ger);

#endif /* !GERTRUDE_H_ */
