
/*
** EPITECH PROJECT, 2018
** MY RPG HEADER
** File description:
** rpg.h
*/

#ifndef _MY_RPG_
#define _MY_RPG_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include "game.h"
#include "menu.h"
#include "gui.h"
/*
** STRUCTURE
*/
typedef struct all {
    menu_t menu;
    mouse_t mouse;
    option_t option;
    game_t game;
} all_t;

int launch(int, char **, char **);

void my_putstr(char const *);
void my_putchar(char);
int my_strlen(char const *);
char *my_getchar(int);
int my_getnbr(char const *);
char *my_revstr(char *);
char *strcopy(char *);
char *my_strcat(char *, char *);
void my_put_error(char *);
bool is_display_set(const char **);
bool are_eq_str(const char *, const char *);

#endif /* _MY_RPG */
