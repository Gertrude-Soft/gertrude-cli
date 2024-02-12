##
## EPITECH PROJECT, 2023
## Gertrude-CLI
## File description:
## A Makefile tool's... Makefile
##

SRC	=	$(wildcard *.c)	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	gertrude-cli

CFLAGS	+=	-Wall -g3 -I../include

all:	build	clean

build:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f vgcode.* coding-style-reports.log $(OBJ) *.gch

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
