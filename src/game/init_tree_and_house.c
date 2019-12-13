/*
** EPITECH PROJECT, 2018
** INIT TREE AND HOUSE MY RPG
** File description:
** init_tree_and_house.c
*/

#include "rpg.h"

void init_tree_three(game_t *game)
{
    sfSprite_setPosition(game->obj[TREE][35].sprite, (sfVector2f) {3900, 950});
    sfSprite_setPosition(game->obj[TREE][36].sprite, (sfVector2f) {3500, 1800});
    sfSprite_setPosition(game->obj[TREE][37].sprite, (sfVector2f) {4050, 1350});
    sfSprite_setPosition(game->obj[TREE][38].sprite, (sfVector2f) {3800, 1800});
    sfSprite_setPosition(game->obj[TREE][39].sprite, (sfVector2f) {3200, 1650});
}

void init_tree_two(game_t *game)
{
    sfSprite_setPosition(game->obj[TREE][16].sprite, (sfVector2f) {3400, 2450});
    sfSprite_setPosition(game->obj[TREE][17].sprite, (sfVector2f) {3600, 2450});
    sfSprite_setPosition(game->obj[TREE][18].sprite, (sfVector2f) {4750, 2200});
    sfSprite_setPosition(game->obj[TREE][19].sprite, (sfVector2f) {4500, 2450});
    sfSprite_setPosition(game->obj[TREE][20].sprite, (sfVector2f) {5300, 2450});
    sfSprite_setPosition(game->obj[TREE][21].sprite, (sfVector2f) {3400, 2000});
    sfSprite_setPosition(game->obj[TREE][22].sprite, (sfVector2f) {3400, 1500});
    sfSprite_setPosition(game->obj[TREE][23].sprite, (sfVector2f) {3800, 2000});
    sfSprite_setPosition(game->obj[TREE][24].sprite, (sfVector2f) {3800, 1500});
    sfSprite_setPosition(game->obj[TREE][25].sprite, (sfVector2f) {3800, 1200});
    sfSprite_setPosition(game->obj[TREE][26].sprite, (sfVector2f) {3400, 1200});
    sfSprite_setPosition(game->obj[TREE][27].sprite, (sfVector2f) {4300, 1200});
    sfSprite_setPosition(game->obj[TREE][28].sprite, (sfVector2f) {4300, 1500});
    sfSprite_setPosition(game->obj[TREE][29].sprite, (sfVector2f) {4300, 1750});
    sfSprite_setPosition(game->obj[TREE][30].sprite, (sfVector2f) {5300, 1750});
    sfSprite_setPosition(game->obj[TREE][31].sprite, (sfVector2f) {5300, 800});
    sfSprite_setPosition(game->obj[TREE][32].sprite, (sfVector2f) {3500, 950});
    sfSprite_setPosition(game->obj[TREE][33].sprite, (sfVector2f) {3300, 950});
    sfSprite_setPosition(game->obj[TREE][34].sprite, (sfVector2f) {3700, 950});
    init_tree_three(game);
}

void init_tree(game_t *game)
{
    for (int i = 0; i != ALLOC_TREE; i++)
        game->obj[TREE][i] = init_object("assets/GAME/tree_red.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 120, 180});
    sfSprite_setPosition(game->obj[TREE][0].sprite, (sfVector2f) {1850, 2450});
    sfSprite_setPosition(game->obj[TREE][1].sprite, (sfVector2f) {2050, 2450});
    sfSprite_setPosition(game->obj[TREE][2].sprite, (sfVector2f) {2250, 2450});
    sfSprite_setPosition(game->obj[TREE][3].sprite, (sfVector2f) {2450, 2450});
    sfSprite_setPosition(game->obj[TREE][4].sprite, (sfVector2f) {2700, 2360});
    sfSprite_setPosition(game->obj[TREE][5].sprite, (sfVector2f) {1800, 2100});
    sfSprite_setPosition(game->obj[TREE][6].sprite, (sfVector2f) {1800, 1850});
    sfSprite_setPosition(game->obj[TREE][7].sprite, (sfVector2f) {2800, 2000});
    sfSprite_setPosition(game->obj[TREE][8].sprite, (sfVector2f) {1100, 1300});
    sfSprite_setPosition(game->obj[TREE][9].sprite, (sfVector2f) {1500, 1300});
    sfSprite_setPosition(game->obj[TREE][10].sprite, (sfVector2f) {1500, 750});
    sfSprite_setPosition(game->obj[TREE][11].sprite, (sfVector2f) {1100, 750});
    sfSprite_setPosition(game->obj[TREE][12].sprite, (sfVector2f) {1900, 650});
    sfSprite_setPosition(game->obj[TREE][13].sprite, (sfVector2f) {2300, 650});
    sfSprite_setPosition(game->obj[TREE][14].sprite, (sfVector2f) {2700, 650});
    sfSprite_setPosition(game->obj[TREE][15].sprite, (sfVector2f) {2800, 1300});
    init_tree_two(game);
}

void init_house(object_t **obj)
{
    for (int i = 0; i != ALLOC_HOUSE; i++)
        obj[HOUSE][i] = init_object("assets/GAME/house.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 153, 192});
    sfSprite_setPosition(obj[HOUSE][0].sprite, (sfVector2f) {1300, 1500});
    sfSprite_setPosition(obj[HOUSE][1].sprite, (sfVector2f) {1000, 1800});
    sfSprite_setPosition(obj[HOUSE][2].sprite, (sfVector2f) {1500, 1800});
    sfSprite_setPosition(obj[HOUSE][3].sprite, (sfVector2f) {1000, 2000});
    sfSprite_setPosition(obj[HOUSE][4].sprite, (sfVector2f) {1500, 2000});
    sfSprite_setPosition(obj[HOUSE][5].sprite, (sfVector2f) {1000, 2200});
    sfSprite_setPosition(obj[HOUSE][6].sprite, (sfVector2f) {1500, 2200});
    sfSprite_setPosition(obj[HOUSE][7].sprite, (sfVector2f) {1000, 2400});
    sfSprite_setPosition(obj[HOUSE][8].sprite, (sfVector2f) {1500, 2510});
    sfSprite_setPosition(obj[HOUSE][9].sprite, (sfVector2f) {2300, 890});
    sfSprite_setPosition(obj[HOUSE][10].sprite, (sfVector2f) {2500, 890});
    sfSprite_setPosition(obj[HOUSE][11].sprite, (sfVector2f) {2700, 890});
    sfSprite_setPosition(obj[HOUSE][12].sprite, (sfVector2f) {2100, 890});
    sfSprite_setPosition(obj[HOUSE][13].sprite, (sfVector2f) {2900, 890});
    sfSprite_setPosition(obj[HOUSE][14].sprite, (sfVector2f) {1900, 890});
    sfSprite_setPosition(obj[HOUSE][15].sprite, (sfVector2f) {3900, 2455});
    sfSprite_setPosition(obj[HOUSE][16].sprite, (sfVector2f) {4600, 965});
}
