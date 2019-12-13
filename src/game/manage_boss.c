/*
** EPITECH PROJECT, 2019
** manage boss
** File description:
** manager of the boss
*/

#include "rpg.h"

void manage_life_bar_boss(game_t *game, enemy_t *boss)
{
    sfVector2f pos_bar = {boss->pos.x - 30, boss->pos.y - 60};
    int percent = (100 * boss->life) / boss->max_life;
    int width = boss->life_bar.total_width * percent / 100;
    sfIntRect red_rect = {0, 57, width, 26};

    sfSprite_setTextureRect(boss->life_bar.red, red_rect);
    sfSprite_setPosition(boss->life_bar.red, pos_bar);
    sfSprite_setPosition(boss->life_bar.black, pos_bar);
    sfRenderWindow_drawSprite(game->window, boss->life_bar.black, NULL);
    sfRenderWindow_drawSprite(game->window, boss->life_bar.red, NULL);
}

void boss_dash(enemy_t *boss, player_t *player)
{
    if (boss->data.dash_time.seconds < 0.5 && player->is_alive) {
        if (player->pos.x < boss->pos.x)
            sfSprite_move(boss->sprite, (sfVector2f) {2, 0});
        else
            sfSprite_move(boss->sprite, (sfVector2f) {-2, 0});
    }
}

void boss_attack(enemy_t *boss, player_t *player)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(boss->clock)) > 0.002) {
        if (boss->data.attack_time.seconds < 0.5 && player->is_alive)
            target_player(player, boss, 2);
        sfClock_restart(boss->clock);
    }
}

void put_boss_status(enemy_t *boss, player_t *player, int i, boss_data_t *data)
{
    data->dash_time.time = sfClock_getElapsedTime(data->dash_time.clock);
    data->dash_time.seconds = sfTime_asSeconds(data->dash_time.time);
    data->attack_time.time = sfClock_getElapsedTime(data->attack_time.clock);
    data->attack_time.seconds = sfTime_asSeconds(data->attack_time.time);
    if (is_in_range(&boss[i], player, 400)) {
        if (player->pos.x < boss[i].pos.x)
            rev_enemy(&boss[i], false);
        else
            rev_enemy(&boss[i], true);
        if (is_in_range(&boss[i], player, 150) && data->dash_time.seconds > 3
            && data->attack_time.seconds > 1)
            sfClock_restart(data->dash_time.clock);
    }
    if (data->dash_time.seconds > 1 && data->dash_time.seconds < 1.01 &&
        data->attack_time.seconds > 2) {
        sfClock_restart(data->attack_time.clock);
    }
    boss_dash(&boss[i], player);
    boss_attack(&boss[i], player);
}

void manage_boss(game_t *game, enemy_t *boss, player_t *player)
{
    for (int i = 0; i != ALLOC_BOSS; i++) {
        boss[i].can_hit.seconds = sfTime_asSeconds(sfClock_getElapsedTime(
            boss[i].can_hit.clock));
        boss[i].pos = sfSprite_getPosition(boss[i].sprite);
        if (boss[i].is_alive &&
            (game->quest.is_quest[1] || game->quest.is_quest[3])) {
            manage_life_bar_boss(game, &boss[i]);
            anim_boss(&boss[i], player, game);
            put_boss_status(boss, player, i, &boss[i].data);
            follow_player(&boss[i], player);
            hit_player(&boss[i], DAMAGE_BOSS, player, game->window);
            if (boss[i].life <= 0) {
                if ((game->quest.is_quest[1] || game->quest.is_quest[3]) &&
                    game->quest.count < game->quest.goal)
                    game->quest.count = game->quest.count + 1;
                player->exp = player->exp + 600;
                sfSprite_setPosition(boss[i].sprite, (sfVector2f) {0, 0});
                boss[i].is_alive = false;
            }
        }
    }
}
