NAME = matrix_rain
SRC = src/main.c src/rain_scene.c src/list.c src/intro_scene.c src/string.c
INC = inc/header.h
CC = clang -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses
all: install clean
install:
	@cp $(SRC) $(INC) .
	@$(CC) $(SRC:src/%=%) -I $(INC:inc/%=%) -o $(NAME)
uninstall:
	@rm $(NAME)
clean:
	@rm $(SRC:src/%=%) $(INC:inc/%=%)
reinstall: uninstall all
