/*
** EPITECH PROJECT, 2018
** INIT PAUSE MY RPG
** File description:
** init_pause.c
*/

#include "rpg.h"

void init_background_pause(pause_t *pause)
{
    char *background = "./assets/GAME/background_pause.png";

    pause->sprite[0].sprite = sfSprite_create();
    pause->sprite[0].texture = sfTexture_createFromFile(background, NULL);
    sfSprite_setTexture(pause->sprite[0].sprite, pause->sprite[0].texture,
    sfTrue);
}

void init_button_pause(pause_t *pause)
{
    char *button = "./assets/MENU/button_menu.png";

    pause->sprite[1].sprite = sfSprite_create();
    pause->sprite[1].texture = sfTexture_createFromFile(button, NULL);
    sfSprite_setTexture(pause->sprite[1].sprite, pause->sprite[1].texture,
    sfTrue);
    pause->sprite[2].sprite = sfSprite_copy(pause->sprite[1].sprite);
    pause->sprite[3].sprite = sfSprite_copy(pause->sprite[1].sprite);
    pause->sprite[4].sprite = sfSprite_copy(pause->sprite[1].sprite);
}

void init_text_pause_two(pause_t *pause)
{
    pause->text[2].text = sfText_copy(pause->text[0].text);
    sfText_setString(pause->text[2].text, "SETTINGS");
    pause->text[3].text = sfText_copy(pause->text[0].text);
    sfText_setString(pause->text[3].text, "QUIT");
    pause->text[4].text = sfText_copy(pause->text[0].text);
    sfText_setString(pause->text[4].text, "Escape to resume");
    sfText_setCharacterSize(pause->text[4].text, 40);
}

void init_text_pause(pause_t *pause)
{
    pause->text[0].font =
    sfFont_createFromFile("./assets/POLICE/Long_Shot.ttf");
    pause->text[0].text = sfText_create();
    sfText_setString(pause->text[0].text, "RESUME");
    sfText_setFont(pause->text[0].text, pause->text[0].font);
    sfText_setCharacterSize(pause->text[0].text, 45);
    sfText_setColor(pause->text[0].text, sfBlack);
    pause->text[1].text = sfText_copy(pause->text[0].text);
    sfText_setString(pause->text[1].text, "SAVE");
    init_text_pause_two(pause);
}

void init_pause(game_t *game)
{
    init_background_pause(&game->pause_game);
    init_button_pause(&game->pause_game);
    init_text_pause(&game->pause_game);
    game->status_pause = 0;
    game->status_settings = 0;
}
