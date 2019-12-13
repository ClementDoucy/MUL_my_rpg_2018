/*
** EPITECH PROJECT, 2018
** create_sprite_menu.c
** File description:
** create button and background sprite for game menu
*/

#include "rpg.h"

void create_sprite_delete(menu_t *menu)
{
    char *delete = "./assets/MENU/delete_file.png";

    menu->sprite[12].sprite = sfSprite_create();
    menu->sprite[12].texture = sfTexture_createFromFile(delete, NULL);
    sfSprite_setTexture(menu->sprite[12].sprite, menu->sprite[12].texture,
                        sfTrue);
    menu->sprite[12].position.x = 1250;
    menu->sprite[12].position.y = 325;
    sfSprite_setPosition(menu->sprite[12].sprite, menu->sprite[12].position);
    menu->sprite[13].sprite = sfSprite_copy(menu->sprite[12].sprite);
    menu->sprite[13].position.x = 1250;
    menu->sprite[13].position.y = 525;
    sfSprite_setPosition(menu->sprite[13].sprite, menu->sprite[13].position);
    menu->sprite[14].sprite = sfSprite_copy(menu->sprite[12].sprite);
    menu->sprite[14].position.x = 1250;
    menu->sprite[14].position.y = 725;
    sfSprite_setPosition(menu->sprite[14].sprite, menu->sprite[14].position);
}

void create_button_play(menu_t *menu)
{
    char *button = "./assets/MENU/button_profil.png";

    menu->sprite[9].sprite = sfSprite_create();
    menu->sprite[9].texture = sfTexture_createFromFile(button, NULL);
    sfSprite_setTexture(menu->sprite[9].sprite, menu->sprite[9].texture,
                        sfTrue);
    menu->sprite[9].position.x = 700;
    menu->sprite[9].position.y = 300;
    sfSprite_setPosition(menu->sprite[9].sprite, menu->sprite[9].position);
    menu->sprite[10].sprite = sfSprite_copy(menu->sprite[9].sprite);
    menu->sprite[10].position.x = 700;
    menu->sprite[10].position.y = 500;
    sfSprite_setPosition(menu->sprite[10].sprite, menu->sprite[10].position);
    menu->sprite[11].sprite = sfSprite_copy(menu->sprite[9].sprite);
    menu->sprite[11].position.x = 700;
    menu->sprite[11].position.y = 700;
    sfSprite_setPosition(menu->sprite[11].sprite, menu->sprite[11].position);
}

void create_button_settings(menu_t *menu)
{
    char *button = "./assets/MENU/button_config.png";

    menu->sprite[6].sprite = sfSprite_create();
    menu->sprite[6].texture = sfTexture_createFromFile(button, NULL);
    sfSprite_setTexture(menu->sprite[6].sprite, menu->sprite[6].texture,
                        sfTrue);
    menu->sprite[6].position.x = 1515;
    menu->sprite[6].position.y = 245;
    sfSprite_setPosition(menu->sprite[6].sprite, menu->sprite[6].position);
    menu->sprite[7].sprite = sfSprite_copy(menu->sprite[6].sprite);
    menu->sprite[7].position.x = 1515;
    menu->sprite[7].position.y = 340;
    sfSprite_setPosition(menu->sprite[7].sprite, menu->sprite[7].position);
}

void create_background_menu(menu_t *menu)
{
    char *background = "./assets/MENU/background_menu.png";
    char *background_set = "./assets/MENU/background_settings.jpg";
    char *background_play = "./assets/MENU/background_profil_two.jpg";

    menu->sprite[0].sprite = sfSprite_create();
    menu->sprite[0].texture = sfTexture_createFromFile(background, NULL);
    sfSprite_setTexture(menu->sprite[0].sprite, menu->sprite[0].texture,
                        sfTrue);
    menu->sprite[1].position.x = 1000;
    menu->sprite[1].position.y = 0;
    menu->sprite[1].sprite = sfSprite_create();
    menu->sprite[1].texture = sfTexture_createFromFile(background_set, NULL);
    sfSprite_setTexture(menu->sprite[1].sprite, menu->sprite[1].texture,
                        sfTrue);
    sfSprite_setPosition(menu->sprite[1].sprite, menu->sprite[1].position);
    menu->sprite[8].sprite = sfSprite_create();
    menu->sprite[8].texture = sfTexture_createFromFile(background_play, NULL);
    sfSprite_setTexture(menu->sprite[8].sprite, menu->sprite[8].texture,
                        sfTrue);
}

void create_button_menu(menu_t *menu)
{
    char *button = "./assets/MENU/button_menu.png";

    menu->sprite[2].sprite = sfSprite_create();
    menu->sprite[2].texture = sfTexture_createFromFile(button, NULL);
    sfSprite_setTexture(menu->sprite[2].sprite, menu->sprite[2].texture,
                        sfTrue);
    menu->sprite[2].position.x = 1150;
    menu->sprite[2].position.y = 200;
    sfSprite_setPosition(menu->sprite[2].sprite, menu->sprite[2].position);
    menu->sprite[3].sprite = sfSprite_copy(menu->sprite[2].sprite);
    menu->sprite[3].position.x = 1150;
    menu->sprite[3].position.y = 400;
    sfSprite_setPosition(menu->sprite[3].sprite, menu->sprite[3].position);
    menu->sprite[4].sprite = sfSprite_copy(menu->sprite[2].sprite);
    menu->sprite[4].position.x = 1150;
    menu->sprite[4].position.y = 600;
    sfSprite_setPosition(menu->sprite[4].sprite, menu->sprite[4].position);
    menu->sprite[5].sprite = sfSprite_copy(menu->sprite[2].sprite);
    menu->sprite[5].position.x = 1150;
    menu->sprite[5].position.y = 800;
    sfSprite_setPosition(menu->sprite[5].sprite, menu->sprite[5].position);
}
