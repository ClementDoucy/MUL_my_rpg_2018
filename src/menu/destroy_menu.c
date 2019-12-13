/*
** EPITECH PROJECT, 2018
** destroy_menu.c
** File description:
** destroy game menu
*/

#include "rpg.h"

void destroy_sprite_menu(menu_t *menu)
{
    int i = 0;

    sfTexture_destroy(menu->sprite[0].texture);
    sfTexture_destroy(menu->sprite[1].texture);
    sfTexture_destroy(menu->sprite[2].texture);
    sfTexture_destroy(menu->sprite[6].texture);
    sfTexture_destroy(menu->sprite[8].texture);
    sfTexture_destroy(menu->sprite[9].texture);
    while (i != 11) {
        sfSprite_destroy(menu->sprite[i].sprite);
        menu->sprite[i].position.x = 0;
        menu->sprite[i].position.y = 0;
        menu->sprite[i].position_anim.x = 0;
        menu->sprite[i].position_anim.y = 0;
        i = i + 1;
    }
}

void destroy_text_menu(menu_t *menu)
{
    int i = 0;

    sfFont_destroy(menu->text[0].font);
    sfFont_destroy(menu->text[1].font);
    while (i != 8) {
        sfText_destroy(menu->text[i].text);
        menu->text[i].position.x = 0;
        menu->text[i].position.y = 0;
        menu->text[i].position_anim.x = 0;
        menu->text[i].position_anim.y = 0;
        i = i + 1;
    }
}

void destroy_menu(menu_t *menu)
{
    destroy_sprite_menu(menu);
    destroy_text_menu(menu);
}
