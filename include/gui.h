/*
** EPITECH PROJECT, 2019
** gui.h
** File description:
** game user interface
*/

#pragma once

typedef struct inventory inv_t;
typedef struct mouse mouse_t;
typedef struct game game_t;
typedef struct items items_t;
typedef struct stuff_slot stuff_slot_t;
typedef struct items_init items_init_t;
typedef enum items_type items_type_t;
typedef enum items_id items_id_t;
typedef enum items_effect items_effect_t;
typedef struct status_bar status_bar_t;
typedef struct player_stat player_stat_t;

#define NB_ITEMS 9
#define INV_WIDTH 6
#define INV_HEIGHT 4

enum items_type {
    SWORD,
    SHIELD,
    HELMET,
    CHESTPLATE,
    BELT,
    BOOTS,
    CONS
};

enum items_id {
    HEAL_POT,
    SWORD_1,
    SHIELD_1,
    HELMET_1,
    CHESTPLATE_1,
    BELT_1,
    BOOTS_1
};

enum items_effect {
    HEAL,
    DMG,
    PARADE,
    ARMOR,
    POWER,
    SPEED,
};

struct inventory {
    sfSprite *sprite;
    sfTexture *text;
    items_t *items;
    sfFont *font;
    sfText *infos[3];
};

struct items {
    char *(*name)(items_id_t);
    int (*effect_value)(items_id_t);
    char *(*effect_val_as_str)(items_id_t);
    char *(*effect_name)(items_effect_t);
    sfSprite *sprite;
    sfTexture *text;
    bool in_inv;
    sfVector2f pos;
    bool in_stuff;
    items_type_t type;
    items_id_t id;
    items_effect_t effect;
    bool exist;
    bool update;
};

struct items_init {
    sfIntRect rect;
    items_type_t type;
    bool in_inv;
    items_effect_t effect;
};

struct status_bar {
    sfSprite *bar;
    sfTexture *bar_tex;
    sfSprite *bloc[5];
    sfTexture *bloc_tex;
    sfText *nb_hp;
};

void draw_items_in_world(items_t *, sfRenderWindow *);
void manage_inventory(game_t *, mouse_t *, int *);
inv_t init_inventory(void);
void loot_items(items_t *, sfVector2f);
size_t count_inv_items(items_t *);
void manage_items_in_inv(game_t *, mouse_t *);
void get_inv_items_rect(sfFloatRect *, items_t *);
bool catch_double_click(sfEvent);
void draw_stuff_items(sfRenderWindow *, items_t *, sfVector2f);
void manage_stuff(sfFloatRect *, game_t *, mouse_t *, size_t);
char *get_items_name(items_id_t);
int get_value_effect(items_id_t);
char *int_to_str(int);
char *get_effect_name(items_effect_t);
char *get_val_effect_as_str(items_id_t);
void draw_items_stat(items_t *, inv_t, int, sfRenderWindow *);
void manage_status_bar(game_t *);
status_bar_t init_status_bar(sfFont *);
char *my_strcat(char *, char *);
void check_slot(items_t **, items_type_t, int);
void update_stat_with_stuff(items_t *, player_stat_t *);
