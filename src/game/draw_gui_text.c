/*
** EPITECH PROJECT, 2019
** draw_gui_text.c
** File description:
** function to draw text in gui
*/

#include "rpg.h"

void draw_items_stat(items_t *items, inv_t inv, int k, sfRenderWindow *win)
{
    sfVector2f pos = sfSprite_getPosition(inv.sprite);

    pos.y += 230;
    pos.x += 10;
    sfText_setString(inv.infos[0], (*items).name(items[k].id));
    sfText_setString(inv.infos[1], (*items).effect_val_as_str(items[k].id));
    sfText_setString(inv.infos[2], (*items).effect_name(items[k].effect));
    for (int i = 0; i < 3; i++, pos.y += (i > 1 ? 0 : 30)) {
        sfText_setColor(inv.infos[i], sfBlack);
        sfText_setPosition(inv.infos[i], pos);
        sfRenderWindow_drawText(win, inv.infos[i], NULL);
    }
}
