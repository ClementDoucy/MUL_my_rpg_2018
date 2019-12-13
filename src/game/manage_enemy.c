/*
** EPITECH PROJECT, 2019
** manage_enemy
** File description:
** enemy manager
*/

#include "rpg.h"

void run_timer_respawn(enemy_t *enemy)
{
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(enemy->respawn_time.clock)) > 10) {
        sfSprite_setPosition(enemy->sprite, enemy->spawn_pos);
        enemy->is_attack = false;
        enemy->is_walk = false;
        enemy->is_alive = true;
        enemy->life = enemy->max_life;
    }
}

void manage_life_bar_scorpio(game_t *game, enemy_t *scorpio)
{
    sfVector2f pos_bar = {scorpio->pos.x - 30, scorpio->pos.y - 45};
    int percent = (100 * scorpio->life) / scorpio->max_life;
    int width = scorpio->life_bar.total_width * percent / 100;
    sfIntRect red_rect = {0, 57, width, 26};

    sfSprite_setTextureRect(scorpio->life_bar.red, red_rect);
    sfSprite_setPosition(scorpio->life_bar.red, pos_bar);
    sfSprite_setPosition(scorpio->life_bar.black, pos_bar);
    sfRenderWindow_drawSprite(game->window, scorpio->life_bar.black, NULL);
    sfRenderWindow_drawSprite(game->window, scorpio->life_bar.red, NULL);
}

void put_scorpio_status(
    enemy_t *scorpio, player_t *player, int i, sfRenderWindow *win)
{
    if (is_in_range(&scorpio[i], player, 400)) {
        if (player->pos.x < scorpio[i].pos.x)
            rev_enemy(&scorpio[i], false);
        else
            rev_enemy(&scorpio[i], true);
        if (is_in_range(&scorpio[i], player, 80) == false || (
            (scorpio[i].pos.y - player->pos.y) > 20 ||
            (scorpio[i].pos.y - player->pos.y) < -20)) {
            scorpio[i].is_walk = true;
            scorpio[i].is_attack = false;
        }
        else {
            scorpio[i].is_walk = false;
            scorpio[i].is_attack = true;
        }
        hit_player(&scorpio[i], DAMAGE_SCORPIO, player, win);
    }
    else {
        scorpio[i].is_attack = false;
        scorpio[i].is_walk = false;
    }
}

void scorpio_death(game_t *game, enemy_t *scorpio, player_t *player, int i)
{
    if (scorpio[i].life <= 0) {
        sfSprite_setPosition(scorpio[i].sprite, (sfVector2f) {0, 0});
        scorpio[i].is_alive = false;
        if ((game->quest.is_quest[0] || game->quest.is_quest[2]) &&
            game->quest.count < game->quest.goal)
            game->quest.count = game->quest.count + 1;
        player->exp = player->exp + 30;
        sfClock_restart(scorpio[i].respawn_time.clock);
    }
}

void manage_scorpio(game_t *game, enemy_t *scorpio, player_t *player)
{
    for (int i = 0; i != ALLOC_SCORPIO; i++) {
        scorpio[i].can_hit.seconds = sfTime_asSeconds(sfClock_getElapsedTime(
            scorpio[i].can_hit.clock));
        scorpio[i].pos = sfSprite_getPosition(scorpio[i].sprite);
        manage_life_bar_scorpio(game, &scorpio[i]);
        if (scorpio[i].is_alive && sfTime_asSeconds(
            sfClock_getElapsedTime(scorpio[i].clock)) > 0.002) {
            anim_scorpio(&scorpio[i], player, game);
            put_scorpio_status(scorpio, player, i, game->window);
            if (scorpio[i].is_walk)
                target_player(player, &scorpio[i], 0.5);
            scorpio_death(game, scorpio, player, i);
            sfClock_restart(scorpio[i].clock);
        }
        else
            run_timer_respawn(&scorpio[i]);
    }
}
