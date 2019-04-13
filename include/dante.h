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
#include <string.h>
#include <unistd.h>

#ifndef DANTE_H_
#define DANTE_H_

#define START_POINT (solver->int_maze[0][0])
#define END_POINT (solver->int_maze[solver->height - 1][solver->width - 1])
#define LAST_POINT (solver->maze[solver->height - 1][solver->width - 1])
#define END_LINE (-5)

typedef struct s_generator {
    int right;
    int top;
    int pos_x;
    int pos_y;
} generator_t;

typedef struct s_solver {
    int **int_maze;
    char **maze;
    int height;
    int width;
} solver_t;

/*----------------- GENERATOR ----------------------*/
// MAIN
char **malloc_my_maze(generator_t *, char **);
void hit_perfect(char **, generator_t *);

// PERFECT
int get_number(generator_t *, char **);
char **create_maze(char **, generator_t *);
void fill_maze(char **, int, int);

//ALGORITHM
void gen_no_perfect(char **, generator_t *);
void gen_perfect(char **, generator_t *);
void transform_array(generator_t *, char **);
void print_maze(char **, generator_t *);


/*----------------- SOLVER ----------------------*/
// MAIN

// SOLVER
void my_solver(solver_t *);
int	resolve(solver_t *, int, int);
void find_size_maze(solver_t *);

// STOCK_MAP
char *get_buffer(char *);
char **get_map(char *);

// TRANSFORM_MAZE
void stock_maze(solver_t *);
int transform_maze(solver_t *);

// PRINT_MAZE
void read_maze_transform(solver_t *);

// UTILS
int find_height_maze(char **);
int find_width_maze(char **);

#endif /* DANTE_H_ */
