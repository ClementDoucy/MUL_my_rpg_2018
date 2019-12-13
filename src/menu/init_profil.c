/*
** EPITECH PROJECT, 2018
** init_profil.c
** File description:
** initialization game profil
*/

#include "rpg.h"

void init_background_profil (profil_t *profil)
{
    char *background = "./assets/MENU/background_profil.jpg";
    char *cursor = "./assets/MENU/cursor_two.png";

    profil->sprite[0].sprite = sfSprite_create();
    profil->sprite[0].texture = sfTexture_createFromFile(background, NULL);
    sfSprite_setTexture(profil->sprite[0].sprite, profil->sprite[0].texture,
                        sfTrue);
    profil->sprite[1].sprite = sfSprite_create();
    profil->sprite[1].texture = sfTexture_createFromFile(cursor, NULL);
    sfSprite_setTexture(profil->sprite[1].sprite, profil->sprite[1].texture,
                        sfTrue);
    profil->sprite[1].pos.x = 580;
    profil->sprite[1].pos.y = 690;
    sfSprite_setPosition(profil->sprite[1].sprite, profil->sprite[1].pos);
}

void init_text_name_profil(profil_t *profil)
{
    profil->text[3].font =
    sfFont_createFromFile("./assets/POLICE/Long_Shot.ttf");
    profil->text[3].text = sfText_create();
    sfText_setFont(profil->text[3].text, profil->text[3].font);
    sfText_setCharacterSize(profil->text[3].text, 80);
    sfText_setColor(profil->text[3].text, sfBlack);
    profil->text[3].pos.x = 600;
    profil->text[3].pos.y = 680;
    sfText_setPosition(profil->text[3].text, profil->text[3].pos);
    profil->text[4].text = sfText_copy(profil->text[0].text);
    sfText_setString(profil->text[4].text, "Touch Enter for play !");
    profil->text[4].pos.x = 710;
    profil->text[4].pos.y = 900;
    sfText_setPosition(profil->text[4].text, profil->text[4].pos);
}

void init_text_profil (profil_t *profil)
{
    profil->text[0].font =
    sfFont_createFromFile("./assets/POLICE/Long_Shot.ttf");
    profil->text[0].text = sfText_create();
    sfText_setString(profil->text[0].text, "Please choose your name :");
    sfText_setFont(profil->text[0].text, profil->text[0].font);
    sfText_setCharacterSize(profil->text[0].text, 60);
    profil->text[0].pos.x = 710;
    profil->text[0].pos.y = 590;
    sfText_setPosition(profil->text[0].text, profil->text[0].pos);
    profil->text[1].text = sfText_copy(profil->text[0].text);
    sfText_setString(profil->text[1].text, "Press Enter to play");
    profil->text[1].pos.x = 1920;
    profil->text[1].pos.y = 1080;
    sfText_setPosition(profil->text[1].text, profil->text[1].pos);
    profil->text[2].text = sfText_copy(profil->text[0].text);
    sfText_setString(profil->text[2].text, "Name invalide, please retry !");
    profil->text[2].pos.x = 800;
    profil->text[2].pos.y = 200;
    sfText_setPosition(profil->text[2].text, profil->text[2].pos);
    init_text_name_profil(profil);
}

void init_profil(game_t *game)
{
    init_background_profil(&game->profil_game);
    init_text_profil(&game->profil_game);
}
