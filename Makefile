##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
## File description:
## Makefile
##

all:	compile	clean

compile:
	make -C gertrude_base

clean:
	sudo make clean -C gertrude_base
	sudo rm -f vgcore*

fclean:
	make fclean -C gertrude_base

gclean:	clean
	sudo make clean -C /opt/gertrude-cli

merge:	compile
	sudo cp -r * /opt/gertrude-cli
	@echo -e "\033[1;32mGood Plant\033[1;0m"

re: fclean all
