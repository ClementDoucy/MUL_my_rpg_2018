/*
** EPITECH PROJECT, 2018
** PAUSE HEADER MY RPG
** File description:
** pause.h
*/

#ifndef _PAUSE_H_
#define _PAUSE_H_

typedef struct game game_t;
typedef struct mouse mouse_t;
/*
** STRUCTURE
*/

typedef struct sprite_pause {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_anim;
} sprite_pause_t;

typedef struct text_pause {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f pos_anim;
} text_pause_t;

typedef struct pause {
    sprite_pause_t sprite[5];
    text_pause_t text[5];
    sfEvent event;
    int status_pause;
} pause_t;

/*
** fichier.c
*/
void display_pause_game(game_t *, pause_t *, mouse_t *, int *);
void analyse_event_pause(game_t *, int *);

#endif /* _PAUSE_H_ */