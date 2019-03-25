/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "include/my.h"
#include "include/lem_in.h"

int main(void)
{
    char *s;
    static int number = 0;
    char *buffer = malloc(sizeof(char) * 10000);
    char **test = NULL;
    int fd = open("text.txt", O_RDONLY);

    if (fd < 0)
        return (84);


    return(0);
}