/*
** EPITECH PROJECT, 2019
** manag_player_stat.c
** File description:
** manage player stat
*/

#include "rpg.h"

player_stat_t init_player_stat(void)
{
    player_stat_t stat;

    stat.heal_point = 100;
    stat.max_hp = 100;
    stat.attack_damage = 20;
    stat.level = 1;
    stat.speed = (sfVector2i){1, 1};
    stat.armor_point = 0;
    stat.magic_power = 20;
    stat.xp = 0;
    return stat;
}

void init_stat_panel(player_stat_t *stat, sfFont *font)
{
    stat->panel = sfSprite_create();
    stat->texture = sfTexture_createFromFile("assets/GAME/stat.png", NULL);
    sfSprite_setTexture(stat->panel, stat->texture, true);
    for (int i = 0; i < 5; i++) {
        stat->text[i] = sfText_create();
        sfText_setFont(stat->text[i], font);
        sfText_setColor(stat->text[i], sfBlack);
    }
    sfText_setString(stat->text[0], "Heroe statistics");
}

void put_stat_in_text(player_stat_t stat, sfVector2f pos)
{
    char *str[4] = {
        my_strcat(int_to_str(stat.max_hp), " max hp"),
        my_strcat(int_to_str(stat.attack_damage), "attak damage"),
        my_strcat(int_to_str(stat.armor_point), " armor points"),
        my_strcat(int_to_str(stat.magic_power), " magic power")
    };

    pos.x += 90;
    sfText_setPosition(stat.text[0], pos);
    for (int i = 0; i < 4; i++) {
        pos.y += 65;
        sfText_setString(stat.text[i + 1], str[i]);
        sfText_setPosition(stat.text[i + 1], pos);
        free(str[i]);
    }
}

void manage_stat_panel(
    sfRenderWindow *win, player_stat_t stat, sfVector2f pos)
{
    static bool check = false;
    static sfClock *clock = NULL;

    if (!clock)
        clock = sfClock_create();
    if (sfKeyboard_isKeyPressed(sfKeyL) &&
        sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.2) {
        sfClock_restart(clock);
        check = !check;
    }
    if (!check)
        return;
    pos = (sfVector2f){pos.x - 950, pos.y + 20};
    put_stat_in_text(stat, pos);
    sfSprite_setPosition(stat.panel, pos);
    sfRenderWindow_drawSprite(win, stat.panel, NULL);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawText(win, stat.text[i], NULL);
}
