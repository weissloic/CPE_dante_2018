/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "../../include/dante.h"
#include "../../include/my.h"

int main(int ac, char **av)
{
    solver_t *solver = malloc(sizeof(solver_t));
    int i = -1;

    if (ac != 2) {
        my_printf("Bad Argument !\n");
        return (84);
    }
    solver->maze = get_map(av[1]);
    if (solver->maze == NULL)
        return (84);

    my_solver(solver);
    i = -1;
    while (solver->maze[++i] != NULL) {
        write(1, solver->maze[i], solver->width);
        write(1, "\n", 1);
    }
    return (0);
}