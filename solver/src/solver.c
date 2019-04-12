/*
** EPITECH PROJECT, 2023
** Generator
** File description:
** Created by benjaminkuhnel,
*/

#include "../../include/my.h"
#include "../../include/dante.h"

int check_value(solver_t *solver, int x, int y)
{
    if (solver->int_maze[y][x] == -1)
        return (1);
    return (0);
}

void find_path(solver_t *solver, int x, int y, int value)
{
    if (y != 0 && check_value(solver, x, y - 1))
        solver->int_maze[y - 1][x] = value;
    if (x != 0 && check_value(solver, x - 1, y))
        solver->int_maze[y][x - 1] = value;
    if (check_value(solver, x + 1, y))
        solver->int_maze[y][x + 1] = value;
    if (solver->int_maze[y + 1] != NULL && check_value(solver, x, y + 1))
        solver->int_maze[y + 1][x] = value;
}

void breadth_algo(solver_t *solver, int value)
{
    for (int y = 0; solver->int_maze[y] != NULL; y++) {
        for (int x = 0; solver->int_maze[y][x] != END_LINE; x++) {
            if (solver->int_maze[y][x] == value - 1)
                find_path(solver, x, y, value);
            if (x + y > value)
                break;
        }
    }
}

void my_solver(solver_t *solver)
{
    solver->height = find_height_maze(solver->maze);
    solver->width = find_width_maze(solver->maze);
    int value = 1;

    transform_maze(solver);
    while (END_POINT == -1) {
        breadth_algo(solver, value);
        value++;
    }
    read_maze_transform(solver);
}