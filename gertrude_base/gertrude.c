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

static void print_file(gertrude_t *ger)
{
    my_printf("\n\n-------OUTPUT------\n"); // START OF DEBUG PRINTF
    if (HEADER == TRUE)
        my_printf("%s", ger->header);
    if (ger->variables != NULL)
        my_printf("%s", ger->variables);
    if (REMARKABLE == TRUE) {
        my_printf("%s", REM_ALL);
        my_printf("%s", REM_CLEAN);
        my_printf("%s", REM_FCLEAN);
        my_printf("%s", REM_RE);
    }
    my_printf("%s", REM_GERTRUDE);
    if (AUTO_PHONY == TRUE && ger->phony != NULL)
        my_printf("%s", ger->phony);
    my_printf("\n---------------------\n"); // END OF DEBUG PRINTF (replace %s with %w for deployment)
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
    system("sudo make --silent -C /opt/gertrude-cli");
    exit(0);
}

int main(int ac, char **av)
{
    gertrude_t ger;
    int fd;

    srand(time(0));
    ger.dir = "./Makefile";
    if (access(ger.dir, F_OK) == -1) {
        fd = open(ger.dir, O_CREAT);
        close(fd);
    }
    ger.epitech = 0;
    ger.variables = NULL;
    ger.header = DEFAULT_HEADER;
    ger.rule_names = NULL;
    my_printf("\n%sGertrude says Welcome!%s\n\n", GREEN, NC);
    if (ac == 1) {
        base_mkf();
        exit(0);
    }
    if (strcmp(av[1], "config") == 0) {
        configuration_command();
    } else if (strcmp(av[1], "update") == 0) {
        my_printf("%sGertrude is updating...%s\n", YELLOW, NC);
        system("sh ./installer.sh");
        my_printf("%sSUCCESS!%s\n", GREEN, NC);
        exit(0);
    }
    parse_args(ac, av, &ger);
    my_printf("%sFinalising...%s\n", YELLOW, NC);
    ger.phony = set_phony(&ger);
    print_file(&ger);
    my_printf("\n%sGood Plant%s\n", GREEN, NC);
}
