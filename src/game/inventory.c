/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** manage inventory
*/

#include "rpg.h"

size_t count_inv_items(items_t *items)
{
    size_t size = 0;

    if (!items)
        return 0;
    for (int i = 0; i < NB_ITEMS; i++)
        if (items[i].exist && items[i].in_inv)
            size++;
    return (size > INV_HEIGHT * INV_WIDTH ? INV_HEIGHT * INV_WIDTH : size);
}

void draw_inv_items(sfRenderWindow *win, items_t *items, sfVector2f pos)
{
    int j = 0;
    int l = 0;
    size_t size = count_inv_items(items);

    pos.x += 10;
    pos.y += 40;
    for (int i = 0; i < INV_HEIGHT; i++)
        for (int k = 0; k < INV_WIDTH;) {
            if (l >= (int)size)
                return;
            if (items[j].in_inv && !items[j].in_stuff) {
                items[j].pos.x = pos.x + k * 50;
                items[j].pos.y = pos.y + i * 48;
                sfSprite_setPosition(items[j].sprite, items[j].pos);
                sfRenderWindow_drawSprite(win, items[j].sprite, NULL);
                k++;
                l++;
            }
            l += ((items[j].in_inv && items[j].in_stuff) ? 1 : 0);
            j++;
        }
}

void manage_mouse_in_inv(mouse_t *mouse, sfVector2f pos,
    game_t *game, bool *dog)
{
    sfVector2i mouse_pos = sfRenderWindow_mapCoordsToPixel
        (game->window, pos, game->view);

    if (!*dog) {
        sfMouse_setPosition(mouse_pos, (sfWindow *)game->window);
        mouse->position_mouse = pos;
        *dog = true;
    } else {
        mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        mouse->position_mouse = sfRenderWindow_mapPixelToCoords
            (game->window, mouse_pos, game->view);
    }
    sfSprite_setPosition(mouse->main_mouse, mouse->position_mouse);
    sfRenderWindow_drawSprite(game->window, mouse->main_mouse, NULL);
}

void manage_inventory(game_t *game, mouse_t *mouse, int *status)
{
    sfVector2f pos = {game->player.pos.x - 950, game->player.pos.y - 525};
    static bool dog = false;

    if (*status != 7) {
        dog = false;
        return;
    }
    sfSprite_setPosition(game->inv.sprite, pos);
    sfRenderWindow_drawSprite(game->window, game->inv.sprite, NULL);
    draw_inv_items(game->window, game->inv.items, pos);
    draw_stuff_items(game->window, game->inv.items, pos);
    manage_mouse_in_inv
        (mouse, (sfVector2f){pos.x += 150, pos.y += 125}, game, &dog);
    manage_items_in_inv(game, mouse);
}
