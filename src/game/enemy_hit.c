/*
** EPITECH PROJECT, 2019
** enemy_hit
** File description:
** manage the hit of the enemy
*/

#include "rpg.h"

void boss_hurt(game_t *game, enemy_t *boss, player_t *player, int damage)
{
    if (boss->can_be_hit) {
        if (player->is_punch)
            boss->life = boss->life - damage * 2;
        else
            boss->life = boss->life - damage;
        sfMusic_play(game->music[HIT_NINJA]);
        boss->can_be_hit = false;
    }
}

void scorpio_hurt(game_t *game, enemy_t *scorpio, player_t *player, int damage)
{
    if (scorpio->can_be_hit) {
        if (player->is_punch)
            scorpio->life = scorpio->life - damage * 2;
        else
            scorpio->life = scorpio->life - damage;
        sfMusic_play(game->music[HIT_SCORPIO]);
        scorpio->can_be_hit = false;
    }
}