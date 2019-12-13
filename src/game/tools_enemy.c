/*
** EPITECH PROJECT, 2019
** tools_enemy
** File description:
** tools for enemy manager
*/

#include "rpg.h"

bool is_in_range(enemy_t *enemy, player_t *player, float range)
{
    float dis[3];

    dis[0] = enemy->pos.x - player->pos.x;
    dis[1] = enemy->pos.y - player->pos.y;
    for (int i = 0; i != 2; i++)
        if (dis[i] < 0)
            dis[i] = dis[i] * -1;
    dis[2] = dis[0] + dis[1];
    if (range > dis[2])
        return true;
    return false;
}

void rev_enemy(enemy_t *enemy, bool verif)
{
    bool take_bool_val;

    if (verif == true)
        take_bool_val = false;
    else
        take_bool_val = true;
    if (enemy->is_reverse == verif) {
        enemy->is_reverse = take_bool_val;
        sfSprite_scale(enemy->sprite, (sfVector2f) {-1, 1});
    }
}

bool watch_in_direction(player_t *player, enemy_t *enemy)
{
    if (enemy->pos.x < player->pos.x) {
        if (player->is_reverse)
            return false;
        return true;
    }
    else
        if (player->is_reverse)
            return true;
    return false;
}

void follow_player(enemy_t *boss, player_t *player)
{
    if (boss->data.attack_time.seconds > 1 &&
        boss->data.dash_time.seconds > 3
        && is_in_range(boss, player, 400) && player->is_alive) {
        target_player(player, boss, 0.4);
        boss->is_walk = true;
    }
    else
        boss->is_walk = false;
}

void hit_boss(enemy_t *boss, player_t *player, game_t *game)
{
    int damage = player->stat.attack_damage;

    if (watch_in_direction(player, boss) && (player->is_punch ||
        player->is_attack) && is_in_range(boss, player, 100)) {
        if (player->anim_time.seconds > 0.3) {
            boss->rect = (sfIntRect) {0, 273, 55, 47};
            if (boss->is_reverse)
                sfSprite_move(boss->sprite, (sfVector2f) {1, 0});
            else
                sfSprite_move(boss->sprite, (sfVector2f) {-1, 0});
            boss_hurt(game, boss, player, damage);
        }
    }
    if (!player->is_attack && !player->is_punch)
        boss->can_be_hit = true;
}
