/*
** EPITECH PROJECT, 2018
** MAIN MY RPG
** File description:
** main.c
*/

#include "rpg.h"

int main(int argc, char **argv, char **env)
{
    if (!is_display_set(((const char **)env)))
        return 84;
    return (launch(argc, argv, env));
}
