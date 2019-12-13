/*
** EPITECH PROJECT, 2018
** display_resume_game.c
** File description:
** create background how to play
*/

#include "rpg.h"

void analyse_events_how_to_play(menu_t *menu, sfRenderWindow *window,
    int *status)
{
    while (sfRenderWindow_pollEvent(window, &menu->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            *status = 1;
    }
}

void display_how_to_play(menu_t *menu, game_t *game, int *status)
{
    sfRenderWindow_drawSprite(game->window, menu->sprite[15].sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->text[11].text, NULL);
    analyse_events_how_to_play(menu, game->window, status);
}