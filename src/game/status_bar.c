/*
** EPITECH PROJECT, 2019
** status_bar.c
** File description:
** status bar management
*/

#include "rpg.h"

void draw_status_bar(status_bar_t status_bar, sfVector2f pos,
    sfRenderWindow *win, player_stat_t stat)
{
    int nb_blocs = stat.heal_point / (stat.max_hp / 5);

    pos.x += 480;
    pos.y -= 504;
    sfSprite_setPosition(status_bar.bar, pos);
    sfRenderWindow_drawSprite(win, status_bar.bar, NULL);
    pos.x += 198;
    pos.y += 60;
    for (int i = 0; i < nb_blocs; i++, pos.x += 41.5) {
        sfSprite_setPosition(status_bar.bloc[i], pos);
        sfRenderWindow_drawSprite(win, status_bar.bloc[i], NULL);
    }
}

void draw_nb_hp(sfRenderWindow *win, sfVector2f pos,
    sfText *nb_hp, player_stat_t stat)
{
    char *str = "  ";

    pos.x += 620;
    pos.y -= 445;
    str = my_strcat(str, int_to_str(stat.heal_point));
    str = my_strcat(str, " /\n");
    str = my_strcat(str, int_to_str(stat.max_hp));
    str = my_strcat(str, " hp");
    sfText_setString(nb_hp, str);
    sfText_setPosition(nb_hp, pos);
    sfRenderWindow_drawText(win, nb_hp, NULL);
}

void manage_status_bar(game_t *game)
{
    draw_status_bar(
        game->status_bar, game->player.pos, game->window, game->player.stat);
    draw_nb_hp(game->window, game->player.pos,
        game->status_bar.nb_hp, game->player.stat);
}
