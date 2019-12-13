/*
** EPITECH PROJECT, 2018
** PROFIL HEADER MY RPG
** File description:
** profil.h
*/

#ifndef _PROFIL_H_
#define _PROFIL_H_

typedef struct game game_t;
typedef struct player player_t;
typedef struct menu menu_t;
/*
** STRUCTURE
*/

typedef struct sprite_profil {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_anim;
} sprite_profil_t;

typedef struct text_profil {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f pos_anim;
} text_profil_t;

typedef struct profil {
    sprite_profil_t sprite[2];
    text_profil_t text[5];
    sfClock *clock;
    sfTime time;
    sfEvent event;
} profil_t;

/*
** fichier.c
*/
void init_profil(game_t *);

bool check_save (game_t *, char *, int *);
void check_file(player_t *, menu_t *);
bool stock_name_in_save(game_t *, player_t *);
void display_profil_name_player(profil_t *, game_t *, int *);
bool get_save_fonction(game_t *, player_t *, char *, int *);

#endif /* _PROFIL_H_ */
