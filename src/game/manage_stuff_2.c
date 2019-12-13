/*
** EPITECH PROJECT, 2019
** manage_stuff_2.c
** File description:
** manage stuff 2
*/

#include "rpg.h"

void check_slot(items_t **items, items_type_t target, int k)
{
    for (int i = 0; i < NB_ITEMS; i++)
        if (k != i && (*items)[i].type == target) {
            (*items)[i].in_stuff = false;
            return;
        }
}

void update_stat_2(items_t *items, player_stat_t *stat, int coef, items_t ptr)
{
    switch (items->type)
    {
    case 4:
        stat->magic_power += ptr.effect_value(items->id) * coef;
        items->update = true;
        break;
    case 5:
        stat->armor_point += ptr.effect_value(items->id) * coef;
        items->update = true;
        break;
    case 6:
        break;
    }
}

void update_stat(items_t *items, player_stat_t *stat, int coef, items_t ptr)
{
    switch (items->type)
    {
    case 0:
        stat->attack_damage += ptr.effect_value(items->id) * coef;
        items->update = true;
        break;
    case 1:
        stat->armor_point += ptr.effect_value(items->id) * coef;
        items->update = true;
        break;
    case 2:
        stat->armor_point += ptr.effect_value(items->id) * coef;
        items->update = true;
        break;
    case 3:
        stat->armor_point += ptr.effect_value(items->id) * coef;
        items->update = true;
        break;
    }
    update_stat_2(items, stat, coef, ptr);
}

void update_removed_items(items_t *items, player_stat_t *stat)
{
    for (int i = 0; i < NB_ITEMS; i++)
        if (items[i].in_inv && !items[i].in_stuff && !items[i].update)
            update_stat(&(items[i]), stat, -1, items[0]);
}

void update_stat_with_stuff(items_t *items, player_stat_t *stat)
{
    for (int i = 0; i < NB_ITEMS; i++)
        if (items[i].in_stuff && !items[i].update)
            update_stat(&(items[i]), stat, 1, items[0]);
    update_removed_items(items, stat);
}
