/*
** EPITECH PROJECT, 2018
** GAME MY RPG
** File description:
** game.c
*/

#include "rpg.h"

void get_game_settings(game_t *game)
{
    sfMusic_setVolume(game->music[MENU_MUSIC], game->option.main_song);
    sfMusic_setVolume(game->music[MAIN_MUSIC], game->option.main_song);
    sfMusic_setVolume(game->music[KILL_SOUND], game->option.second_song);
    sfMusic_setVolume(game->music[HIT_SCORPIO], game->option.second_song);
    sfMusic_setVolume(game->music[HIT_NINJA], game->option.second_song);
    sfMusic_setLoop(game->music[MENU_MUSIC], true);
    sfMusic_setLoop(game->music[MAIN_MUSIC], true);
}

void loop_main_game_three(all_t *all, int *status)
{
    switch (*status) {
        case 7:
            game_function(&all->game, &all->mouse, status);
            manage_inventory(&all->game, &all->mouse, status);
            break;
        case 8:
            for (int i = 0; i != 5; i++) {
                sfMusic_stop(all->game.music[i]);
                sfMusic_destroy(all->game.music[i]);
            }
            sfRenderWindow_close(all->game.window);
            break;
    }
}

void loop_main_game_two(all_t *all, int *status)
{
    switch (*status) {
        case 3:
            display_settings_game(&all->menu, &all->mouse, &all->game, status);
            break;
        case 4:
            display_profil_game(&all->menu, &all->mouse, &all->game, status);
            break;
        case 5:
            display_profil_name_player(
                &all->game.profil_game, &all->game, status);
            break;
        case 6:
            display_how_to_play(&all->menu, &all->game, status);
            break;
    }
    loop_main_game_three(all, status);
}

void loop_main_game(all_t *all, int *status, int *i)
{
    get_game_settings(&all->game);
    switch (*status) {
        case 1:
        if (*i == 1) {
            sfMusic_stop(all->game.music[MAIN_MUSIC]);
            sfMusic_play(all->game.music[MENU_MUSIC]);
            *i = 0;
        }
            display_game_menu(&all->menu, &all->mouse, &all->game, status);
            break;
        case 2:
            if (*i == 0) {
                sfMusic_stop(all->game.music[MENU_MUSIC]);
                sfMusic_play(all->game.music[MAIN_MUSIC]);
                *i = 1;
            }
            game_function(&all->game, &all->mouse, status);
            break;
    }
    loop_main_game_two(all, status);
}

void main_game(all_t *all, int *status)
{
    static int i = 0;

    sfRenderWindow_display(all->game.window);
    sfMusic_setVolume(all->game.music[MAIN_MUSIC], all->game.option.main_song);
    sfMusic_setVolume(all->game.music[MENU_MUSIC], all->game.option.main_song);
    sfMusic_setVolume(all->game.music[KILL_SOUND],
        all->game.option.second_song);
    sfMusic_setLoop(all->game.music[MAIN_MUSIC], true);
    sfMusic_setLoop(all->game.music[MENU_MUSIC], true);
    sfRenderWindow_setMouseCursorVisible(all->game.window, 0);
    loop_main_game(all, status, &i);
}
