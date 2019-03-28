##
## EPITECH PROJECT, 2018
## Makefile perso
## File description:
## Makefile command
##

CC	=	gcc -g

CFLAGS	=	-W -Wextra -Wall
CINC	=   -I../include/
LDFLAGS =   -L../lib/my -lmy -lm

NAME	=	solver

NAME_TEST = unit_tests

SRC 	= 	src/main.c\
			src/get_next_line.c\
			src/str_to_word_tab.c\

OBJ 	=	$(SRC:src/%.c=obj/%.o)

PREFIX	=	"[SOLVER] "

all:	create_dir $(NAME)

obj/%.o: src/%.c
	$(CC) -c -o $@ $^

$(NAME): $(OBJ)
		@echo "[LIB] $(BLUE)Compiling..."
		make -sC ../lib/my
		@echo "$(PREFIX)Compiling..."
		$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(CINC) $(LDFLAGS)
		cp $(NAME) ../tournament/$(NAME)
		@echo "$(PREFIX)Compiled ! $(NAME)"

clean :
		@echo "$(PREFIX)Delete ! .~ and .# folder"
		@rm -f *~ *#

fclean:		clean
		@echo "$(PREFIX)Delete ! $(NAME)"
		@rm -f $(NAME)
		@rm -f lib/my/libmy.a

re:		fclean all clean

test_run:
		@echo "$[TESTS] Start tests..."
		gcc tests/tests.c -o $(NAME_TEST) -L. -lmy --coverage -lcriterion
		./unit_tests
		@gcovr --exclude tests/
		@echo "[TESTS] End tests..."
		@rm *.g*

create_dir:
		mkdir -p obj
