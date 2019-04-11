/*
** EPITECH PROJECT, 2023
** Generator
** File description:
** Created by benjaminkuhnel,
*/

#include "../../include/my.h"
#include "../../include/dante.h"

void find_size_maze(solver_t *solver)
{
    solver->height = 0;

    for (int i = 0; solver->map[i] != NULL; i++)
        solver->height += 1;
    solver->width = my_strlen(solver->map[0]);
}

int	resolve(solver_t *solver, int i, int j)
{
    if (i > solver->height || j > solver->width || i < 0 || j < 0 ||
        solver->map[i][j] != '*')
        return (-1);
    if ((i == solver->height && j == solver->width - 1) ||
        (i + 1 > 0 && resolve(solver, i + 1, j)) == 0 ||
        (resolve(solver, i, j - 1)) == 0 ||
        (resolve(solver, i, j + 1)) == 0 ||
        (resolve(solver, i - 1, j)) == 0) {
        solver->map[i][j] = 'o';
        return (0);
    }
    return (-1);
}

void my_solver(solver_t *solver)
{
    find_size_maze(solver);
    resolve(solver, 0, 0);
}