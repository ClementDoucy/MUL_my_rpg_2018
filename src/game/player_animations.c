/*
** EPITECH PROJECT, 2019
** player_animations
** File description:
** animations of the player
*/

#include "rpg.h"

void walk_animation(player_t *player)
{
    player->pos = sfSprite_getPosition(player->sprite);
    player->anim_time.time = sfClock_getElapsedTime(player->anim_time.clock);
    player->anim_time.seconds = player->anim_time.time.microseconds / 1000000.0;
    if (player->anim_time.seconds < 0.1)
        player->rect = (sfIntRect) {0, 3, 68, 87};
    if (player->anim_time.seconds > 0.1 && player->anim_time.seconds < 0.2)
        player->rect = (sfIntRect) {83, 3, 68, 87};
    if (player->anim_time.seconds > 0.2 && player->anim_time.seconds < 0.3)
        player->rect = (sfIntRect) {164, 3, 68, 87};
    if (player->anim_time.seconds > 0.3 && player->anim_time.seconds < 0.4)
        player->rect = (sfIntRect) {246, 3, 68, 87};
    if (player->anim_time.seconds > 0.4 && player->anim_time.seconds < 0.5)
        player->rect = (sfIntRect) {335, 4, 68, 87};
    if (player->anim_time.seconds > 0.5)
        sfClock_restart(player->anim_time.clock);
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void attack_animation(player_t *player)
{
    player->anim_time.time = sfClock_getElapsedTime(player->anim_time.clock);
    player->anim_time.seconds = player->anim_time.time.microseconds / 1000000.0;
    if (player->anim_time.seconds < 0.1)
        player->rect = (sfIntRect) {4, 92, 69, 85};
    if (player->anim_time.seconds > 0.1 && player->anim_time.seconds < 0.2)
        player->rect = (sfIntRect) {247, 90, 72, 89};
    if (player->anim_time.seconds > 0.2 && player->anim_time.seconds < 0.3)
        player->rect = (sfIntRect) {84, 186, 93, 86};
    if (player->anim_time.seconds > 0.3 && player->anim_time.seconds < 0.4)
        player->rect = (sfIntRect) {334, 92, 105, 86};
    if (player->anim_time.seconds > 0.4 && player->anim_time.seconds < 0.5)
        player->rect = (sfIntRect) {296, 184, 128, 85};
    if (player->anim_time.seconds > 0.5) {
        sfSprite_scale(player->sprite, (sfVector2f) {-1, 1});
        player->is_attack = false;
        player->rect = (sfIntRect) {4, 92, 69, 85};
        sfClock_restart(player->anim_time.clock);
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void punch_animation(player_t *player)
{
    player->anim_time.time = sfClock_getElapsedTime(player->anim_time.clock);
    player->anim_time.seconds = player->anim_time.time.microseconds / 1000000.0;
    if (player->anim_time.seconds < 0.1)
        player->rect = (sfIntRect) {10, 277, 58, 87};
    if (player->anim_time.seconds > 0.1 && player->anim_time.seconds < 0.2)
        player->rect = (sfIntRect) {75, 282, 99, 85};
    if (player->anim_time.seconds > 0.2 && player->anim_time.seconds < 0.3)
        player->rect = (sfIntRect) {180, 280, 107, 85};
    if (player->anim_time.seconds > 0.3 && player->anim_time.seconds < 0.4)
        player->rect = (sfIntRect) {305, 280, 120, 86};
    if (player->anim_time.seconds > 0.4) {
        sfSprite_scale(player->sprite, (sfVector2f) {-1, 1});
        player->is_punch = false;
        player->rect = (sfIntRect) {4, 92, 69, 85};
        sfClock_restart(player->anim_time.clock);
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void dash_animation(player_t *player)
{
    player->anim_time.time = sfClock_getElapsedTime(player->anim_time.clock);
    player->anim_time.seconds = player->anim_time.time.microseconds / 1000000.0;
    if (player->anim_time.seconds < 0.1)
        player->rect = (sfIntRect) {6, 374, 68, 89};
    if (player->anim_time.seconds > 0.1 && player->anim_time.seconds < 0.2)
        player->rect = (sfIntRect) {91, 374, 68, 89};
    if (player->anim_time.seconds > 0.2 && player->anim_time.seconds < 0.3)
        player->rect = (sfIntRect) {176, 374, 68, 89};
    if (player->anim_time.seconds > 0.3 && player->anim_time.seconds < 0.4)
        player->rect = (sfIntRect) {260, 374, 64, 89};
    if (player->anim_time.seconds > 0.4) {
        player->is_dash = false;
        player->rect = (sfIntRect) {4, 92, 69, 85};
        sfClock_restart(player->anim_time.clock);
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}