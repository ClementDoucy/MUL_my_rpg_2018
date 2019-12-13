/*
** EPITECH PROJECT, 2019
** scorpio_animation
** File description:
** all scorpio animations functions
*/

#include "rpg.h"

void idle_scorpio_anim(enemy_t *scorpio)
{
    if (scorpio->anim_time.seconds < 0.1)
        scorpio->rect = (sfIntRect) {0, 2, 59, 59};
    if (scorpio->anim_time.seconds > 0.1 && scorpio->anim_time.seconds < 0.2)
        scorpio->rect = (sfIntRect) {59, 2, 59, 58};
    if (scorpio->anim_time.seconds > 0.2 && scorpio->anim_time.seconds < 0.3)
        scorpio->rect = (sfIntRect) {116, 2, 58, 58};
    if (scorpio->anim_time.seconds > 0.3 && scorpio->anim_time.seconds < 0.4)
        scorpio->rect = (sfIntRect) {175, 2, 60, 58};
    if (scorpio->anim_time.seconds > 0.4)
        sfClock_restart(scorpio->anim_time.clock);
}

void walk_scorpio_anim(enemy_t *scorpio)
{
    if (scorpio->anim_time.seconds < 0.1)
        scorpio->rect = (sfIntRect) {0, 62, 59, 59};
    if (scorpio->anim_time.seconds > 0.1 && scorpio->anim_time.seconds < 0.2)
        scorpio->rect = (sfIntRect) {60, 62, 61, 56};
    if (scorpio->anim_time.seconds > 0.2 && scorpio->anim_time.seconds < 0.3)
        scorpio->rect = (sfIntRect) {126, 62, 59, 58};
    if (scorpio->anim_time.seconds > 0.3 && scorpio->anim_time.seconds < 0.4)
        scorpio->rect = (sfIntRect) {192, 62, 56, 60};
    if (scorpio->anim_time.seconds > 0.4)
        sfClock_restart(scorpio->anim_time.clock);
}

void attack_scorpio_anim(enemy_t *scorpio)
{
    if (scorpio->anim_time.seconds < 0.1)
        scorpio->rect = (sfIntRect) {0, 196, 58, 68};
    if (scorpio->anim_time.seconds > 0.1 && scorpio->anim_time.seconds < 0.2)
        scorpio->rect = (sfIntRect) {60, 196, 66, 68};
    if (scorpio->anim_time.seconds > 0.2 && scorpio->anim_time.seconds < 0.3)
        scorpio->rect = (sfIntRect) {126, 196, 67, 68};
    if (scorpio->anim_time.seconds > 0.3 && scorpio->anim_time.seconds < 0.4)
        scorpio->rect = (sfIntRect) {190, 188, 55, 74};
    if (scorpio->anim_time.seconds > 0.4)
        sfClock_restart(scorpio->anim_time.clock);
}

void hit_scorpio(enemy_t *scorpio, player_t *player, game_t *game)
{
    int damage = player->stat.attack_damage;

    if (watch_in_direction(player, scorpio) && (player->is_punch ||
        player->is_attack) && is_in_range(scorpio, player, 100)) {
        if (player->anim_time.seconds > 0.3) {
            scorpio->rect = (sfIntRect) {0, 273, 55, 47};
            if (scorpio->is_reverse)
                sfSprite_move(scorpio->sprite, (sfVector2f) {1, 0});
            else
                sfSprite_move(scorpio->sprite, (sfVector2f) {-1, 0});
            scorpio_hurt(game, scorpio, player, damage);
        }
    }
    if (!player->is_attack && !player->is_punch)
        scorpio->can_be_hit = true;
}

void anim_scorpio(enemy_t *scorpio, player_t *player, game_t *game)
{
    scorpio->anim_time.time = sfClock_getElapsedTime(scorpio->anim_time.clock);
    scorpio->anim_time.seconds = sfTime_asSeconds(scorpio->anim_time.time);
    if (scorpio->is_walk || scorpio->is_attack) {
        if (scorpio->is_walk)
            walk_scorpio_anim(scorpio);
        else
            attack_scorpio_anim(scorpio);
        hit_scorpio(scorpio, player, game);
    }
    else
        idle_scorpio_anim(scorpio);
    sfSprite_setTextureRect(scorpio->sprite, scorpio->rect);
}
