/*
** EPITECH PROJECT, 2019
** sprite_tools
** File description:
** tools for sprites
*/

#include "rpg.h"

void rev_sprite(player_t *player, bool verif)
{
    bool take_bool_val;

    if (verif == true)
        take_bool_val = false;
    else
        take_bool_val = true;
    if (player->is_reverse == verif) {
        player->is_reverse = take_bool_val;
        sfSprite_scale(player->sprite, (sfVector2f) {-1, 1});
    }
}