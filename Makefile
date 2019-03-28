##
## EPITECH PROJECT, 2018
## Makefile perso
## File description:
## Makefile command
##

NAME_TEST = unit_tests

all:
	make -s -C generator/
	make -s -C solver/

clean :
	make clean -s -C generator/
	make clean -s -C solver/

fclean:		clean
	make fclean -s -C generator/
	make fclean -s -C solver/


re:		fclean all

test_run:
		@echo "$[TESTS] Start tests..."
		gcc tests/tests.c -o $(NAME_TEST) -L. -lmy --coverage -lcriterion
		./unit_tests
		@gcovr --exclude tests/
		@echo "$[TESTS] End tests..."
		@rm *.g*

create_dir:
	@mkdir -p obj
