/*
** EPITECH PROJECT, 2018
** init_pnj.c
** File description:
** file for init pnj posotion and dialog
*/

#include "rpg.h"

static void create_all_sprite_for_pnj_icon(char *file, pnj_t *new_pnj)
{
    sfTexture *texture;

    new_pnj->sprite = sfSprite_create();
    new_pnj->icon = sfSprite_create();
    new_pnj->box = sfSprite_create();
    new_pnj->pic = sfSprite_create();
    texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(new_pnj->sprite, texture, sfFalse);
    texture = sfTexture_createFromFile("assets/GAME/dialog.png", NULL);
    sfSprite_setTexture(new_pnj->icon, texture, sfFalse);
    texture = sfTexture_createFromFile("assets/GAME/box_dialog.png", NULL);
    sfSprite_setTexture(new_pnj->box, texture, sfFalse);
    texture = sfTexture_createFromFile("assets/GAME/portait.png", NULL);
    sfSprite_setTexture(new_pnj->pic, texture, sfFalse);
}

static void fix_rect_and_pos_on_icon(pnj_t *new_pnj,  sfVector2f pos,
    sfIntRect rect)
{
    new_pnj->pos = pos;
    sfSprite_setPosition(new_pnj->sprite, new_pnj->pos);
    new_pnj->pos.x = pos.x + 35;
    new_pnj->pos.y = pos.y - 35;
    sfSprite_setPosition(new_pnj->icon, new_pnj->pos);
    sfSprite_setPosition(new_pnj->box, (sfVector2f) {1384, 1225});
    new_pnj->rect = rect;
    sfSprite_setTextureRect(new_pnj->sprite, new_pnj->rect);
    new_pnj->icon_rect = (sfIntRect) {0, 0, 147, 50};
    sfSprite_setTextureRect(new_pnj->icon, new_pnj->icon_rect);
    sfSprite_setTextureRect(new_pnj->pic, (sfIntRect) {144, 144, 144, 144});
}

sfText *create_new_text_page(char *message)
{
    sfFont *font;
    sfText *new;

    new = sfText_create();
    font = sfFont_createFromFile("./assets/POLICE/BlackCastleMF.ttf");
    sfText_setString(new, message);
    sfText_setFont(new, font);
    return new;
}

pnj_t create_one_pnj(char *file, sfVector2f pos, sfIntRect rect)
{
    pnj_t new_pnj;
    char *txt = my_strcat("hero", "! Welcome to Malokran");

    create_all_sprite_for_pnj_icon(file, &new_pnj);
    fix_rect_and_pos_on_icon(&new_pnj, pos, rect);
    new_pnj.txt[0] = create_new_text_page(my_strcat("Hi ", txt));
    new_pnj.txt[1] = create_new_text_page(
        "My name is Celestia! I am a yolo wizard.");
    new_pnj.txt[2] = create_new_text_page(
        "To begin we have to train yourself to be able to fight the evil!");
    new_pnj.txt[3] = create_new_text_page(
        "Fights 8 scorpio and come back when you finish!");
    new_pnj.message_is_display = false;
    return new_pnj;
}

void init_pnj(game_t *game)
{
    sfVector2f reverse = {-1, 1};

    game->all_pnj[0] = create_one_pnj("assets/GAME/npc_four.png",
        (sfVector2f) {1384, 1225}, (sfIntRect) {0, 0, 83, 87});
    sfSprite_setOrigin(game->all_pnj[0].sprite, (sfVector2f) {43, 0});
    sfSprite_scale(game->all_pnj[0].sprite, reverse);
}
