/*
** EPITECH PROJECT, 2018
** create_text_info_menu.c
** File description:
** create text for game menu
*/

#include "rpg.h"

void create_text_play(menu_t *menu)
{
    menu->text[5].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[5].text, "Chose your game part");
    menu->text[5].position.x = 720;
    menu->text[5].position.y = 120;
    sfText_setCharacterSize(menu->text[5].text, 75);
    sfText_setPosition(menu->text[5].text, menu->text[5].position);
    menu->text[6].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[6].text, "EMPTY");
    menu->text[6].position.x = 940;
    menu->text[6].position.y = 320;
    sfText_setPosition(menu->text[6].text, menu->text[6].position);
    menu->text[7].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[7].text, "EMPTY");
    menu->text[7].position.x = 940;
    menu->text[7].position.y = 520;
    sfText_setPosition(menu->text[7].text, menu->text[7].position);
    menu->text[8].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[8].text, "EMPTY");
    menu->text[8].position.x = 940;
    menu->text[8].position.y = 720;
    sfText_setPosition(menu->text[8].text, menu->text[8].position);
}

void create_text_menu_two(menu_t *menu)
{
    menu->text[3].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[3].text, "HTP");
    menu->text[3].position.x = 1375;
    menu->text[3].position.y = 640;
    sfText_setPosition(menu->text[3].text, menu->text[3].position);
    menu->text[4].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[4].text, "QUIT");
    menu->text[4].position.x = 1370;
    menu->text[4].position.y = 840;
    sfText_setPosition(menu->text[4].text, menu->text[4].position);
    menu->text[9].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[9].text, "");
    sfText_setCharacterSize(menu->text[9].text, 35);
    menu->text[9].position.x = 1200;
    menu->text[9].position.y = 620;
    sfText_setPosition(menu->text[9].text, menu->text[9].position);
}

void create_text_menu(menu_t *menu)
{
    menu->text[1].font = sfFont_createFromFile("./assets/POLICE/Long_Shot.ttf");
    menu->text[1].text = sfText_create();
    sfText_setString(menu->text[1].text, "PLAY");
    sfText_setFont(menu->text[1].text, menu->text[1].font);
    sfText_setCharacterSize(menu->text[1].text, 45);
    menu->text[1].position.x = 1365;
    menu->text[1].position.y = 244;
    sfText_setPosition(menu->text[1].text, menu->text[1].position);
    sfText_setColor(menu->text[1].text, sfBlack);
    menu->text[2].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[2].text, "SETTINGS");
    menu->text[2].position.x = 1335;
    menu->text[2].position.y = 440;
    sfText_setPosition(menu->text[2].text, menu->text[2].position);
    menu->text[10].text = sfText_copy(menu->text[1].text);
    sfText_setString(menu->text[10].text,
    "move your mouse on the buttons\n and click to change the keys");
    menu->text[10].position.x = 1160;
    menu->text[10].position.y = 460;
    sfText_setPosition(menu->text[10].text, menu->text[10].position);
    create_text_menu_two(menu);
}

void create_text_title(menu_t *menu)
{
    menu->text[0].font = sfFont_createFromFile(
        "./assets/POLICE/PrinceValiant.ttf");
    menu->text[0].text = sfText_create();
    sfText_setString(menu->text[0].text, "Heroes");
    sfText_setFont(menu->text[0].text, menu->text[0].font);
    sfText_setCharacterSize(menu->text[0].text, 100);
    menu->text[0].position.x = 380;
    menu->text[0].position.y = 170;
    sfText_setPosition(menu->text[0].text, menu->text[0].position);
    sfText_setColor(menu->text[0].text, sfBlack);
}
