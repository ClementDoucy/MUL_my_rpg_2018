/*
** EPITECH PROJECT, 2019
** status_bar_init.c
** File description:
** status bar initialization
*/

#include "rpg.h"

status_bar_t init_status_bar(sfFont *font)
{
    status_bar_t status_bar;

    status_bar.bar = sfSprite_create();
    status_bar.bar_tex = sfTexture_createFromFile(
        "assets/GAME/health.png", NULL);
    sfSprite_setTexture(status_bar.bar, status_bar.bar_tex, true);
    status_bar.bloc_tex = sfTexture_createFromFile(
        "assets/GAME/health_two.png", NULL);
    for (int i = 0; i < 5; i++) {
        status_bar.bloc[i] = sfSprite_create();
        sfSprite_setTexture(status_bar.bloc[i], status_bar.bloc_tex, true);
    }
    status_bar.nb_hp = sfText_create();
    sfText_setFont(status_bar.nb_hp, font);
    sfText_setColor(status_bar.nb_hp, sfRed);
    sfText_setScale(status_bar.nb_hp, (sfVector2f){0.5, 0.5});
    return status_bar;
}
