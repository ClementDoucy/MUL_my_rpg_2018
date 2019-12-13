/*
** EPITECH PROJECT, 2019
** init_enemy
** File description:
** initialize all enemies
*/

#include "rpg.h"

enemy_t *init_scorpio(enemy_t *enemy)
{
    sfTexture *text = sfTexture_createFromFile("assets/GAME/scorpio.png", NULL);

    enemy = malloc(sizeof(enemy_t) * ALLOC_SCORPIO);
    for (int i = 0; i != ALLOC_SCORPIO; i++) {
        enemy[i].sprite = sfSprite_create();
        sfSprite_setTexture(enemy[i].sprite, text, sfFalse);
        enemy[i].pos = (sfVector2f) {5000, 1400};
        sfSprite_setPosition(enemy[i].sprite, enemy->pos);
        sfSprite_setTextureRect(enemy[i].sprite, (sfIntRect) {0, 0, 59, 59});
        enemy[i].is_alive = true;
        enemy[i].is_walk = false;
        enemy[i].is_attack = false;
        enemy[i].is_reverse = false;
        enemy[i].can_be_hit = true;
        enemy[i].life = 50;
        enemy[i].damage = 10;
        enemy[i].anim_time.clock = sfClock_create();
        enemy[i].anim_time.seconds = 0;
        enemy[i].respawn_time.clock = sfClock_create();
    }
    return enemy;
}

void init_scorpio_pos_and_life(enemy_t *enemy)
{
    sfTexture *text = sfTexture_createFromFile("assets/GAME/black_red_bar.png",
        NULL);

    for (int i = 0; i != ALLOC_SCORPIO; i++) {
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
        enemy[i].rect = (sfIntRect) {0, 2, 59, 59};
        enemy[i].clock = sfClock_create();
    }
}

enemy_t **init_enemy(void)
{
    enemy_t **enemy = malloc(sizeof(enemy_t *) * ALLOC_ENEMY);

    for (int i = 0; i != ALLOC_ENEMY; i++) {
        if (i == SCORPIO) {
            enemy[i] = init_scorpio(enemy[i]);
            sfSprite_setPosition(enemy[i][0].sprite, (sfVector2f) {4600, 1800});
            sfSprite_setPosition(enemy[i][1].sprite, (sfVector2f) {5000, 1400});
            init_scorpio_pos_and_life(enemy[i]);
        }
        if (i == BOSS) {
            enemy[i] = init_boss(enemy[i]);
            init_boss_data(enemy[i]);
            init_boss_pos_and_life(enemy[i]);
            sfSprite_setPosition(enemy[i][0].sprite, (sfVector2f) {3000, 2000});
            sfSprite_setPosition(enemy[i][1].sprite, (sfVector2f) {2750, 2300});
            sfSprite_setPosition(enemy[i][2].sprite, (sfVector2f) {2700, 2000});
        }
    }
    return enemy;
}