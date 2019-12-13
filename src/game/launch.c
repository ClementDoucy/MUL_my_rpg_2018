/*
** EPITECH PROJECT, 2018
** LAUNCH MY RPG
** File description:
** launch.c
*/

#include "particle.h"
#include "rpg.h"
#include "stdbool.h"

void start_game_rpg(all_t *all, int status)
{
    while (sfRenderWindow_isOpen(all->game.window)) {
        main_game(all, &status);
    }
}

int print_message_help(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Finite my_rpg created with CSFML.\n");
        my_putchar('\n');
        my_putchar('\n');
        my_putstr("USAGE\n");
        my_putstr("   ./my_rpg\n");
        my_putchar('\n');
        my_putstr("USER INTERACTIONS\n");
        my_putstr(" USE MOUSE    many interaction\n");
        my_putchar('\n');
        my_putstr("This game was created by Clement Doucy, Clement Challopin");
        my_putstr(", Adrien Mollat and Lucas Guyader !\n");
        my_putstr("Have a good time !\n");
        return (0);
    }
    return (1);
}

bool check_error(int argc, char **argv, char **env)
{
    if (!*env)
        return (false);
    if (argc > 2) {
        my_putstr("./my_rpg:  bad arguments.\n");
        my_putstr("retry with -h\n");
        return (false);
    }
    if (argc == 2) {
        if (!print_message_help(argv))
            return (false);
    }
    return (true);
}

int launch(int argc, char **argv, char **env)
{
    all_t all;
    int status = 1;

    if (!check_error(argc, argv, env))
        return (0);
    init_game(&all);
    start_game_rpg(&all, status);
    return (0);
}
