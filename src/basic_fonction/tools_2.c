/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** contains basic functions
*/

#include "rpg.h"

char *my_strcat(char *dest, char *src)
{
    size_t size = my_strlen(dest) + my_strlen(src) + 1;
    char *new = malloc(sizeof(char) * size);
    int i = 0;

    if (!new)
        return NULL;
    if (dest)
        for (; dest[i] != '\0'; i++)
            new[i] = dest[i];
    if (src)
        for (int k = 0; src[k] != '\0'; k++) {
            new[i] = src[k];
            i++;
        }
    new[i] = '\0';
    return new;
}
