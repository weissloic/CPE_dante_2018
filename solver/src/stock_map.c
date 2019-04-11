/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** Created by benjaminkuhnel,
*/

#include "../../include/dante.h"
#include "../../include/my.h"

char *get_buffer(char *file)
{
    struct stat st;
    char *buffer = NULL;
    int rd = 0;
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return (NULL);
    stat(file, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    if ((rd = read(fd, buffer, st.st_size)) == -1)
        return (NULL);
    buffer[rd] = '\0';
    return (buffer);
}

char **get_map(char *file)
{
    char **tmp = NULL;
    char *buffer = NULL;

    buffer = get_buffer(file);
    if (buffer == NULL)
        return (NULL);
    tmp = my_str_to_word_array(buffer);
    return (tmp);
}
