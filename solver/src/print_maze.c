/*
** EPITECH PROJECT, 2023
** Generator
** File description:
** Created bline benjaminkuhnel,
*/

#include "../../include/my.h"
#include "../../include/dante.h"

int transform_col(solver_t *solver, int *x, int y, int value)
{
    if (*x != 0 && solver->int_maze[y][*x - 1] == value) {
        (*x)--;
        return (1);
    } else if (solver->int_maze[y][*x + 1] == value) {
        (*x)++;
        return (1);
    }
    return (0);
}

void transform_line(solver_t *solver, int x, int *y, int value)
{
    if (*y != 0 && solver->int_maze[*y - 1][x] == value) {
        (*y)--;
    } else {
        (*y)++;
    }
}

void read_maze_transform(solver_t *solver)
{
    int value = END_POINT - 1;
    int col = solver->width - 1;
    int line = solver->height - 1;

    while (line != 0 || col != 0) {
        if (!transform_col(solver, &col, line, value))
            transform_line(solver, col, &line, value);
        solver->maze[line][col] = 'o';
        value--;
    }
    LAST_POINT = 'o';
}