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
    solver->map = get_map(av[1]);
    if (solver->map == NULL)
        return (84);

    while (solver->map[++i] != NULL)
        printf("%s\n", solver->map[i]);
    my_solver(solver);
    while (solver->map[++i] != NULL)
        printf("%s\n", solver->map[i]);
    return (0);
}