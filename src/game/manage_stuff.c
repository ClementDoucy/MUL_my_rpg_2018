/*
** EPITECH PROJECT, 2019
** manage_stuff.c
** File description:
** manage stuff
*/

#include "rpg.h"

void stuff_items(int i, items_t *items, player_stat_t *stat)
{
    int l = 0;

    for (int k = 0; k < NB_ITEMS; k++) {
        l += (items[k].in_inv ? 1 : 0);
        if (l == i + 1 && items[k].type == CONS) {
            stat->heal_point += 50;
            stat->heal_point = stat->heal_point > 100 ? 100 : stat->heal_point;
            items[k].exist = false;
            items[k].in_inv = false;
            return;
        } if (l == i + 1 && items[k].in_stuff) {
            items[k].in_stuff = false;
            items[k].update = false;
            return;
        } if (l == i + 1 && (items[k].type >= 0 && items[k].type <= 5)) {
            check_slot(&items, items[k].type, k);
            items[k].in_stuff = true;
            items[k].update = false;
            return;
        }
    }
}

void get_stuff_input(
    sfFloatRect *rect, sfSprite *mouse, game_t *game, size_t size)
{
    sfVector2f tmp = {0, 0};

    if (catch_double_click(game->event)) {
        tmp = sfSprite_getPosition(mouse);
        for (int i = 0; i < (int)size; i++)
            if (sfFloatRect_contains(&(rect[i]), tmp.x, tmp.y)) {
                stuff_items(i, game->inv.items, &(game->player.stat));
                return;
            }
    }
}

void draw_items_info(int i, items_t *items, inv_t inv, sfRenderWindow *win)
{
    int l = 0;

    for (int k = 0; k < NB_ITEMS; k++) {
        if (items[k].in_inv)
            l++;
        if (l == i + 1) {
            draw_items_stat(items, inv, k, win);
            return;
        }
    }
}

void is_mouse_on_items(
    game_t *game, sfSprite *mouse, sfFloatRect *rect, size_t size)
{
    sfVector2f pos = sfSprite_getPosition(mouse);

    for (int i = 0; i < (int)size; i++)
        if (sfFloatRect_contains(&(rect[i]), pos.x, pos.y)) {
            draw_items_info(i, game->inv.items, game->inv, game->window);
            return;
        }
}

void manage_stuff(
    sfFloatRect *rect, game_t *game, mouse_t *mouse, size_t size)
{
    get_stuff_input(rect, mouse->main_mouse, game, size);
    is_mouse_on_items(game, mouse->main_mouse, rect, size);
    update_stat_with_stuff(game->inv.items, &(game->player.stat));
}
