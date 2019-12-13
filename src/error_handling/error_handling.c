/*
** EPITECH PROJECT, 2019
** error_handling.c
** File description:
** error management
*/

#include "rpg.h"

bool is_display_set(const char **env)
{
    if (!env)
        return false;
    for (; *env; env++)
        if (are_eq_str(*env, "DISPLAY=:0") || are_eq_str(*env, "DISPLAY=:0.0"))
            return true;
    my_put_error("\x1B[31mFatal error:");
    my_put_error("\x1B[37m DISPLAY variable not correctly "
        "set in environnement.\n");
    return false;
}
