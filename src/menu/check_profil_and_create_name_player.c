/*
** EPITECH PROJECT, 2018
** check_profil_and_create_name_player.c
** File description:
** check profil in the profil background and create name player
*/

#include "rpg.h"

bool stock_name_in_save(game_t *game, player_t *player)
{
    game->fd = open(game->filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR |
    S_IRGRP | S_IWGRP | S_IROTH);
    write(game->fd, player->name, my_strlen(player->name));
    write(game->fd, "\n", 1);
    if (close(game->fd) == -1)
        return (false);
    sfText_setString(player->text, player->name);
    return (true);
}

void check_file(player_t *player, menu_t *menu)
{
    size_t len = 0;
    FILE *fp;

    if ((fp = fopen("./save/save_one", "r")) != NULL) {
        if (getline(&player->name, &len, fp) == -1)
            player->name = "EMPTY";
        sfText_setString(menu->text[6].text, player->name);
        fclose(fp);
    }
    if ((fp = fopen("./save/save_two", "r")) != NULL) {
        if (getline(&player->name, &len, fp) == -1)
            player->name = "EMPTY";
        sfText_setString(menu->text[7].text, player->name);
        fclose(fp);
    }
    if ((fp = fopen("./save/save_three", "r")) != NULL) {
        if (getline(&player->name, &len, fp) == -1)
            player->name = "EMPTY";
        sfText_setString(menu->text[8].text, player->name);
        fclose(fp);
    }
}

bool get_name_file_and_close_dir(
    game_t *game, DIR *rep, char *filename, int *status)
{
    if (closedir(rep) == -1)
        return (false);
    filename = my_strcat("./save/", filename);
    game->filename = filename;
    *status = 5;
    return (true);
}

bool check_save(game_t *game, char *filename, int *status)
{
    DIR* rep = NULL;
    int i = 0;
    struct dirent *directory_read = NULL;

    game->fd = 0;
    rep = opendir("./save");
    if (rep == NULL) {
        my_putstr("Error open directory\n");
        return (false);
    }
    while ((directory_read = readdir(rep)) != NULL) {
        while (directory_read->d_name[i] == filename[i])
            i++;
        if (i == 9 || i == 11) {
            if (get_save_fonction(game, &game->player, filename, status))
                return (true);
        }
        i = 0;
    }
    return (get_name_file_and_close_dir(game, rep, filename, status));
}
