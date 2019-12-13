/*
** EPITECH PROJECT, 2018
** HEADER MENU MY RPG
** File description:
** menu.h
*/

#ifndef _MENU_H_
#define _MENU_H_

typedef struct game game_t;
/*
** STRUCTURE
*/

typedef struct sprite_menu {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f position_anim;
} sprite_menu_t;

typedef struct text_menu {
    sfText *text;
    sfFont *font;
    sfVector2f position;
    sfVector2f position_anim;
} text_menu_t;

typedef struct menu {
    sprite_menu_t sprite[16];
    text_menu_t text[12];
    sfClock *clock1;
    sfTime time1;
    sfEvent event;
    int status_menu;
} menu_t;
/*
** fichier.c
*/
void init_sprite_menu(menu_t *);
void create_background_menu(menu_t *);
void create_button_menu(menu_t *);
void create_button_settings(menu_t *);
void create_button_play(menu_t *);
void create_sprite_delete(menu_t *);
void create_text_play(menu_t *);
void create_text_title(menu_t *);
void create_text_menu(menu_t *);
void init_position_text_button(menu_t *);
void init_position_anim_button(menu_t *);
void init_position_event_menu(menu_t *, sfVector2f);

void change_status_button(int*, menu_t *, int);
void manage_mouse_click_settings(sfMouseButtonEvent, menu_t *, int *);
void manage_mouse_move_settings(sfMouseMoveEvent, menu_t *);
void display_how_to_play(menu_t *, game_t *, int *);
void destroy_menu(menu_t *);
#endif /* _MENU_H_ */
