##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the lib
##

CC	=	gcc -g

SRC	=	my_compute_square_root.c	\
		my_compute_power_rec.c		\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_is_prime.c				\
		my_isneg.c					\
		my_put_nbr.c				\
		my_putchar.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_strupcase.c				\
		my_swap.c					\
		print_base.c				\
		print_basicfunc.c			\
		print_float.c				\
		printf.c                    \
		my_memset.c                 \
		get_next_line.c             \
		str_to_word_tab.c           \

OBJ  	= $(SRC:%.c=obj/%.o)

NAME 	= libmy.a

PREFIX  = "[LIB] "

all:	 create_dir $(NAME)

obj/%.o: %.c
	@$(CC) -c -o $@ $^
	@echo "$(PREFIX)$^ => $@"

$(NAME):  $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(PREFIX)Created $(NAME) !"

clean:
	rm -f *~ *# obj/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all clean

create_dir:
		mkdir -p obj
