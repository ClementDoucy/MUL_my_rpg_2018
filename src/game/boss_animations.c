/*
** EPITECH PROJECT, 2019
** boss_animations
** File description:
** animations of the boss
*/

#include "rpg.h"

void idle_boss_anim(enemy_t *boss)
{
    if (boss->anim_time.seconds < 0.1)
        boss->rect = (sfIntRect) {5, 0, 69, 61};
    if (boss->anim_time.seconds > 0.1 && boss->anim_time.seconds < 0.2)
        boss->rect = (sfIntRect) {88, 0, 69, 61};
    if (boss->anim_time.seconds > 0.2 && boss->anim_time.seconds < 0.3)
        boss->rect = (sfIntRect) {169, 0, 69, 61};
    if (boss->anim_time.seconds > 0.3 && boss->anim_time.seconds < 0.4)
        boss->rect = (sfIntRect) {251, 0, 69, 61};
    if (boss->anim_time.seconds > 0.4)
        sfClock_restart(boss->anim_time.clock);
}

void dash_boss_anim(enemy_t *boss, boss_data_t data)
{
    if (data.dash_time.seconds < 0.1)
        boss->rect = (sfIntRect) {8, 211, 62, 58};
    if (data.dash_time.seconds > 0.1 && data.dash_time.seconds < 0.2)
        boss->rect = (sfIntRect) {74, 211, 62, 58};
    if (data.dash_time.seconds > 0.2 && data.dash_time.seconds < 0.3)
        boss->rect = (sfIntRect) {140, 211, 62, 58};
    if (data.dash_time.seconds > 0.3 && data.dash_time.seconds < 0.4)
        boss->rect = (sfIntRect) {206, 211, 62, 58};
}

void attack_boss_anim(enemy_t *boss, boss_data_t data)
{
    if (data.attack_time.seconds < 0.1)
        boss->rect = (sfIntRect) {2, 153, 68, 47};
    if (data.attack_time.seconds > 0.1 && data.attack_time.seconds < 0.2)
        boss->rect = (sfIntRect) {75, 153, 66, 47};
    if (data.attack_time.seconds > 0.2 && data.attack_time.seconds < 0.3)
        boss->rect = (sfIntRect) {149, 156, 61, 44};
    if (data.attack_time.seconds > 0.3 && data.attack_time.seconds < 0.4)
        boss->rect = (sfIntRect) {215, 123, 63, 77};
    if (data.attack_time.seconds > 0.4 && data.attack_time.seconds < 0.5) {
        boss->rect = (sfIntRect) {280, 132, 77, 72};
        boss->is_attack = true;
    }
    if (data.attack_time.seconds > 0.5 && data.attack_time.seconds < 0.6) {
        boss->rect = (sfIntRect) {362, 152, 60, 54};
        boss->is_attack = false;
    }
}

void walk_anim_boss(enemy_t *boss)
{
    if (boss->anim_time.seconds < 0.1)
        boss->rect = (sfIntRect) {8, 64, 62, 58};
    if (boss->anim_time.seconds > 0.1 && boss->anim_time.seconds < 0.2)
        boss->rect = (sfIntRect) {74, 64, 62, 58};
    if (boss->anim_time.seconds > 0.2 && boss->anim_time.seconds < 0.3)
        boss->rect = (sfIntRect) {140, 64, 62, 58};
    if (boss->anim_time.seconds > 0.3 && boss->anim_time.seconds < 0.4)
        boss->rect = (sfIntRect) {206, 64, 62, 58};
}

void anim_boss(enemy_t *boss, player_t *player, game_t *game)
{
    boss->anim_time.time = sfClock_getElapsedTime(boss->anim_time.clock);
    boss->anim_time.seconds = sfTime_asSeconds(boss->anim_time.time);
    idle_boss_anim(boss);
    if (boss->is_walk)
        walk_anim_boss(boss);
    if (boss->data.dash_time.seconds < 0.4 && player->is_alive)
        dash_boss_anim(boss, boss->data);
    if (boss->data.attack_time.seconds < 0.6 && player->is_alive)
        attack_boss_anim(boss, boss->data);
    hit_boss(boss, player, game);
    sfSprite_setTextureRect(boss->sprite, boss->rect);
}