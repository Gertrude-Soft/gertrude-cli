/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Point of Entry
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#include "../include/my.h"
#include "../include/text_mod.h"
#include "../include/gertrude.h"
#include "../include/ger_conf.h"

void print_file(gertrude_t *ger)
{
    my_printf("%sFinalising...%s\n", YELLOW, NC);
    if (HEADER == true)
        print_header(ger);
    if (ger->variables != NULL)
        my_printf("%w", ger->dir, ger->variables);
    if (ger->rules != NULL)
        my_printf("%w", ger->dir, ger->rules);
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

static void configuration_command(void)
{
    char *command;

    command = malloc(strlen("sudo ") + strlen(EDITOR) + strlen(CONFDIR) + 2);
    strcpy(command, "sudo ");
    strcat(command, EDITOR);
    strcat(command, " ");
    strcat(command, CONFDIR);
    system(command);
    free(command);
    system("sudo make --silent -C /opt/gertrude-cli");
    exit(0);
}

int main(int ac, char **av)
{
    gertrude_t ger;
    int fd;

    srand(time(0));
    ger.dir = strdup("./Makefile");
    if (access(ger.dir, F_OK) == -1) {
        fd = open(ger.dir, O_CREAT);
        close(fd);
    }
    ger.variables = NULL;
    ger.rule_names = malloc(sizeof(NULL));
    ger.rule_names[0] = NULL;
    ger.deps = NULL;
    ger.cmds = NULL;
    ger.rules = strdup("\0");
    ger.header = DEFAULT_HEADER;
    my_printf("\n%sGertrude says Welcome!%s\n\n", GREEN, NC);
    if (ac == 1) {
        my_printf("%sGetting standard Makefile...%s\n", YELLOW, NC);
        base_mkf(&ger);
        my_printf("\n%sGood Plant%s\n", GREEN, NC);
        exit(0);
    }
    if (strcmp(av[1], "config") == 0) {
        configuration_command();
    } else if (strcmp(av[1], "update") == 0) {
        my_printf("%sGertrude is updating...%s\n", YELLOW, NC);
        system("sudo sh /opt/gertrude-cli/installer.sh");
        my_printf("%sSUCCESS!%s\n", GREEN, NC);
        exit(0);
    }
    parse_args(ac, av, &ger);
    ger.phony = set_phony(&ger);
    print_file(&ger);
    my_printf("\n%sGood Plant%s\n", GREEN, NC);
    free_gaza(&ger);
    return 0;
}
