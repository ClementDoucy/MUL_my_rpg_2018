/*
** EPITECH PROJECT, 2018
** DISPLAY PAUSE MY RPG
** File description:
** display_pause.c
*/

#include "rpg.h"

void init_position_pause_event(pause_t *pause)
{
    pause->sprite[0].pos_anim.x = pause->sprite[0].pos.x - 20;
    pause->sprite[0].pos_anim.y = pause->sprite[0].pos.y;
    pause->sprite[1].pos_anim.x = pause->sprite[1].pos.x - 20;
    pause->sprite[1].pos_anim.y = pause->sprite[1].pos.y;
    pause->sprite[2].pos_anim.x = pause->sprite[2].pos.x - 20;
    pause->sprite[2].pos_anim.y = pause->sprite[2].pos.y;
    pause->sprite[3].pos_anim.x = pause->sprite[3].pos.x - 20;
    pause->sprite[3].pos_anim.y = pause->sprite[3].pos.y;
    pause->sprite[4].pos_anim.x = pause->sprite[4].pos.x - 20;
    pause->sprite[4].pos_anim.y = pause->sprite[4].pos.y;
    pause->text[0].pos_anim.x = pause->text[0].pos.x + 5;
    pause->text[0].pos_anim.y = pause->text[0].pos.y + 5;
    pause->text[1].pos_anim.x = pause->text[1].pos.x + 5;
    pause->text[1].pos_anim.y = pause->text[1].pos.y + 5;
    pause->text[2].pos_anim.x = pause->text[2].pos.x + 5;
    pause->text[2].pos_anim.y = pause->text[2].pos.y + 5;
    pause->text[3].pos_anim.x = pause->text[3].pos.x + 5;
    pause->text[3].pos_anim.y = pause->text[3].pos.y + 5;
    pause->text[4].pos_anim.x = pause->text[4].pos.x;
    pause->text[4].pos_anim.y = pause->text[4].pos.y;
}

void init_position_pause(pause_t *pause, player_t player)
{
    pause->sprite[0].pos.x = player.pos.x - 350;
    pause->sprite[0].pos.y = player.pos.y - 400;
    pause->sprite[1].pos.x = player.pos.x - 210;
    pause->sprite[1].pos.y = player.pos.y - 180;
    pause->sprite[2].pos.x = player.pos.x - 210;
    pause->sprite[2].pos.y = player.pos.y - 20;
    pause->sprite[3].pos.x = player.pos.x - 210;
    pause->sprite[3].pos.y = player.pos.y + 140;
    pause->sprite[4].pos.x = player.pos.x - 210;
    pause->sprite[4].pos.y = player.pos.y + 300;
    pause->text[0].pos.x = player.pos.x - 10;
    pause->text[0].pos.y = player.pos.y - 140;
    pause->text[1].pos.x = player.pos.x + 5;
    pause->text[1].pos.y = player.pos.y + 20;
    pause->text[2].pos.x = player.pos.x - 25;
    pause->text[2].pos.y = player.pos.y + 180;
    pause->text[3].pos.x = player.pos.x + 10;
    pause->text[3].pos.y = player.pos.y + 340;
    pause->text[4].pos.x = player.pos.x - 60;
    pause->text[4].pos.y = player.pos.y + 448;
    init_position_pause_event(pause);
}

void set_position_pause(pause_t *pause, player_t player)
{
    init_position_pause(pause, player);
    sfSprite_setPosition(pause->sprite[0].sprite, pause->sprite[0].pos);
    sfText_setPosition(pause->text[4].text, pause->text[4].pos);
}

void manage_mouse_in_pause(game_t *game, mouse_t *mouse, sfVector2f pos)
{
    static bool dog = false;
    sfVector2i mouse_pos = sfRenderWindow_mapCoordsToPixel(
        game->window, pos, game->view);

    if (!dog) {
        sfMouse_setPosition(mouse_pos, (sfWindow *)game->window);
        mouse->position_mouse = pos;
        dog = true;
    } else {
        mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        mouse->position_mouse = sfRenderWindow_mapPixelToCoords
        (game->window, mouse_pos, game->view);
    }
    sfSprite_setPosition(mouse->main_mouse, mouse->position_mouse);
    sfRenderWindow_drawSprite(game->window, mouse->main_mouse, NULL);
}

void display_pause_game(game_t *game, pause_t *pause, mouse_t *mouse,
                        int *status)
{
    sfVector2f pos = {game->player.pos.x - 950, game->player.pos.y - 525};
    int i = 0;
    int o = 0;

    set_position_pause(pause, game->player);
    sfRenderWindow_drawSprite(game->window, game->obj[BACK][1].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->obj[BACK][0].sprite, NULL);
    draw_objects_in_order(&game->player, game->draw_obj, game);
    sfView_setCenter(game->view, game->player.pos);
    sfRenderWindow_setView(game->window, game->view);
    while (i != 5) {
        sfRenderWindow_drawSprite(game->window, pause->sprite[i].sprite, NULL);
        i++;
    }
    while (o != 5) {
        sfRenderWindow_drawText(game->window, pause->text[o].text, NULL);
        o++;
    }
    manage_mouse_in_pause(game, mouse, pos);
    analyse_event_pause(game, status);
}
