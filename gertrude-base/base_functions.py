##
## GERTRUDE PROJECT, 2023
## GERTRUDE-CLI
## File description:
## Functions that are not related to Makefile or arguments handling
##

from gertrude import GREEN, RED, YELLOW, NC

UL = '\033[4m' # Underline
STOP = '\033[0m' # No Modification

def help():
    print(f"{RED}Gertrude HELP!")
    print(f"\n{GREEN}Gertrude-CLI, a Makefile tool{NC}")
    print(f"\n{YELLOW}USAGE:\n\n\
    {GREEN}gertrude{NC} DIRECTORY [--var variable[=value]]* [[-r rule] [--deps dependencies]* [--cmd command]*]* [-epi]\n\n")
    print(f"{YELLOW}DESCRIPTION:{NC}\n\n\
    DIRECTORY : Directory to the Makefile. No Makefile should exist there.\n\n\
    --var : Define {UL}variable{STOP} using {UL}value{STOP}. If {UL}value{STOP} is not provided, it will be initialised to 42.\n\n\
    -r : Define {UL}rule{STOP}. By default, the rule created runs 'echo New Rule'. C.F. --deps, --cmd\n\n\
    --deps : {UL}rule{STOP} will run {UL}dependencies{STOP}. Each --deps argument can only name one dependecy.\n\n\
    --cmd : {UL}rule{STOP} will run {UL}command{STOP}. Each --cmd argument can only state one command.\n\n\
    -epi : Preprends the Epitech Header (2023 style).")
