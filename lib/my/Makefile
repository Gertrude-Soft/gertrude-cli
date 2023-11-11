##
## EPITECH PROJECT, 2023
## B-CPE-100-LYN-1-1-cpoolday10-laurent.gonzalez
## File description:
## Makefile
##

SOURCE_FILES = $(wildcard *.c)

HEADER_FILE = my.h

LIB = libmy.a

all: compile lib cpy_lib cpy_header clean

compile: $(SOURCE_FILES)
	gcc -c $(SOURCE_FILES) -g3

lib:
	ar rcs $(LIB) *.o

cpy_lib: $(LIB)
	cp $(LIB) ../

cpy_header: $(HEADER_FILE)
	cp $(HEADER_FILE) ../../include/

clean:
	rm -f *.o *.gch

fclean:
	rm libmy.a
	rm ../libmy.a
	rm ../../include/my.h

re: fclean all
