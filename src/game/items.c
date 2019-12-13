/*
** EPITECH PROJECT, 2019
** items.c
** File description:
** manage items
*/

#include "rpg.h"

static const sfVector2f stuff_slot[6] = {
    {122, 468},
    {170, 468},
    {260, 285},
    {260, 335},
    {260, 385},
    {260, 435}
};

void draw_items_in_world(items_t *items, sfRenderWindow *win)
{
    for (int i = 0; i < NB_ITEMS; i++)
        if (items[i].exist && !items[i].in_inv && !items[i].in_stuff)
            sfRenderWindow_drawSprite(win, items[i].sprite, NULL);
}

void loot_items(items_t *items, sfVector2f pos)
{
    if (count_inv_items(items) >= INV_HEIGHT * INV_WIDTH)
        return;
    for (int i = 0; i < NB_ITEMS; i++)
        if (!items[i].in_inv && !items[i].in_stuff)
            if ((pos.x >= items[i].pos.x - 30 && pos.x <= items[i].pos.x + 30)
                && (pos.y >= items[i].pos.y - 30 &&
                    pos.y <= items[i].pos.y + 30))
                items[i].in_inv = true;
}

void get_inv_items_rect(sfFloatRect *rect, items_t *items)
{
    int k = 0;

    for (int i = 0; i < NB_ITEMS; i++)
        if (items[i].in_inv) {
            rect[k] = sfSprite_getGlobalBounds(items[i].sprite);
            k++;
        }
}

void draw_stuff_items(sfRenderWindow *win, items_t *items, sfVector2f pos)
{
    sfVector2f tmp = {0, 0};

    pos.x -= 5;
    pos.y -= 6;
    for (int i = 0; i < NB_ITEMS; i++)
        if (items[i].in_stuff && items[i].exist) {
            tmp.x = pos.x + stuff_slot[items[i].type].x;
            tmp.y = pos.y + stuff_slot[items[i].type].y;
            sfSprite_setPosition(items[i].sprite, tmp);
            sfRenderWindow_drawSprite(win, items[i].sprite, NULL);
        }
}
