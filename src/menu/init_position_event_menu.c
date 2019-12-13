/*
** EPITECH PROJECT, 2018
** init_position_event_menu.c
** File description:
** create evenement position for game menu
*/

#include "rpg.h"

void init_position_anim_button(menu_t *menu)
{
    menu->sprite[2].position_anim.x = 1130;
    menu->sprite[2].position_anim.y = 190;
    menu->sprite[3].position_anim.x = 1130;
    menu->sprite[3].position_anim.y = 390;
    menu->sprite[4].position_anim.x = 1130;
    menu->sprite[4].position_anim.y = 590;
    menu->sprite[5].position_anim.x = 1130;
    menu->sprite[5].position_anim.y = 790;
}

void init_position_text_button(menu_t *menu)
{
    menu->text[1].position_anim.x = 1370;
    menu->text[1].position_anim.y = 240;
    menu->text[2].position_anim.x = 1340;
    menu->text[2].position_anim.y = 440;
    menu->text[3].position_anim.x = 1375;
    menu->text[3].position_anim.y = 640;
    menu->text[4].position_anim.x = 1375;
    menu->text[4].position_anim.y = 840;
}

void init_position_event_menu(menu_t *menu, sfVector2f main_scale)
{
    sfSprite_setScale(menu->sprite[2].sprite, main_scale);
    sfSprite_setScale(menu->sprite[3].sprite, main_scale);
    sfSprite_setScale(menu->sprite[4].sprite, main_scale);
    sfSprite_setScale(menu->sprite[5].sprite, main_scale);
    sfSprite_setPosition(menu->sprite[2].sprite, menu->sprite[2].position);
    sfSprite_setPosition(menu->sprite[3].sprite, menu->sprite[3].position);
    sfSprite_setPosition(menu->sprite[4].sprite, menu->sprite[4].position);
    sfSprite_setPosition(menu->sprite[5].sprite, menu->sprite[5].position);
    sfText_setPosition(menu->text[1].text, menu->text[1].position);
    sfText_setPosition(menu->text[2].text, menu->text[2].position);
    sfText_setPosition(menu->text[3].text, menu->text[3].position);
    sfText_setPosition(menu->text[4].text, menu->text[4].position);
}
