/*
** EPITECH PROJECT, 2019
** init_boss
** File description:
** init the boss of the game
*/

#include "rpg.h"

void init_boss_pos_and_life(enemy_t *enemy)
{
    sfTexture *text = sfTexture_createFromFile("assets/GAME/black_red_bar.png",
        NULL);

    for (int i = 0; i != ALLOC_BOSS; i++) {
        enemy[i].life_bar.black = sfSprite_create();
        enemy[i].life_bar.red = sfSprite_create();
        sfSprite_setTexture(enemy[i].life_bar.red, text, sfFalse);
        sfSprite_setTexture(enemy[i].life_bar.black, text, sfFalse);
        sfSprite_setTextureRect(enemy[i].life_bar.black,
            (sfIntRect) {0, 5, 150, 26});
        sfSprite_scale(enemy[i].life_bar.red, (sfVector2f) {0.4, 0.4});
        sfSprite_scale(enemy[i].life_bar.black, (sfVector2f) {0.4, 0.4});
        enemy[i].life_bar.total_width = 150;
        sfSprite_setOrigin(enemy[i].sprite, (sfVector2f) {30, 30});
        enemy[i].pos = sfSprite_getPosition(enemy[i].sprite);
        enemy[i].spawn_pos = sfSprite_getPosition(enemy[i].sprite);
        enemy[i].max_life = enemy[i].life;
        enemy[i].can_hit.clock = sfClock_create();
        enemy[i].clock = sfClock_create();
        sfSprite_scale(enemy[i].sprite, (sfVector2f) {1.4, 1.4});
    }
}

enemy_t *init_boss(enemy_t *enemy)
{
    sfTexture *text = sfTexture_createFromFile("assets/GAME/boss.png", NULL);

    enemy = malloc(sizeof(enemy_t) * ALLOC_BOSS);
    for (int i = 0; i != ALLOC_BOSS; i++) {
        enemy[i].sprite = sfSprite_create();
        sfSprite_setTexture(enemy[i].sprite, text, sfFalse);
        enemy[i].pos = (sfVector2f) {3000, 2000};
        sfSprite_setPosition(enemy[i].sprite, enemy->pos);
        sfSprite_setTextureRect(enemy[i].sprite, (sfIntRect) {5, 0, 69, 61});
        enemy[i].is_alive = false;
        enemy[i].is_walk = false;
        enemy[i].is_attack = false;
        enemy[i].is_reverse = false;
        enemy[i].can_be_hit = true;
        enemy[i].life = 300;
        enemy[i].damage = 10;
        enemy[i].anim_time.clock = sfClock_create();
        enemy[i].anim_time.seconds = 0;
        enemy[i].respawn_time.clock = sfClock_create();
    }
    return enemy;
}

void init_boss_data(enemy_t *enemy)
{
    for (int i = 0; i != ALLOC_BOSS; i++) {
        enemy[i].data.dash_time.clock = sfClock_create();
        enemy[i].data.dash_time.seconds = 0;
        enemy[i].data.attack_time.clock = sfClock_create();
        enemy[i].data.attack_time.seconds = 0;
    }
}