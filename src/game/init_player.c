/*
** EPITECH PROJECT, 2019
** init player
** File description:
** init the player
*/

#include "particle.h"
#include "rpg.h"

quest_t init_quest(void)
{
    sfFont *font = sfFont_createFromFile("./assets/POLICE/BlackCastleMF.ttf");
    quest_t quest;

    for (int i = 0; i != 4; i++)
        quest.is_quest[i] = false;
    quest.count = 0;
    quest.goal = 0;
    quest.nbr_of_dialog = 3;
    quest.quest_nbr = 0;
    quest.txt = sfText_create();
    sfText_setFont(quest.txt, font);
    sfText_setColor(quest.txt, sfBlack);
    return quest;
}

void init_lvl_text(player_t *player)
{
    sfFont *font = sfFont_createFromFile("./assets/POLICE/BlackCastleMF.ttf");

    player->exp_bar.txt_lvl = sfText_create();
    sfText_setFont(player->exp_bar.txt_lvl, font);
    sfText_setColor(player->exp_bar.txt_lvl, sfBlack);
}

void init_player3(player_t *player)
{
    player->font = sfFont_createFromFile("./assets/POLICE/PrinceValiant.ttf");
    player->text = sfText_create();
    sfText_setFont(player->text, player->font);
    sfText_setCharacterSize(player->text, 45);
    sfText_setColor(player->text, sfBlack);
    player->blood = create_blood_effect();
}

void init_player2(player_t *player)
{
    sfTexture *text = sfTexture_createFromFile("assets/GAME/exp_bar.jpg", NULL);

    player->is_move = false;
    player->is_attack = false;
    player->is_dash = false;
    player->exp = 0;
    player->max_exp = 20;
    player->lvl = 1;
    player->stat.percent_armor = player->stat.armor_point / 100;
    player->is_punch = false;
    player->exp_bar.bar = sfSprite_create();
    player->exp_bar.rect_bar = (sfIntRect) {0, 0, 258, 16};
    sfSprite_setTexture(player->exp_bar.bar, text, sfFalse);
    sfSprite_setTextureRect(player->exp_bar.bar, player->exp_bar.rect_bar);
    player->exp_bar.total_width = 258;
    init_lvl_text(player);
    player->is_alive = true;
    init_player3(player);
}

player_t init_player(char *file, sfVector2f pos, sfIntRect rect)
{
    player_t player;
    sfTexture *texture;

    player.sprite = sfSprite_create();
    texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(player.sprite, texture, sfFalse);
    player.pos = pos;
    sfSprite_setPosition(player.sprite, player.pos);
    player.rect = rect;
    sfSprite_setTextureRect(player.sprite, player.rect);
    player.width = rect.width;
    player.length = rect.height;
    player.anim_time.clock = sfClock_create();
    player.anim_time.seconds = 0;
    player.stat = init_player_stat();
    player.stat.level = 1;
    player.is_reverse = false;
    player.name = NULL;
    sfSprite_setOrigin(player.sprite,
                (sfVector2f) {player.width / 2, player.length / 2});
    return player;
}
