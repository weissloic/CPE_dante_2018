/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "../../include/my.h"
#include "../../include/dante.h"

char **malloc_my_maze(generator_t *gen, char **maze)
{
    maze = malloc(sizeof(char *) * (gen->pos_y + 2));
    if (maze == NULL)
        return (NULL);
    int i = 0;
    for (i = 0; i <= gen->pos_y; i++)
        maze[i] = malloc(sizeof(char) * (gen->pos_x + 1));

    if (maze[0] == NULL)
        return (NULL);

    maze[i] = NULL;

    return (maze);
}

void hit_perfect(char **maze, generator_t *gen)
{
    int i = 0;
    int y = 0;
    int x = 0;
    int number = (gen->pos_x * gen->pos_y) / 2;

    for (i; i < number; i++) {
        y = rand() % gen->pos_x;
        x = rand() % gen->pos_y;
        maze[x][y] = '*';
    }
}

int main(int ac, char **av)
{
    generator_t *gen = malloc(sizeof(generator_t));
    char **maze = NULL;
    srand(getpid() * time(NULL));
    gen->top = 0;
    gen->right = 0;
    if (ac == 3) {
        if (get_number(gen, av) == 84) return (84);
        if (!(maze = malloc_my_maze(gen, maze))) return (84);
        gen_no_perfect(maze, gen);
    }
    else if (ac == 4 && my_strcmp(av[3], "perfect") == 0) {
        if (get_number(gen, av) == 84) return (84);
        if (!(maze = malloc_my_maze(gen, maze))) return (84);
        gen_perfect(maze, gen);
    }
    else
        return (84);
}