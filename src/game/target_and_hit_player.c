/*
** EPITECH PROJECT, 2019
** target_and_hit_player
** File description:
** target player and hit him
*/

#include "particle.h"
#include "rpg.h"

void target_player(player_t *target, enemy_t *enemy, float speed)
{
    float power = 0.05;
    float vector_x = 0;
    float vector_y = 0;
    static sfClock *clock = NULL;

    if (!clock)
        clock = sfClock_create();
    enemy->pos = sfSprite_getPosition(enemy->sprite);
    target->pos = sfSprite_getPosition(target->sprite);
    vector_x = (target->pos.x - enemy->pos.x) * power * speed;
    vector_y = (target->pos.y - enemy->pos.y) * power * speed;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.01)
        sfSprite_move(enemy->sprite, (sfVector2f) {vector_x , vector_y});
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.02)
        sfClock_restart(clock);
}

void hit_player(
    enemy_t *enemy, int damage, player_t *player, sfRenderWindow *win)
{
    static bool check = false;

    damage -= (player->stat.armor_point / 5);
    if (damage < 1)
        damage = 1;
    if (enemy->is_attack && enemy->can_hit.seconds > 1 &&
        player->stat.heal_point > 0 && !player->is_dash) {
        sfClock_restart(enemy->can_hit.clock);
        if (damage > player->stat.heal_point)
            player->stat.heal_point = 0;
        else {
            player->stat.heal_point = player->stat.heal_point - damage;
            check = true;
        }
    }
    if (check)
        draw_blood_effect(player->blood, player->pos, win, &check);
}
