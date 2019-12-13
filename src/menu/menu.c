/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** game menu
*/

#include "rpg.h"

void manage_mouse_click_menu(sfMouseButtonEvent event, game_t *game,
    menu_t *menu, int *status)
{
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 200 &&
        event.y <= 325) {
        check_file(&game->player, menu);
        *status = 4;
    }
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 400 &&
        event.y <= 525)
        *status = 3;
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 600 &&
        event.y <= 725)
        *status = 6;
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 800 &&
        event.y <= 925)
        *status = 8;
}

void manage_mouse_move_menu_two(sfMouseMoveEvent event, menu_t *menu,
                                sfVector2f scale_zoom)
{
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 600 &&
        event.y <= 725) {
        sfSprite_setScale(menu->sprite[4].sprite, scale_zoom);
        sfSprite_setPosition(menu->sprite[4].sprite,
        menu->sprite[4].position_anim);
        sfText_setPosition(menu->text[3].text, menu->text[3].position_anim);
    }
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 800 &&
        event.y <= 925) {
        sfSprite_setScale(menu->sprite[5].sprite, scale_zoom);
        sfSprite_setPosition(menu->sprite[5].sprite,
        menu->sprite[5].position_anim);
        sfText_setPosition(menu->text[4].text, menu->text[4].position_anim);
    }
}

void manage_mouse_move_menu(sfMouseMoveEvent event, menu_t *menu)
{
    sfVector2f scale_zoom = {1.1, 1.1};
    sfVector2f main_scale = {1, 1};

    init_position_event_menu(menu, main_scale);
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 200 &&
        event.y <= 325) {
        sfSprite_setScale(menu->sprite[2].sprite, scale_zoom);
        sfSprite_setPosition(menu->sprite[2].sprite,
        menu->sprite[2].position_anim);
        sfText_setPosition(menu->text[1].text, menu->text[1].position_anim);
    }
    if (event.x >= 1150 && event.x <= 1638 && event.y >= 400 &&
        event.y <= 525) {
        sfSprite_setScale(menu->sprite[3].sprite, scale_zoom);
        sfSprite_setPosition(menu->sprite[3].sprite,
        menu->sprite[3].position_anim);
        sfText_setPosition(menu->text[2].text, menu->text[2].position_anim);
    }
    manage_mouse_move_menu_two(event, menu, scale_zoom);
}

void analyse_events_menu(menu_t *menu, mouse_t *mouse, game_t *game,
    int *status)
{
    while (sfRenderWindow_pollEvent(game->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            *status = 8;
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            *status = 8;
        if (menu->event.type == sfEvtMouseMoved) {
            manage_mouse_move_main(menu->event.mouseMove, mouse);
            manage_mouse_move_menu(menu->event.mouseMove, menu);
        }
        if (menu->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_menu(menu->event.mouseButton, game, menu,
                                    status);
    }
}

void display_game_menu(menu_t *menu, mouse_t *mouse, game_t *game,
    int *status)
{
    sfRenderWindow_drawSprite(game->window, menu->sprite[0].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[2].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[3].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[4].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[5].sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->text[0].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[1].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[2].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[3].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[4].text, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->main_mouse, NULL);
    analyse_events_menu(menu, mouse, game, status);
}
