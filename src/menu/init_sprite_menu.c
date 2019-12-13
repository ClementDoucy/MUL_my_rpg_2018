/*
** EPITECH PROJECT, 2018
** init_sprite_menu.c
** File description:
** initialization sprite and text for game menu
*/

#include "rpg.h"

void init_how_to_play (menu_t *menu)
{
    char *background = "./assets/MENU/background_how_to_play.jpg";

    menu->sprite[15].sprite = sfSprite_create();
    menu->sprite[15].texture = sfTexture_createFromFile(background, NULL);
    sfSprite_setTexture(menu->sprite[15].sprite, menu->sprite[15].texture,
                        sfTrue);
    menu->text[11].font =
    sfFont_createFromFile("./assets/POLICE/Long_Shot.ttf");
    menu->text[11].text = sfText_create();
    sfText_setString(menu->text[11].text, "HOW TO PLAY");
    sfText_setFont(menu->text[11].text, menu->text[11].font);
    sfText_setCharacterSize(menu->text[11].text, 55);
    sfText_setColor(menu->text[11].text, sfBlack);
    menu->text[11].position.x = 850;
    menu->text[11].position.y = 20;
    sfText_setPosition(menu->text[11].text, menu->text[11].position);
}

void init_sprite_menu(menu_t *menu)
{
    create_background_menu(menu);
    create_button_menu(menu);
    create_button_settings(menu);
    create_button_play(menu);
    create_text_title(menu);
    create_text_menu(menu);
    create_text_play(menu);
    create_sprite_delete(menu);
    init_position_text_button(menu);
    init_position_anim_button(menu);
    init_how_to_play(menu);
    menu->status_menu = 1;
}
