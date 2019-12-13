/*
** EPITECH PROJECT, 2019
** check_and_block_player
** File description:
** check collision and block player
*/

#include "rpg.h"

void bridge_collide(player_t *charac)
{
    if (charac->pos.x > 3080 && charac->pos.x < 3201) {
        if (charac->pos.y == 2501)
            sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
        if (charac->pos.y == 2474)
            sfSprite_move(charac->sprite, (sfVector2f) {0, 1});
        if (charac->pos.y == 1155)
            sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
        if (charac->pos.y == 1099)
            sfSprite_move(charac->sprite, (sfVector2f) {0, 1});
    }
}

void lake_collide(player_t *charac)
{
    if (charac->pos.x > 1906 && charac->pos.x < 2502 && charac->pos.y == 1256)
        sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
    if (charac->pos.x > 1906 && charac->pos.x < 2944 && charac->pos.y == 1880)
        sfSprite_move(charac->sprite, (sfVector2f) {0, 1});
    if (charac->pos.y > 1255 && charac->pos.y < 1881 && charac->pos.x == 1907)
        sfSprite_move(charac->sprite, (sfVector2f) {-1, 0});
    if (charac->pos.y > 1255 && charac->pos.y < 1560 && charac->pos.x == 2499)
        sfSprite_move(charac->sprite, (sfVector2f) {1, 0});
    if (charac->pos.y > 1550 && charac->pos.y < 1881 && charac->pos.x == 2949)
        sfSprite_move(charac->sprite, (sfVector2f) {1, 0});
    if (charac->pos.x > 2480 && charac->pos.x < 2944 && charac->pos.y == 1550)
        sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
}

void replace_player(player_t *charac)
{
    sfVector2f down_right_pos = {charac->pos.x + charac->rect.width,
        charac->pos.y + charac->rect.height};

    if (charac->pos.x < 952 || (charac->pos.x == 3200 && (charac->pos.y > 2500
        || (charac->pos.y < 2475 && charac->pos.y > 1154) ||
        charac->pos.y < 1100)))
        sfSprite_move(charac->sprite, (sfVector2f) {1, 0});
    if (charac->pos.y < 682)
        sfSprite_move(charac->sprite, (sfVector2f) {0, 1});
    if (down_right_pos.x > 5657 || (charac->pos.x > 3080 && charac->pos.x < 3085
        && (charac->pos.y > 2500 || (charac->pos.y < 2475
        && charac->pos.y > 1154) || charac->pos.y < 1100)))
        sfSprite_move(charac->sprite, (sfVector2f) {-1, 0});
    if (down_right_pos.y > 2784)
        sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
    bridge_collide(charac);
    lake_collide(charac);
}

void check_which_side(player_t *charac, object_t obj)
{
    sfVector2f pos_obj = sfSprite_getPosition(obj.sprite);
    int width = obj.hit_rect.width;
    int height = obj.hit_rect.height;

    pos_obj.x = pos_obj.x + obj.hit_rect.left;
    pos_obj.y = pos_obj.y + obj.hit_rect.top;
    charac->rect.width = 68;
    charac->rect.height = 87;
    if (charac->pos.y == pos_obj.y + height - 1)
        sfSprite_move(charac->sprite, (sfVector2f) {0, 1});
    if (charac->pos.y + charac->rect.height == pos_obj.y + 1)
        sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
    if (charac->pos.x == pos_obj.x + width - 1)
        sfSprite_move(charac->sprite, (sfVector2f) {1, 0});
    if (charac->pos.x + charac->rect.width == pos_obj.x + 1)
        sfSprite_move(charac->sprite, (sfVector2f) {-1, 0});
}

void replace_player_object(player_t *charac, object_t **obj)
{
    int coord[2] = {0, 0};

    if (is_collide(*charac, obj, coord))
        check_which_side(charac, obj[coord[0]][coord[1]]);
}