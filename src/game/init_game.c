/*
** EPITECH PROJECT, 2018
** INIT GAME MY RPG
** File description:
** init_game.c
*/

#include "particle.h"
#include "rpg.h"

void init_option_game(option_t *option)
{
    option->main_song = 50;
    option->second_song = 50;
}

void init_music(sfMusic **music)
{
    music[MENU_MUSIC] = sfMusic_createFromFile("assets/MUSIC/music_menu.ogg");
    music[MAIN_MUSIC] = sfMusic_createFromFile("assets/MUSIC/main_music.ogg");
    music[KILL_SOUND] = sfMusic_createFromFile("assets/MUSIC/kill.ogg");
    music[HIT_SCORPIO] = sfMusic_createFromFile("assets/MUSIC/hit_scorpio.ogg");
    music[HIT_NINJA] = sfMusic_createFromFile("assets/MUSIC/hit_ninja.ogg");
    sfMusic_play(music[MENU_MUSIC]);
}

void init_camera(game_t *game)
{
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f) {1920, 1080});
    sfView_setCenter(game->view, game->player.pos);
}

void init_main_game(game_t *game)
{
    init_option_game(&game->option);
    game->player = init_player("assets/GAME/player.png",
        (sfVector2f) {2000, 1200}, (sfIntRect) {38, 2, 68, 87});
    init_player2(&game->player);
    init_objects(game);
    init_competencies(game);
    game->enemy = init_enemy();
    init_pause(game);
    init_profil(game);
    init_camera(game);
    init_music(game->music);
    game->inv = init_inventory();
    game->status_bar = init_status_bar(game->inv.font);
    init_stat_panel(&(game->player.stat), game->inv.font);
    game->rain = create_rain();
}

void init_game(all_t *all)
{
    all->game.quest = init_quest();
    init_window(&all->game);
    sfRenderWindow_setFramerateLimit(all->game.window, 180);
    init_sprite_menu(&all->menu);
    init_main_game(&all->game);
    create_mouse(&all->mouse);
    init_pnj(&all->game);
}
