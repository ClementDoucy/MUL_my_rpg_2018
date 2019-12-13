/*
** EPITECH PROJECT, 2019
** items_info.c
** File description:
** get info of items
*/

#include "rpg.h"

char *get_items_name(items_id_t id)
{
    static char *names[NB_ITEMS] = {
        "Healing potion",
        "Sword",
        "Shield",
        "Helmet",
        "Chestplate",
        "Magic belt",
        "Boots"
    };

    return names[id];
}

int get_value_effect(items_id_t id)
{
    static int values[NB_ITEMS] = {
        50,
        10,
        10,
        10,
        20,
        15,
        25
    };

    return values[id];
}

char *get_val_effect_as_str(items_id_t id)
{
    static char *values[NB_ITEMS] = {
        "50",
        "10",
        "10",
        "10",
        "20",
        "15",
        "25"
    };

    return values[id];
}

char *get_effect_name(items_effect_t id_effect)
{
    static char *effect[SPEED + 1] = {
        " \tHeal points",
        " \tDamage points",
        " \tParade points",
        " \tArmor points",
        " \tPower points",
        " \tspeed points"
    };

    return effect[id_effect];
}
