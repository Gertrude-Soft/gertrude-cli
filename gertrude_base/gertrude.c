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

int main(int ac, char **av)
{
    gertrude_t ger;
    int fd;
    char *command;

    srand(time(0));
    ger.dir = "./Makefile";
    if (access(ger.dir, F_OK) == -1) {
        fd = open(ger.dir, O_CREAT);
        close(fd);
    }
    ger.epitech = 0;
    ger.variables = NULL;
    ger.rule_names = NULL;
    ger.deps = NULL;
    ger.cmds = NULL;
    ger.rules = NULL;
    ger.header = DEFAULT_HEADER;
    my_printf("\n%sGertrude says Welcome!%s\n\n", GREEN, NC);
    if (ac == 1) {
        base_mkf();
        exit(0);
    }
    if (strcmp(av[1], "config") == 0) {
        command = malloc(strlen("sudo ") + strlen(EDITOR) + strlen(CONFDIR) + 2);
        strcpy(command, "sudo ");
        strcat(command, EDITOR);
        strcat(command, " ");
        strcat(command, CONFDIR);
        system(command);
        system("sudo make --silent -C /opt/gertrude-cli");
        exit(0);
    } else if (strcmp(av[1], "update") == 0) {
        my_printf("%sGertrude is updating...%s\n", YELLOW, NC);
        system("sh ./installer.sh");
        my_printf("%sSUCCESS!%s\n", GREEN, NC);
        exit(0);
    }
    parse_args(ac, av, &ger);
    my_printf("%sFinalising...%s\n", YELLOW, NC);
    // my_printf("%w", ger.dir, ger.variables);
    // if (HEADER == TRUE)
    //     my_printf("%w", ger.dir, ger.header);
    // if (REMARKABLE == TRUE) {
    //     my_printf("%w", ger.dir, REM_ALL);
    //     my_printf("%w", ger.dir, REM_CLEAN);
    //     my_printf("%w", ger.dir, REM_FCLEAN);
    //     my_printf("%w", ger.dir, REM_RE);
    // }
    // my_printf("%w", ger.dir, REM_GERTRUDE);
    my_printf("\n%sGood Plant%s\n", GREEN, NC);
}
