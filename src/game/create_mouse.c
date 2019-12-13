/*
** EPITECH PROJECT, 2018
** CREATE MOUSE MY RPG
** File description:
** create_mouse.c
*/

#include "rpg.h"

void create_mouse(mouse_t *mouse)
{
    char *mouse_one = "./assets/GAME/cursor.png";

    mouse->main_mouse = sfSprite_create();
    mouse->texture_main_mouse = sfTexture_createFromFile(mouse_one, NULL);
}
