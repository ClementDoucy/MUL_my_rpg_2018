/*
** EPITECH PROJECT, 2018
** INIT AND DISPLAY RIVER MY RPG
** File description:
** init_and_display_river.c
*/

#include "rpg.h"

void init_river(game_t *game)
{
    game->obj[RIVER][0] = init_object("assets/GAME/river.png",
        (sfVector2f) {1000, -100}, (sfIntRect) {0, 0, 80, 60});
    game->obj[RIVER][1] = init_object("assets/GAME/river.png",
        (sfVector2f) {3000, 1200}, (sfIntRect) {0, 0, 80, 60});
    game->obj[RIVER][2] = init_object("assets/GAME/river.png",
        (sfVector2f) {3950, 1200}, (sfIntRect) {0, 0, 80, 60});
    game->obj[RIVER][3] = init_object("assets/GAME/river.png",
        (sfVector2f) {4600, 0}, (sfIntRect) {0, 0, 80, 60});
    game->obj[RIVER][4] = init_object("assets/GAME/river.png",
        (sfVector2f) {4800, 200}, (sfIntRect) {0, 0, 80, 60});
}

void init_sign(game_t *game)
{
    game->obj[SIGN][0] = init_object("assets/GAME/sign.png",
        (sfVector2f) {1500, 100}, (sfIntRect) {0, 0, 35, 30});
    game->obj[SIGN][1] = init_object("assets/GAME/sign.png",
        (sfVector2f) {2770, 100}, (sfIntRect) {0, 0, 35, 30});
    game->obj[SIGN][2] = init_object("assets/GAME/sign.png",
        (sfVector2f) {4230, 100}, (sfIntRect) {0, 0, 35, 30});
    game->obj[SIGN][3] = init_object("assets/GAME/sign.png",
        (sfVector2f) {1500, 1400}, (sfIntRect) {0, 0, 35, 30});
    game->obj[SIGN][4] = init_object("assets/GAME/sign.png",
        (sfVector2f) {2770, 1450}, (sfIntRect) {0, 0, 35, 30});
    game->obj[SIGN][5] = init_object("assets/GAME/sign.png",
        (sfVector2f) {3550, 1600}, (sfIntRect) {0, 0, 35, 30});
}
