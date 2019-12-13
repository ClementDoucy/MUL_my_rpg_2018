/*
** EPITECH PROJECT, 2018
** click_button.c
** File description:
** animation for button settings
*/

#include "rpg.h"

void click_button_main_song(sfMouseMoveEvent event, menu_t *menu,
    sfVector2f position, float *main_song)
{
    sfVector2f position_move;
    float gap = 1.2;
    static float i = 3;

    if (event.x <= position.x + 40 && event.x >= position.x - 40 &&
    event.y <= position.y + 40 && event.y >= position.y - 40 &&
    event.x >= 1358 && event.x <= 1700) {
        if (event.x <= (1528- i)) {
            *main_song = *main_song - gap;
            i = i + 4.1;
        }
        if (event.x >= (1529 - i)) {
            *main_song = *main_song + gap;
            i = i - 4.1;
        }
        position_move.x = event.x;
        position_move.y = position.y;
        sfSprite_setPosition(menu->sprite[6].sprite, position_move);
    }
}

bool click_button_effect_song(sfMouseMoveEvent event, menu_t *menu,
    sfVector2f position, float *second_song)
{
    sfVector2f position_move;
    float gap = 1.2;
    static float i = 3;

    if (event.x <= position.x + 40 && event.x >= position.x - 40 &&
    event.y <= position.y + 40 && event.y >= position.y - 40 &&
    event.x >= 1358 && event.x <= 1700) {
        if (event.x <= (1528 - i)) {
            *second_song = *second_song - gap;
            i = i + 4.1;
        }
        if (event.x >= (1529 - i)) {
            *second_song = *second_song + gap;
            i = i - 4.1;
        }
        position_move.x = event.x;
        position_move.y = position.y;
        sfSprite_setPosition(menu->sprite[7].sprite, position_move);
        return (true);
    }
    return (false);
}

void click_button_settings(sfMouseMoveEvent event, menu_t *menu,
    game_t *game)
{
    sfVector2f position_one = {0, 0};
    sfVector2f position_two = {0, 0};

    position_one = sfSprite_getPosition(menu->sprite[6].sprite);
    position_two = sfSprite_getPosition(menu->sprite[7].sprite);
    click_button_main_song(event, menu, position_one, &game->option.main_song);
    if (click_button_effect_song(event, menu, position_two,
    &game->option.second_song))
        sfMusic_play(game->music[KILL_SOUND]);
}
