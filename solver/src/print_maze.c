/*
** EPITECH PROJECT, 2023
** Generator
** File description:
** Created bline benjaminkuhnel,
*/

#include "../../include/my.h"
#include "../../include/dante.h"

void read_maze_transform(solver_t *solver)
{
    int value = END_POINT - 1;
    int col = solver->width - 1;
    int line = solver->height - 1;

    while (line != 0 || col != 0) {
        if (col != 0 && solver->int_maze[line][col - 1] == value)
            col--;
        else if (solver->int_maze[line][col + 1] == value)
            col++;
        else if (line != 0 && solver->int_maze[line - 1][col] == value)
            line--;
        else
            line++;
        solver->maze[line][col] = 'o';
        value--;
    }
    solver->maze[solver->height - 1][solver->width - 1] = 'o';
}