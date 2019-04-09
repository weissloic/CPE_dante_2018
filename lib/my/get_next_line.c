/*
** EPITECH PROJECT, 2023
** GNL
** File description:
** Created by benjaminkuhnel,
*/

#include "../../include/my.h"

char *my_strgnl(char *str, char *cpy)
{
    char *txt = NULL;
    int i;
    int j;

    if (cpy == NULL)
        return (str);
    if (str == NULL)
        return (cpy);
    txt = malloc(sizeof(char) * (my_strlen(str) + my_strlen(cpy) + 1));
    if (txt == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        txt[i] = str[i];
    for (j = 0; cpy[j] != '\0'; j++, i++)
        txt[i] = cpy[j];
    txt[i] = '\0';
    return (txt);
}

int stock_txt(char **txt, char **buffer)
{
    int i = 0;

    *txt = malloc(sizeof(char) * (READ_SIZE + 1));
    if (*txt == NULL)
        return (-1);
    while (**buffer != '\0' && (i == 0 || *(*buffer - 1) != '\n')) {
        (*txt)[i] = **buffer;
        (*buffer)++;
        i++;
    }
    (*txt)[i] = '\0';
    return (i);
}

char *stock_buffer(char *buffer, int fd)
{
    int rd = 0;

    buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    if (buffer == NULL)
        return (NULL);
    rd = read(fd, buffer, READ_SIZE);
    if (rd == -1)
        return (NULL);
    buffer[rd] = '\0';
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *txt = NULL;
    static int i = 0;

    if (fd == -1)
        return (NULL);
    if (buffer == NULL || buffer[0] == '\0')
        buffer = stock_buffer(buffer, fd);
    if (buffer == NULL || buffer[0] == '\0')
        return (NULL);
    if ((i = stock_txt(&txt, &buffer)) == -1)
        return (NULL);
    if (i != 0 && txt[i - 1] == '\n')
        txt[i - 1] = '\0';
    else
        txt = my_strgnl(txt, get_next_line(fd));
    return (txt);
}