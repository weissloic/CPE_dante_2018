/*
** EPITECH PROJECT, 2019
** strtowordtab
** File description:
** strtowordtab
*/

#include "../../include/dante.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i <= n; i++) {
        dest[i] = src[i];
        if (n == i)
            dest[n] = '\0';
    }
    return (dest);
}

int size_line(char const *str)
{
    int nb_line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nb_line++;
    }
    return (nb_line + 1);
}

int condition(char c)
{
    if (c != '\t' && c != '\0' && c != '\n')
        return (1);
    return (0);
}

char **my_str_to_word_array(char const *buffer)
{
    char **word_array = NULL;
    int n = 0;
    int x = 0;
    int y = 0;

    word_array = malloc(sizeof(char *) * (size_line(buffer) + 1));
    while (buffer[y] != '\0') {
        for (x = 0; condition(buffer[x + y]); x++);
        if (x != 0) {
            word_array[n] = malloc(sizeof(char) * x + 1);
            my_strncpy(word_array[n], buffer + y, x);
            word_array[n][x] = '\0';
            n++;
            y += x;
        }
        if (buffer[y] != '\0')
            y++;
    }
    word_array[n] = NULL;
    return (word_array);
}
