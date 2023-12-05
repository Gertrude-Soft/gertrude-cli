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
	sudo make clean -C lib/my
	sudo make clean -C gertrude_base
	sudo make clean -C /opt/gertrude-cli
	sudo rm -f vgcore*

fclean:
	rm -f libmy.a lib/my/libmy.a include/my.h lib/libmy.a
	make fclean -C gertrude_base

merge:	compile
	sudo cp -r * /opt/gertrude-cli
	@echo -e "\033[1;32mGood Plant\033[1;0m"

re: fclean	all
