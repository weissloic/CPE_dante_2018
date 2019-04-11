/*
** EPITECH PROJECT, 2023
** Generator
** File description:
** Created by benjaminkuhnel,
*/

#include "../../include/my.h"
#include "../../include/dante.h"

void stock_maze(solver_t *solver)
{
    for (int y = 0; solver->maze[y] != NULL; y++) {
        for (int x = 0; solver->maze[y][x] != '\0'; x++) {
            if (solver->maze[y][x] == '*')
                solver->int_maze[y][x] = -1;
            if (solver->maze[y][x] == 'X')
                solver->int_maze[y][x] = -2;
        }
    }
    solver->int_maze[0][0] = 0;
}

int transform_maze(solver_t *solver)
{
    solver->int_maze = malloc(sizeof(int *) * (solver->height + 1));
    if (solver->int_maze == NULL)
        return (84);

    for (int i = 0; i < solver->height; i++) {
        solver->int_maze[i] = malloc(sizeof(int) * (solver->width + 1));
        if (solver->int_maze[i] == NULL)
            return (84);
        solver->int_maze[i][solver->width] = END_LINE;
    }
    solver->int_maze[solver->height] = NULL;
    stock_maze(solver);
    return (0);
}