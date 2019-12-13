/*
** EPITECH PROJECT, 2018
** INIT SPRITE GAME MY RPG
** File description:
** init_sprite_game.c
*/

#include "rpg.h"

void init_hit_rect_object(object_t **obj)
{
    for (int i = 1; i != 3; i++) {
        if (i == TREE)
            for (int j = 0; j != ALLOC_TREE; j++)
                obj[i][j].hit_rect = (sfIntRect) {35, 140, 120, 30};
        if (i == HOUSE)
            for (int j = 0; j != ALLOC_HOUSE; j++)
                obj[i][j].hit_rect = (sfIntRect) {35, 112, 155, 80};
    }
}

object_t init_object(char *file, sfVector2f pos, sfIntRect rect)
{
    object_t object;

    object.sprite = sfSprite_create();
    object.text = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(object.sprite, object.text, sfFalse);
    object.pos = pos;
    sfSprite_setPosition(object.sprite, object.pos);
    object.rect = rect;
    sfSprite_setTextureRect(object.sprite, object.rect);
    return object;
}
