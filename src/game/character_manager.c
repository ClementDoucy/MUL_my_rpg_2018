/*
** EPITECH PROJECT, 2019
** character_manager
** File description:
** manage the player
*/

#include "rpg.h"

void player_attack_manager(player_t *charac)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && !charac->is_attack) {
        charac->is_attack = true;
        sfSprite_scale(charac->sprite, (sfVector2f) {-1, 1});
        sfClock_restart(charac->anim_time.clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyW) && !charac->is_punch &&
        charac->lvl >= 10) {
        charac->is_punch = true;
        sfSprite_scale(charac->sprite, (sfVector2f) {-1, 1});
        sfClock_restart(charac->anim_time.clock);
    }
    if (charac->is_attack) {
        charac->is_move = false;
        attack_animation(charac);
    }
    if (charac->is_punch) {
        charac->is_move = false;
        punch_animation(charac);
    }
}

void player_death(player_t *charac)
{
    charac->anim_time.time = sfClock_getElapsedTime(charac->anim_time.clock);
    charac->anim_time.seconds = sfTime_asSeconds(charac->anim_time.time);

    if (charac->anim_time.seconds < 0.1)
        charac->rect = (sfIntRect) {8, 463, 70, 87};
    if (charac->anim_time.seconds > 0.1 && charac->anim_time.seconds < 0.2)
        charac->rect = (sfIntRect) {86, 465, 75, 84};
    if (charac->anim_time.seconds > 0.2 && charac->anim_time.seconds < 0.3)
        charac->rect = (sfIntRect) {171, 465, 76, 84};
    if (charac->anim_time.seconds > 0.3 && charac->anim_time.seconds < 0.4)
        charac->rect = (sfIntRect) {261, 472, 87, 81};
    sfSprite_setTextureRect(charac->sprite, charac->rect);
}

void character_manager(player_t *charac, object_t **obj)
{
    static sfClock *clock = NULL;

    if (!clock)
        clock = sfClock_create();
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.002
        && charac->is_alive) {
        check_move(charac);
        player_attack_manager(charac);
        move_and_dash(charac, obj);
        sfClock_restart(clock);
    }
    if (charac->stat.heal_point <= 0 && charac->is_alive) {
        charac->is_alive = false;
        sfClock_restart(charac->anim_time.clock);
    }
    if (!charac->is_alive)
        player_death(charac);
}