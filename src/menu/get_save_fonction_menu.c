/*
** EPITECH PROJECT, 2018
** get_save_fonction.c
** File description:
** get save in the profil game
*/

#include "rpg.h"

bool save_fonction_pos_player(player_t *player, FILE *fp, size_t len)
{
    char *pos_x = NULL;
    char *pos_y = NULL;

    if (getline(&player->name, &len, fp) == -1)
        return (false);
    sfText_setString(player->text, player->name);
    if (getline(&pos_x, &len, fp) == -1)
        return (true);
    player->pos.x = my_getnbr(pos_x);
    if (player->pos.x == 0) {
        getline(&pos_x, &len, fp);
        player->pos.x = my_getnbr(pos_x);
    }
    getline(&pos_y, &len, fp);
    player->pos.y = my_getnbr(pos_y);
    sfSprite_setPosition(player->sprite, player->pos);
    return (true);
}

bool save_fonction_menu(player_t *player, FILE *fp, size_t len)
{
    if (!save_fonction_pos_player(player, fp, len))
        return (false);
    return (true);
}

bool get_save_fonction(game_t *game, player_t *player, char *filename,
                       int *status)
{
    FILE *fp;
    size_t len = 0;

    filename = my_strcat("./save/", filename);
    game->filename = filename;
    if ((fp = fopen(game->filename, "r")) != NULL) {
        if (!save_fonction_menu(player, fp, len)) {
            fclose(fp);
            return (false);
        }
        fclose(fp);
    }
    *status = 2;
    return (true);
}
