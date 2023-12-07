/*
** EPITECH PROJECT, 2023
** gertrude-cli
** File description:
** error_handling
*/

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/my.h"
#include "../include/error_codes.h"
#include "../include/text_mod.h"
#include "../include/gertrude.h"
#include "../include/ger_conf.h"

const char *GERTRWARNS[] = {"Gertrude is trying to reach you for your extended warranty.",
                            "Gertrude is trying to get your mess in order.",
                            "Gertrude is wondering if you need help finding the right syntax.",
                            "Gertrude is giggling in her pot after that one.",
                            "Gertrude is wondering how she will explain this one.",
                            "Gertrude just got ran over.",
                            "Gertrude is staring at your soul.",
                            "Gertrude is having a seizure.",
                            "Gertrude grew out gray hair because of this.",
                            "Gertrude suggests you watch your language.",
                            "Gertrude is asking you politely to fix your request."};

const char *GERTERRORS[] = {"Gertrude is asking you to read the docs.",
                            "Criminal offensive plant eye.",
                            "Gertrude is getting reminiscent of 9/11 after what you just gave her.",
                            "Gertrude is crying in pain.",
                            "Gertrude has some serious questions for you.",
                            "Gertrude is doubting her existence.",
                            "Gertrude has been slain.",
                            "Gertrude can't get around your stupidity.",
                            "Gertrude is lost in words, code rather.",
                            "Gertrude is under utter shock.",
                            "Gertrude is left in shambles.",
                            "You just got invited to Gertrude's funeral!",
                            "Gertrude hasn't ever witnessed such malpractice."};

const char ERR21[42] = "** Variable affectation without value. **";
const char BERR21[40] = "Variable has been defaulted to empty \\.";

const char ERR42[47] = "** Variable or positional argument missing. **";
const char BERR42[43] = "Gertrude no understand, Exited with crash.";

const char ERR63[38] = "** No directory given as argument. **";
const char BERR63[43] = "Gertrude no understand, Exited with crash.";

const char ERR84[37] = "** Rule specified without a name. **";
const char BERR84[43] = "Gertrude no understand, Exited with crash.";

const char ERR105[48] = "** Dependency specified without a rule name. **";
const char BERR105[26] = "No dependencies affected.";

const char ERR126[42] = "** Command specified without following **";
const char BERR126[20] = "No commands affeced.";

static void error_header(char *gercode)
{
    char *err_name;

    if (strcmp(gercode, GERERR) == 0) {
        err_name = malloc(15);
        strcpy(err_name, "GERTRUDE ERROR");
    }
    if (strcmp(gercode, GERWARN) == 0) {
        err_name = malloc(17);
        strcpy(err_name, "GERTRUDE WARNING");
    }
    for (int i = 0; i < ERROR_WIDTH / 2 - (strlen(err_name) / 2); i++) {
        my_printf("=");
    }
    my_printf("%s%s%s", gercode, err_name, NC);
    for (int i = 0; i < ERROR_WIDTH / 2 - (strlen(err_name) / 2); i++) {
        my_printf("=");
    }
    my_printf("\n");
    free(err_name);
    return;
}

static void custom_gertrude_message(char *gercode)
{
    my_printf("== %s%s%s\n",
    FYELLOW,
    (strcmp(gercode, GERWARN) == 0) ?
    GERTRWARNS[rand() % 11] : GERTERRORS[rand() % 13],
    NC);
    return;
}

static int input_formating(char **av, int ac, int i, char *gercode)
{
    int count = 0;
    int err_index = ERROR_WIDTH;

    my_printf("%s=input=%s ", gercode, NC);
    for (int j = i - 1; j < ac && count <= ERROR_WIDTH - 9; j++) {
        if (i == j) {
            err_index = count + strlen(av[j]);
            my_printf("%s", RED);
        } else
            my_printf("%s", NC);
        for (int k = 0; k < strlen(av[j]) && count <= ERROR_WIDTH - 9; k++) {
            my_putchar(av[j][k]);
            count++;
        }
        if (j != ac - 1)
            count += my_printf(" ");
    }
    my_printf("%s\n", NC);
    return (err_index + 7);
}

