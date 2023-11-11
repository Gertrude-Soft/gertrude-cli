##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
## File description:
## Makefile
##

all: compile mv

compile:
	make -C lib/my

mv:
	cp lib/libmy.a .

clean:
	make clean -C lib/my

fclean:
	rm -f libmy.a lib/my/libmy.a include/my.h lib/libmy.a

re: all
