/*
** EPITECH PROJECT, 2018
** MANAGE MOUSE MOVE MY RPG
** File description:
** manage_mouse_move.c
*/

#include "rpg.h"

void manage_mouse_move_main(sfMouseMoveEvent event, mouse_t *mouse)
{
    mouse->position_mouse.x = event.x;
    mouse->position_mouse.y = event.y;
    sfSprite_setPosition(mouse->main_mouse, mouse->position_mouse);
    sfSprite_setTexture(mouse->main_mouse, mouse->texture_main_mouse, sfTrue);
}
