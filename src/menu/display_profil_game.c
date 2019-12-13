/*
** EPITECH PROJECT, 2018
** display_profil_game.c
** File description:
** create background choose part in the game
*/

#include "rpg.h"

void remove_file(game_t *game, menu_t *menu, char *filename, int status)
{
    FILE *fp;

    filename = my_strcat("./save/", filename);
    game->filename = filename;
    if ((fp = fopen(game->filename, "w+")) != NULL) {
        fclose(fp);
    }
    if (status == 1)
        sfText_setString(menu->text[6].text, "EMPTY");
    else if (status == 2)
        sfText_setString(menu->text[7].text, "EMPTY");
    else
        sfText_setString(menu->text[8].text, "EMPTY");
}

void manage_mouse_click_play(sfMouseButtonEvent event, game_t *game,
    menu_t *menu, int *status)
{
    if (event.x >= 751 && event.x <= 1193 && event.y >= 300 &&
        event.y <= 386) {
        if (!check_save(game, "save_one", status))
            *status = 8;
    }
    if (event.x >= 751 && event.x <= 1193 && event.y >= 500 &&
        event.y <= 586) {
        if (!check_save(game, "save_two", status))
            *status = 8;
    }
    if (event.x >= 751 && event.x <= 1193 && event.y >= 700 &&
        event.y <= 786) {
        if (!check_save(game, "save_three", status))
            *status = 8;
    }
    if (event.x >= 1249 && event.x <= 1290 && event.y >= 320 && event.y <= 366)
        remove_file(game, menu, "save_one", 1);
    if (event.x >= 1249 && event.x <= 1290 && event.y >= 520 && event.y <= 566)
        remove_file(game, menu, "save_two", 2);
    if (event.x >= 1249 && event.x <= 1290 && event.y >= 720 && event.y <= 766)
        remove_file(game, menu, "save_three", 3);
}

void manage_mouse_move_play(sfMouseMoveEvent event, menu_t *menu)
{
    sfText_setColor(menu->text[6].text, sfBlack);
    sfText_setColor(menu->text[7].text, sfBlack);
    sfText_setColor(menu->text[8].text, sfBlack);
    if (event.x >= 751 && event.x <= 1193 && event.y >= 300 && event.y <= 386)
        sfText_setColor(menu->text[6].text, sfGreen);
    if (event.x >= 751 && event.x <= 1193 && event.y >= 500 && event.y <= 586)
        sfText_setColor(menu->text[7].text, sfGreen);
    if (event.x >= 751 && event.x <= 1193 && event.y >= 700 && event.y <= 786)
        sfText_setColor(menu->text[8].text, sfGreen);
    if (event.x >= 1249 && event.x <= 1290 && event.y >= 320 && event.y <= 366)
        sfText_setColor(menu->text[6].text, sfRed);
    if (event.x >= 1249 && event.x <= 1290 && event.y >= 520 && event.y <= 566)
        sfText_setColor(menu->text[7].text, sfRed);
    if (event.x >= 1249 && event.x <= 1290 && event.y >= 720 && event.y <= 766)
        sfText_setColor(menu->text[8].text, sfRed);
}

void analyse_events_profil(menu_t *menu, mouse_t *mouse,
    game_t *game, int *status)
{
    while (sfRenderWindow_pollEvent(game->window, &menu->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            *status = 1;
        if (menu->event.type == sfEvtMouseMoved) {
            manage_mouse_move_main(menu->event.mouseMove, mouse);
            manage_mouse_move_play(menu->event.mouseMove, menu);
        }
        if (menu->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_play(menu->event.mouseButton, game, menu,
            status);
    }
}

void display_profil_game(menu_t *menu, mouse_t *mouse, game_t *game,
    int *status)
{
    sfRenderWindow_drawSprite(game->window, menu->sprite[8].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[9].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[10].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[11].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[12].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[13].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite[14].sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->text[5].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[6].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[7].text, NULL);
    sfRenderWindow_drawText(game->window, menu->text[8].text, NULL);
    sfRenderWindow_drawSprite(game->window, mouse->main_mouse, NULL);
    analyse_events_profil(menu, mouse, game, status);
}
