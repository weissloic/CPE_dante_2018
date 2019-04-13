/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../../include/my.h"
#include "../../include/dante.h"

void gen_no_perfect(char **maze, generator_t *gen)
{
    maze = create_maze(maze, gen);
    transform_array(gen, maze);
    hit_perfect(maze, gen);
    print_maze(maze, gen);
}

void gen_perfect(char **maze, generator_t *gen)
{
    maze = create_maze(maze, gen);
    transform_array(gen, maze);
    print_maze(maze, gen);
}

void create_lab(char **maze, int i, int j, generator_t *gen)
{
    int value = rand() % 2;
    if (i - 1 >= 0 && maze[i - 1][j] == 'X')
        gen->top = 1;
    if (j - 1 >= 0 && maze[i][j - 1] == 'X')
        gen->right = 1;
    if (i - 1 >= 0 && gen->top == 1 && gen->right == 0)
        maze[i - 1][j] = '*';
    if (j - 1 >= 0 && gen->top == 0)
        maze[i][j - 1] = '*';
    if (j - 1 >= 0 && value == 0)
        maze[i][j - 1] = '*';
    else if (i - 1 >= 0 && value == 1)
        maze[i - 1][j] = '*';
}

void transform_array(generator_t *gen, char **maze)
{
    int i = 0;
    int j = 0;

    for (i; i <= gen->pos_y; i += 2) {
        j = 0;
        gen->top = 0;
        gen->right = 0;
        for (j; j < gen->pos_x; j += 2) {
            if (i == 0)
                maze[i][j] = '*';
            create_lab(maze, i, j, gen);
        }
    }
}

void print_maze(char **maze, generator_t *gen)
{
    int i = 0;
    maze[gen->pos_y - 1][gen->pos_x - 1] = '*';

    while (i < gen->pos_y - 1) {
        write(1, maze[i++], gen->pos_x);
        write(1, "\n", 1);
    }
    write(1, maze[i], gen->pos_x);
}