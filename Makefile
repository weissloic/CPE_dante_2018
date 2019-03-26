##
## EPITECH PROJECT, 2018
## Makefile perso
## File description:
## Makefile command
##

CC	=	gcc -g

CFLAGS	=	-W -Wextra -Wall
CINC	=   -I include/
LDFLAGS =   -Llib/my -lmy -lm

NAME	=	lem_in

NAME_TEST = unit_tests

SRC 	=   src/main.c\
            src/get_next_line.c\
			src/str_to_word_tab.c\

PREFIX	=	"[MAIN] "

OBJ  	= $(SRC:%.c=%.o)

all:	$(NAME)

%.o: src/%.c
	$(CC) -c -o $@ $^
	echo "$(PREFIX)$^ => $@"

$(NAME): $(OBJ)
		@echo "[LIB] Compiling..."
		make -sC lib/my
		make -sC solver/
		make -sC generator/
		make -sC tournament/
		@echo "$(PREFIX)Compiling..."
		@$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(CINC) $(LDFLAGS)
		@echo "$(PREFIX)Compiled ! $(NAME)"

clean :
		@echo "$(PREFIX)Delete ! .~ and .# folder"
		@rm -f *~ *# *.o

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
		@echo "$[TESTS] End tests..."
		@rm *.g*


