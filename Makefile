##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
## File description:
## Makefile
##

all:	compile	mv

compile:	clib	mv
	make -C ./gertrude_base/

clib:
	make -C lib/my

mv:
	cp lib/libmy.a .

clean:
	make clean -C lib/my
	make clean -C gertrude_base

fclean:
	rm -f libmy.a lib/my/libmy.a include/my.h lib/libmy.a
	make fclean -C gertrude_base

re: fclean	all
