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
    maze = malloc(sizeof(char *) * (gen->pos_y));
    if (maze == NULL)
        return (84);
    int i = 0;
    for (i = 0; i <= gen->pos_y; i++)
        maze[i] = malloc(sizeof(char) * (gen->pos_x));

    if (maze[0] == NULL)
        return (84);

    maze[i] = NULL;

    return (maze);
}

int main(int ac, char **av)
{
    generator_t *gen = malloc(sizeof(generator_t));

    char **maze = NULL;
    srand(1390 * time(NULL));
    if (ac == 3) {
        if (get_number(gen, av) == 84)
            return (84);
        maze = malloc_my_maze(gen, maze);
        gen_no_perfect(maze, gen);
    }
    else if (ac == 4 && my_strcmp(av[3], "perfect") == 0) {
        if (get_number(gen, av) == 84)
            return (84);
        maze = malloc_my_maze(gen, maze);
        gen_no_perfect(maze, gen);
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

char **create_maze(char **maze, generator_t *gen)
{
    int i = 0;
    int j = 0;

    while (i  < gen->pos_y) {
        j = 0;
        while (j < gen->pos_x) {
            if (j % 2 == 0 && i % 2 == 0)
                maze[i][j] = '*';
            else if (j % 2 != 0 && i % 2 == 0)
                maze[i][j] = 'X';
            else if (i % 2 != 0)
                maze[i][j] = 'X';
            j++;
        }
        i++;
    }
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
        if (maze[y][x] == 'X')
            maze[y][x] = '*';
    }
}

void gen_no_perfect(char **maze, generator_t *gen)
{
    gen->top = 0;
    gen->right = 0;
    maze = create_maze(maze, gen);
    transform_array(gen, maze);
    hit_perfect(maze, gen);
    print_maze(maze, gen);
}

void create_lab(char **maze, int i, int j, generator_t *gen)
{
    int value = rand() % 2;
    if (i - 1 >= 0 && maze[i - 1][j] == 'X')
        gen->top = 1;
    if (j - 1 >= 0 && maze[i][j - 1] == 'X')
        gen->right = 1;
    if (i - 1 >= 0 && gen->top == 1 && gen->right == 0)
        maze[i - 1][j] = '*';
    if (j - 1 >= 0 && gen->top == 0 && gen->right == 1)
        maze[i][j - 1] = '*';
    if (j - 1 >= 0 && value == 0)
        maze[i][j - 1] = '*';
    else if (i - 1 >= 0 && value == 1)
        maze[i - 1][j] = '*';
}

void transform_array(generator_t *gen, char **maze)
{
    int i = 0;
    int j = 0;

    for (i; i <= gen->pos_y; i += 2) {
        j = 0;
        gen->top = 0;
        gen->right = 0;
        for (j; j < gen->pos_x; j += 2) {
            if (i == 0)
                maze[i][j] = '*';
            create_lab(maze, i, j, gen);
        }
    }
}

void print_maze(char **maze, generator_t *gen)
{
    int i = 0;
    int j = 0;

    maze[gen->pos_x][gen->pos_y] = '*';
    maze[gen->pos_x - 2][gen->pos_y - 1] = '*';
    maze[gen->pos_x - 1][gen->pos_y - 2] = '*';
    maze[gen->pos_y - 1][gen->pos_x - 1] = '*';

    while (i < gen->pos_y) {
        j = 0;
        while (j < gen->pos_x) {
                printf("%c", maze[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}