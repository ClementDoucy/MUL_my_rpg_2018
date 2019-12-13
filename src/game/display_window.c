/*
** EPITECH PROJECT, 2018
** DISPLAY WINDOW MY RPG
** File description:
** display_window.c
*/

#include "rpg.h"

void init_window(game_t *game)
{
    game->video_mode.width = 1920;
    game->video_mode.height = 1080;
    game->video_mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(
        game->video_mode, "MY_RPG", sfResize | sfClose, NULL);
}
