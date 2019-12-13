/*
** EPITECH PROJECT, 2019
** character_move
** File description:
** all movement of the player
*/

#include "rpg.h"

void character_move(player_t *charac)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sfSprite_move(charac->sprite, (sfVector2f) {0, -1});
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sfSprite_move(charac->sprite, (sfVector2f) {0, 1});
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        rev_sprite(charac, true);
        sfSprite_move(charac->sprite, (sfVector2f) {-1, 0});
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        rev_sprite(charac, false);
        sfSprite_move(charac->sprite, (sfVector2f) {1, 0});
    }
    charac->pos = sfSprite_getPosition(charac->sprite);
}

void character_dash(player_t *player)
{
    player->pos = sfSprite_getPosition(player->sprite);
    if (player->is_reverse)
        sfSprite_move(player->sprite, (sfVector2f) {-1, 0});
    else
        sfSprite_move(player->sprite, (sfVector2f) {1, 0});
    player->pos = sfSprite_getPosition(player->sprite);
}

void move_and_dash(player_t *charac, object_t **obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift) && !charac->is_dash &&
        !charac->is_attack && !charac->is_punch && charac->lvl >= 5) {
        charac->is_dash = true;
        sfClock_restart(charac->anim_time.clock);
    }
    if (charac->is_dash) {
        charac->is_move = false;
        character_dash(charac);
        replace_player(charac);
        replace_player_object(charac, obj);
        dash_animation(charac);
    }
    if (charac->is_move) {
        character_move(charac);
        replace_player(charac);
        replace_player_object(charac, obj);
        walk_animation(charac);
    }
}

void check_move(player_t *charac)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyRight))
        charac->is_move = true;
    else {
        charac->is_move = false;
        charac->rect = (sfIntRect) {0, 0, 74, 90};
        sfSprite_setTextureRect(charac->sprite, charac->rect);
    }
}