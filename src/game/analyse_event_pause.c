/*
** EPITECH PROJECT, 2018
** ANALYSE EVENT PAUSE MY RPG
** File description:
** analyse_event_pause.c
*/

#include "rpg.h"

void init_event_pause(pause_t *pause)
{
    sfVector2f main_scale = {1, 1};

    sfSprite_setScale(pause->sprite[1].sprite, main_scale);
    sfSprite_setScale(pause->sprite[2].sprite, main_scale);
    sfSprite_setScale(pause->sprite[3].sprite, main_scale);
    sfSprite_setScale(pause->sprite[4].sprite, main_scale);
    sfSprite_setPosition(pause->sprite[1].sprite, pause->sprite[1].pos);
    sfSprite_setPosition(pause->sprite[2].sprite, pause->sprite[2].pos);
    sfSprite_setPosition(pause->sprite[3].sprite, pause->sprite[3].pos);
    sfSprite_setPosition(pause->sprite[4].sprite, pause->sprite[4].pos);
    sfText_setPosition(pause->text[0].text, pause->text[0].pos);
    sfText_setPosition(pause->text[1].text, pause->text[1].pos);
    sfText_setPosition(pause->text[2].text, pause->text[2].pos);
    sfText_setPosition(pause->text[3].text, pause->text[3].pos);
    sfText_setColor(pause->text[4].text, sfBlack);
}

int click_button_pause(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f pos_init = {960, 540};

    if (event.x <= 1235 && event.x >= 750 && event.y >= 327 &&
        event.y <= 437)
        game->status_pause = 0;
    if (event.x <= 1235 && event.x >= 750 && event.y >= 460 &&
        event.y <= 570)
        get_save_fonction_in_game(game, &game->player);
    if (event.x <= 1235 && event.x >= 750 && event.y >= 594 &&
        event.y <= 704) {
        sfView_setCenter(game->view, pos_init);
        sfRenderWindow_setView(game->window, game->view);
        game->status_settings = 1;
        return (3);
    }
    if (event.x <= 1235 && event.x >= 750 && event.y >= 730 &&
        event.y <= 840)
        return (8);
    return (2);
}

void anim_button_pause_two(sfMouseMoveEvent event, pause_t *pause,
                                sfVector2f scale_zoom)
{
    if (event.x <= 1235 && event.x >= 750 && event.y >= 594 &&
        event.y <= 704) {
        sfSprite_setScale(pause->sprite[3].sprite, scale_zoom);
        sfSprite_setPosition(pause->sprite[3].sprite,
        pause->sprite[3].pos_anim);
        sfText_setPosition(pause->text[2].text, pause->text[2].pos_anim);
    }
    if (event.x <= 1235 && event.x >= 750 && event.y >= 730 &&
        event.y <= 840) {
        sfSprite_setScale(pause->sprite[4].sprite, scale_zoom);
        sfSprite_setPosition(pause->sprite[4].sprite,
        pause->sprite[4].pos_anim);
        sfText_setPosition(pause->text[3].text, pause->text[3].pos_anim);
    }
}

void anim_button_pause(sfMouseMoveEvent event, pause_t *pause)
{
    sfVector2f scale_zoom = {1.1, 1.1};

    init_event_pause(pause);
    if (event.x <= 1235 && event.x >= 750 && event.y >= 327 &&
        event.y <= 437) {
        sfSprite_setScale(pause->sprite[1].sprite, scale_zoom);
        sfSprite_setPosition(pause->sprite[1].sprite,
        pause->sprite[1].pos_anim);
        sfText_setPosition(pause->text[0].text, pause->text[0].pos_anim);
        sfText_setColor(pause->text[4].text, sfGreen);
    }
    if (event.x <= 1235 && event.x >= 750 && event.y >= 460 &&
        event.y <= 570) {
        sfSprite_setScale(pause->sprite[2].sprite, scale_zoom);
        sfSprite_setPosition(pause->sprite[2].sprite,
        pause->sprite[2].pos_anim);
        sfText_setPosition(pause->text[1].text, pause->text[1].pos_anim);
    }
    anim_button_pause_two(event, pause, scale_zoom);
}

void analyse_event_pause(game_t *game, int *status)
{
    while (sfRenderWindow_pollEvent(game->window, &game->pause_game.event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            game->status_pause = 0;
        if (game->pause_game.event.type == sfEvtMouseMoved)
            anim_button_pause(game->pause_game.event.mouseMove,
            &game->pause_game);
        if (game->pause_game.event.type == sfEvtMouseButtonPressed) {
            *status = click_button_pause(game->pause_game.event.mouseButton,
            game);
        }
    }
}
