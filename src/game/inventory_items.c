/*
** EPITECH PROJECT, 2019
** inventory_items.c
** File description:
** manage items in inventory
*/

#include "rpg.h"

void remove_items(int i, items_t *items, sfVector2f pos)
{
    int l = 0;
    static sfClock *clock = NULL;

    if (clock && sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 0.3)
        return;
    clock = sfClock_create();
    for (int k = 0; k < NB_ITEMS; k++) {
        if (items[k].in_inv)
            l++;
        if (l == i + 1) {
            items[k].in_inv = false;
            items[k].in_stuff = false;
            items[k].pos.x = pos.x;
            items[k].pos.y = pos.y - 50;
            sfSprite_setPosition(items[k].sprite, items[k].pos);
            sfClock_restart(clock);
            return;
        }
    }
}

void get_rm_input(mouse_t *mouse, size_t size, sfFloatRect *rect, game_t *game)
{
    sfVector2f tmp = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        tmp = sfSprite_getPosition(mouse->main_mouse);
        for (int i = 0; i < (int)size; i++)
            if (sfFloatRect_contains(&(rect[i]), tmp.x, tmp.y)) {
                remove_items(i, game->inv.items, game->player.pos);
                return;
            }
    }
}

void manage_items_in_inv(game_t *game, mouse_t *mouse)
{
    size_t size = count_inv_items(game->inv.items);
    sfFloatRect rect[size];

    if (!size)
        return;
    get_inv_items_rect(rect, game->inv.items);
    get_rm_input(mouse, size, rect, game);
    manage_stuff(rect, game, mouse, size);
}
