/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include "../include/get_next_line.h"

int main(int ac, char **av)
{
    generator_t *gen = malloc(sizeof(generator_t));

    if (ac == 3) {
        if (get_number(gen, av) == 84)
            return (84);
        printf("no perfect\n");
    }
    else if (ac == 4 && my_strcmp(av[3], "perfect") == 0) {
        if (get_number(gen, av) == 84)
            return (84);
        printf("Perfect\n");
    }
    else
        return (84);
}

int get_number(generator_t *gen, char **av)
{
    gen->pos_x = atoi(av[1]);
    gen->pos_y = atoi(av[2]);

    if (gen->pos_x <= 0 || gen->pos_y <= 0)
        return (84);
}