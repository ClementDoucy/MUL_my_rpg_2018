/*
** EPITECH PROJECT, 2018
** INIT OBJET AND PLAYER MY RPG
** File description:
** init_object.c
*/

#include "rpg.h"

object_t copy_object(object_t obj)
{
    object_t object;

    object.sprite = sfSprite_copy(obj.sprite);
    object.pos = obj.pos;
    sfSprite_setPosition(object.sprite, object.pos);
    object.rect = obj.rect;
    sfSprite_setTextureRect(object.sprite, object.rect);
    return object;
}

object_t *init_draw_object(object_t **obj)
{
    object_t *rep = malloc(sizeof(object_t) * ALLOC_MAX * ALLOC_OBJECT);
    int k = 0;

    for (int i = 1; i != 3; i++) {
        if (i == TREE)
            for (int j = 0; j != ALLOC_TREE; j++) {
                rep[k] = copy_object(obj[i][j]);
                k = k + 1;
            }
        if (i == HOUSE)
            for (int j = 0; j != ALLOC_HOUSE; j++) {
                rep[k] = copy_object(obj[i][j]);
                k = k + 1;
            }
    }
    return rep;
}

void init_pos_objects(object_t **obj)
{
    for (int i = 0; i != ALLOC_OBJECT; i++) {
        if (i == TREE)
            for (int j = 0; j != ALLOC_TREE; j++) {
                obj[i][j].pos = sfSprite_getPosition(obj[i][j].sprite);
            }
        if (i == HOUSE)
            for (int j = 0; j != ALLOC_HOUSE; j++) {
                obj[i][j].pos = sfSprite_getPosition(obj[i][j].sprite);
            }
    }
}

void init_objects(game_t *game)
{
    game->obj = malloc(sizeof(object_t *) * ALLOC_OBJECT);
    for (int i = 0; i != ALLOC_OBJECT; i++) {
        game->obj[i] = malloc(sizeof(object_t) * 40);
        if (i == TREE)
            game->obj[i] = malloc(sizeof(object_t) * ALLOC_TREE);
        if (i == HOUSE)
            game->obj[i] = malloc(sizeof(object_t) * ALLOC_HOUSE);
        if (i == BACK)
            game->obj[i] = malloc(sizeof(object_t) * ALLOC_BACK);
    }
    game->obj[BACK][0] = init_object("assets/GAME/map_ground.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 8000, 5000});
    game->obj[BACK][1] = init_object("assets/GAME/map_sea.jpg",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 8000, 5000});
    init_tree(game);
    init_house(game->obj);
    init_river(game);
    init_sign(game);
    init_pos_objects(game->obj);
    init_hit_rect_object(game->obj);
    game->draw_obj = sort_objects(init_draw_object(game->obj));
}
