/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/


#include "../../include/my.h"
#include "../../include/dante.h"

int get_number(generator_t *gen, char **av)
{
    gen->pos_x = atoi(av[1]);
    gen->pos_y = atoi(av[2]);

    if (gen->pos_x <= 0 || gen->pos_y <= 0)
        return (84);
    return (0);
}

char **create_maze(char **maze, generator_t *gen)
{
    int i = 0;
    int j = 0;

    for (int i = 0; i < gen->pos_y; i++) {
        for (int j = 0; j < gen->pos_x; j++) {
            fill_maze(maze, i, j);
        }
    }
    return (maze);
}

void fill_maze(char **maze, int i, int j)
{
    if (j % 2 == 0 && i % 2 == 0)
        maze[i][j] = '*';
    else if (j % 2 != 0 && i % 2 == 0)
        maze[i][j] = 'X';
    else if (i % 2 != 0)
        maze[i][j] = 'X';
}