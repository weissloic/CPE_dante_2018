/*
** EPITECH PROJECT, 2019
** dante
** File description:
** my
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef DANTE_H_
#define DANTE_H_

typedef struct s_generator {
    int pos_x;
    int pos_y;
} generator_t;

typedef struct s_solver {
    char **map;
} solver_t;

// GENERATOR
int get_number(generator_t *, char **);

char **my_str_to_word_array(char const *);

#endif /* DANTE_H_ */