static void point_to_error(char *error, int err_index, char *gercode)
{
    my_printf("==");
    for (int j = 0; j < ERROR_WIDTH; j++) {
        if (j == err_index - 2 || j == ERROR_WIDTH - 3  ) {
            my_printf("%s^%s", gercode, NC);
            break;
        }
        my_printf(" ");
    }
    my_printf("\n==");
    for (int j = 2; j < err_index && j < (ERROR_WIDTH - strlen(error)); j++)
        my_printf(" ");
    my_printf("%s%s%s\n", RED, error, NC);
}

static void input_error_formating(char **av, int ac, int i, char *gercode,
    char error[])
{
    int err_index;

    err_index = input_formating(av, ac, i, gercode);
    point_to_error(error, err_index, gercode);
    return;
}

static void put_behavior_bottom(char **av, int i, char *behavior, char *gercode)
{
    char *name;
    int size;
    int j;

    for (size = 0; av[i][size] != '\0' && av[i][size] != '=' && size != (ERROR_WIDTH - strlen(behavior) - 14); size++);
    name = malloc(size + 1);
    for (j = 0; j < size; j++) {
        name[j] = av[i][j];
    }
    name[j] = '\0';
    if (size == (ERROR_WIDTH - strlen(behavior) - 14)) {
        name[size - 3] = '.';
        name[size - 2] = '.';
        name[size - 1] = '.';
        name[size] = '\0';
    }
    my_printf("%s=behavior= %s'%s' %s%s%s\n", gercode, YELLOW, name, FYELLOW, behavior, NC);
    for (int j = 0; j < ERROR_WIDTH; j++)
        my_printf("=");
    my_printf("\n\n");
    free(name);
}

static void var_errors(char **av, int ac, int i, char *gercode)
{
    error_header(gercode);
    custom_gertrude_message(gercode);
    if (strcmp(gercode, GERWARN) == 0) {
        input_error_formating(av, ac, i, gercode, (char *)ERR21);
        put_behavior_bottom(av, i, (char *)BERR21, gercode);
    }
    if (strcmp(gercode, GERERR) == 0) {
        input_error_formating(av, ac, i, gercode, (char *)ERR42);
        put_behavior_bottom(av, i, (char *)BERR42, gercode);
        exit(84);
    }
}

static void dir_errors(char **av, int ac, int i, char *gercode)
{
    error_header(gercode);
    custom_gertrude_message(gercode);
    input_error_formating(av, ac, i, gercode, (char *)ERR63);
    put_behavior_bottom(av, i, (char *)BERR63, gercode);
    exit(84);
}

static void rule_errors(char **av, int ac, int i, char *gercode)
{
    error_header(gercode);
    custom_gertrude_message(gercode);
    input_error_formating(av, ac, i, gercode, (char *)ERR84);
    put_behavior_bottom(av, i, (char *)BERR84, gercode);
    exit(84);
}

static void dep_warn(char **av, int ac, int i, char *gercode)
{
    error_header(gercode);
    custom_gertrude_message(gercode);
    input_error_formating(av, ac, i, gercode, (char *)ERR105);
    put_behavior_bottom(av, i, (char *)BERR105, gercode);
}

static void cmd_warn(char **av, int ac, int i, char *gercode)
{
    error_header(gercode);
    custom_gertrude_message(gercode);
    input_error_formating(av, ac, i, gercode, (char *)ERR126);
    put_behavior_bottom(av, i, (char *)BERR126, gercode);
}

void gertrude_errors(char **av, int ac, int i, int error)
{
    if (error == VARWARN)
        var_errors(av, ac, i, GERWARN);
    if (error == VARERR)
        var_errors(av, ac, i, GERERR);
    if (error == DIRERR)
        dir_errors(av, ac, i, GERERR);
    if (error == RULERR)
        rule_errors(av, ac, i, GERERR);
    if (error == DEPWARN)
        dep_warn(av, ac, i, GERWARN);
    if (error == CMDWARN)
        cmd_warn(av, ac, i, GERWARN);
    if (error == 911)
        help(84);
    return;
}
