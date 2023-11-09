##
## GERTRUDE PROJECT, 2023
## GERTRUDE-CLI
## File description:
## A CLI-based Makefile tool
##

from base_functions import *
import sys

GREEN = '\033[1;32m'
RED = '\033[1;31m'
YELLOW = '\033[1;33m'
NC = '\033[1;0m'

def parse_args(args):
    for i in range(len(args)):
        if args[i] == "-h":
            help()
            exit(0)
        elif args[i] == "--var":
            i += 1
            variable_def(args, i)

def main():
    print(f"{GREEN}Gertrude says Welcome!{NC}")
    args = sys.argv[1:]
    parse_args(args)

if __name__ == '__main__':
    main()
