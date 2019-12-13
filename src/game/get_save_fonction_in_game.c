/*
** EPITECH PROJECT, 2018
** GET SAVE FONCTION IN GAME MY RPG
** File description:
** get_save_fonction_in_game.c
*/

#include "rpg.h"

void get_save_fonction_in_game(game_t *game, player_t *player)
{
    char *pos_x = NULL;
    char *pos_y = NULL;

    if ((game->fd = open(game->filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR
    | S_IRGRP | S_IWGRP | S_IROTH)) != -1) {
        write(game->fd, player->name, my_strlen(player->name));
        write(game->fd, "\n", 1);
        pos_x = int_to_str((int)player->pos.x);
        write(game->fd, pos_x, my_strlen(pos_x));
        write(game->fd, "\n", 1);
        pos_y = int_to_str((int)player->pos.y);
        write(game->fd, pos_y, my_strlen(pos_y));
        write(game->fd, "\n", 1);
    }
}
