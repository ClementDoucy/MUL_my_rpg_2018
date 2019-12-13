/*
** EPITECH PROJECT, 2019
** gui_init.c
** File description:
** game user interface initialization
*/

#include "rpg.h"

static const items_init_t items_info[NB_ITEMS] = {
    {{0, 290, 30, 30}, CONS, false, HEAL},
    {{0, 290, 30, 30}, CONS, false, HEAL},
    {{0, 290, 30, 30}, CONS, false, HEAL},
    {{35, 160, 30, 30}, SWORD, true, DMG},
    {{35, 192, 30, 30}, SHIELD, true, PARADE},
    {{35, 224, 30, 30}, HELMET, true, ARMOR},
    {{130, 224, 30, 30}, CHESTPLATE, true, ARMOR},
    {{130, 256, 30, 30}, BELT, true, POWER},
    {{67, 256, 30, 30}, BOOTS, true, SPEED}
};

void init_items_methods(items_t *item, int nb)
{
    item->name = (!nb ? &get_items_name : NULL);
    item->effect_value = (!nb ? &get_value_effect : NULL);
    item->effect_val_as_str = (!nb ? &get_val_effect_as_str : NULL);
    item->effect_name = (!nb ? &get_effect_name : NULL);
}

void set_items_in_world(items_t *items)
{
    items[0].pos.x = 2604;
    items[0].pos.y = 805;
    sfSprite_setPosition(items[0].sprite, items[0].pos);
    items[1].pos.x = 1357;
    items[1].pos.y = 2179;
    sfSprite_setPosition(items[1].sprite, items[1].pos);
    items[2].pos.x = 1386;
    items[2].pos.y = 909;
    sfSprite_setPosition(items[2].sprite, items[2].pos);
}

items_t *init_items(void)
{
    items_t *items = malloc(sizeof(items_t) * NB_ITEMS);

    for (int i = 0; items && i < NB_ITEMS; i++) {
        items[i].sprite = sfSprite_create();
        items[i].text = sfTexture_createFromFile(
            "assets/GAME/items.png", &items_info[i].rect);
        sfSprite_setTexture(items[i].sprite, items[i].text, true);
        sfSprite_setScale(items[i].sprite, (sfVector2f){1.4, 1.4});
        items[i].in_inv = items_info[i].in_inv;
        items[i].in_stuff = false;
        items[i].type = items_info[i].type;
        items[i].id = i;
        items[i].effect = items_info[i].effect;
        init_items_methods(&(items[i]), i);
        items[i].exist = true;
        items[i].update = true;
    }
    set_items_in_world(items);
    return items;
}

inv_t init_inventory(void)
{
    inv_t inv;

    inv.text = sfTexture_createFromFile("assets/GAME/inventory.png", NULL);
    inv.sprite = sfSprite_create();
    sfSprite_setTexture(inv.sprite, inv.text, true);
    sfSprite_setScale(inv.sprite, (sfVector2f){1.4, 1.4});
    inv.items = init_items();
    inv.font = sfFont_createFromFile("assets/POLICE/Philosopher-Bold.ttf");
    for (int i = 0; i < 3; i++) {
        inv.infos[i] = sfText_create();
        sfText_setFont(inv.infos[i], inv.font);
    }
    return inv;
}
