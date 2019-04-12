/*
** EPITECH PROJECT, 2023
** Generator
** File description:
** Created by benjaminkuhnel,
*/

#include "../../include/dante.h"
#include "../../include/my.h"

int find_height_maze(char **maze)
{
    int count = 0;

    for (int i = 0; maze[i] != NULL; i++)
        count++;
    return (count);
}

int find_width_maze(char **maze)
{
    int count = 0;

    if (maze[0] == NULL)
        return (-1);
    count = strlen(maze[0]);
    return (count);
}