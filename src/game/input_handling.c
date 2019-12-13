/*
** EPITECH PROJECT, 2019
** input_handling.c
** File description:
** catch input keyboard
*/

#include "rpg.h"

static const float timer = 0.3;

bool catch_double_click(sfEvent event)
{
    static sfClock *clock = NULL;
    static bool check = false;

    if (!clock)
        clock = sfClock_create();
    if (!check && event.type == sfEvtMouseButtonReleased &&
        event.mouseButton.button == sfMouseLeft) {
        sfClock_restart(clock);
        check = true;
        return false;
    }
    if (check && event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        check = false;
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) <= timer)
            return true;
        else
            sfClock_restart(clock);
    }
    return false;
}
