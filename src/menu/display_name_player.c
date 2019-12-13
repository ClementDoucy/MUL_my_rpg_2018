/*
** EPITECH PROJECT, 2018
** display_name_player.c
** File description:
** create background choose name player
*/

#include "rpg.h"

int entered_name(profil_t *profil, player_t *player, int i)
{
    char *name = NULL;
    int o = 0;

    name = malloc(sizeof(char) * my_strlen(player->name));
    while (o != i - 1) {
        name[o] = player->name[o];
        o++;
    }
    player->name = name;
    i--;
    profil->sprite[1].pos.x = profil->sprite[1].pos.x - 35;
    return (i);
}

void event_profil_name_entered(sfKeyCode str, profil_t *profil,
    player_t *player)
{
    static int i = 0;

    if (i == 0) {
        player->name = malloc(sizeof(char) * 120);
        player->name[0] = '\0';
    }
    if ((int)str == 8 && i != 0)
        i = entered_name(profil, player, i);
    else {
        if (i != 7 && (int)str > 59 && (int)str < 123) {
            player->name[i] = str;
            i++;
            player->name[i] = '\0';
            profil->sprite[1].pos.x = profil->sprite[1].pos.x + 35;
        }
    }
    sfText_setString(profil->text[3].text, player->name);
}

void event_profil_name_valided(profil_t *profil, game_t *game, int *status)
{
    if (game->player.name == NULL)
        sfText_setColor(profil->text[0].text, sfRed);
    else {
        if (!stock_name_in_save(game, &game->player))
            *status = 8;
        *status = 2;
    }
}

void analyse_events_profil_name(profil_t *profil, game_t *game, int *status)
{
    while (sfRenderWindow_pollEvent(game->window, &profil->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            *status = 4;
        if (sfKeyboard_isKeyPressed(sfKeyReturn) == 1)
            event_profil_name_valided(profil, game, status);
        if (profil->event.type == sfEvtTextEntered) {
            event_profil_name_entered(profil->event.key.code, profil,
            &game->player);
            sfText_setColor(profil->text[0].text, sfWhite);
        }
    }
}

void display_profil_name_player(profil_t *profil, game_t *game, int *status)
{
    sfRenderWindow_drawSprite(game->window, profil->sprite[0].sprite, NULL);
    sfSprite_setPosition(profil->sprite[1].sprite, profil->sprite[1].pos);
    sfRenderWindow_drawSprite(game->window, profil->sprite[1].sprite, NULL);
    sfRenderWindow_drawText(game->window, profil->text[0].text, NULL);
    sfRenderWindow_drawText(game->window, profil->text[1].text, NULL);
    sfRenderWindow_drawText(game->window, profil->text[3].text, NULL);
    sfRenderWindow_drawText(game->window, profil->text[4].text, NULL);
    analyse_events_profil_name(profil, game, status);
}
