/*
** EPITECH PROJECT, 2019
** string_handling.c
** File description:
** string manipulation
*/

#include "rpg.h"

bool are_eq_str(const char *s1, const char *s2)
{
    if (!s1 || !s2)
        return false;
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    for (; *s1 && *s2; s1++, s2++)
        if (*s1 != *s2)
            return false;
    return true;
}

void my_put_error(char *str)
{
    if (!str)
        return;
    for (; *str; str++)
        write(2, str, 1);
}
