/*
** EPITECH PROJECT, 2018
** display_settings_game.c
** File description:
** create background settings game
*/

#include "rpg.h"

void manage_change_key(sfKeyCode str, key_game_t *key_game, int key)
{
    if (key == KEY_SWORD) {
        key_game->key_sword = str;
    }
}

void manage_destroy_settings(int status_settings, int *status)
{
    if (status_settings == 0)
        *status = 1;
    else {
        status_settings = 0;
        *status = 2;
    }
}

void analyse_events_settings(menu_t *menu, mouse_t *mouse, game_t *game,
    int *status)
{
    static int button = 0;
    static int key = 0;

    while (sfRenderWindow_pollEvent(game->window, &menu->event)) {
        if (menu->event.type == sfEvtMouseButtonPressed &&
            menu->event.type != sfEvtMouseButtonReleased)
            button = 1;
        if (menu->event.type == sfEvtMouseButtonReleased)
            button = 0;
        if (button == 1)
            click_button_settings(menu->event.mouseMove, menu, game);
        if (menu->event.type == sfEvtMouseMoved) {
            manage_mouse_move_main(menu->event.mouseMove, mouse);
            manage_mouse_move_settings(menu->event.mouseMove, menu);
        } if (menu->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_settings(menu->event.mouseButton, menu, &key);
        if (menu->event.type == sfEvtTextEntered)
            manage_change_key(menu->event.key.code, &game->key, key);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            manage_destroy_settings(game->status_settings, status);
    }
}

void display_settings_game(menu_t *menu, mouse_t *mouse, game_t *game,
    int *status)
{
    sfRenderWindow_drawSprite(game->window, menu->sprite[0].sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->text[0].text, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[1].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[6].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[7].sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->text[9].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[10].text, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->main_mouse, NULL);
    analyse_events_settings(menu, mouse, game, status);
}
