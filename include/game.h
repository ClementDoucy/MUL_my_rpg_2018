/*
** EPITECH PROJECT, 2018
** HEADER GAME MY RPG
** File description:
** game.h
*/

#ifndef _GAME_H_
#define _GAME_H_
/*
** STRUCTURE
*/

#include "rpg.h"
#include "menu.h"
#include "pause.h"
#include "profil.h"
#include "gui.h"

typedef struct all all_t;
typedef struct pause pause_t;
typedef struct profil profil_t;
typedef struct inventory inv_t;
typedef struct status_bar status_bar_t;
typedef struct player_stat player_stat_t;

typedef struct option {
    float main_song;
    float second_song;
} option_t;

typedef struct timer
{
    sfTime time;
    sfClock *clock;
    float seconds;
} Timer;

struct player_stat
{
    sfVector2i speed;
    unsigned int level;
    unsigned int max_hp;
    int heal_point;
    unsigned int attack_damage;
    unsigned int armor_point;
    float percent_armor;
    unsigned int magic_power;
    unsigned int xp;
    sfSprite *panel;
    sfTexture *texture;
    sfText *text[5];
};

typedef struct exp_bar {
    sfSprite *bar;
    sfIntRect rect_bar;
    float total_width;
    sfText *txt_lvl;
} exp_bar_t;

typedef struct player {
    player_stat_t stat;
    exp_bar_t exp_bar;
    char *name;
    sfText *text;
    sfFont *font;
    sfVector2f text_pos;
    int width;
    int length;
    Timer anim_time;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int lvl;
    int exp;
    int max_exp;
    bool is_reverse;
    bool is_move;
    bool is_attack;
    bool is_dash;
    bool is_punch;
    bool is_alive;
    sfVertexArray *blood;
} player_t;

typedef struct pnj {
    sfSprite *sprite;
    sfSprite *icon;
    sfSprite *box;
    sfSprite *pic;
    sfText *txt[4];
    sfVector2f pos;
    bool message_is_display;
    sfTexture *text;
    sfIntRect rect;
    sfIntRect icon_rect;
    char *message;
} pnj_t;

typedef struct enemy_life {
    sfSprite *black;
    sfIntRect rect_black;
    float total_width;
    sfSprite *red;
    sfIntRect rect_red;
} enemy_life_t;

typedef struct boss_data {
    Timer dash_time;
    Timer attack_time;
} boss_data_t;

typedef struct enemy {
    sfSprite *sprite;
    sfIntRect rect;
    Timer anim_time;
    Timer respawn_time;
    Timer can_hit;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f spawn_pos;
    boss_data_t data;
    bool can_be_hit;
    bool is_alive;
    bool is_walk;
    bool is_reverse;
    bool is_attack;
    int life;
    int max_life;
    int damage;
    enemy_life_t life_bar;
} enemy_t;

typedef struct text {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f pos_anim;
} text_t;

typedef struct object {
    int width;
    int length;
    sfSprite *sprite;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
    sfIntRect hit_rect;
    int is_physic;
} object_t;

typedef struct quest {
    bool is_quest[4];
    int count;
    int goal;
    int quest_nbr;
    int nbr_of_dialog;
    sfText *txt;
} quest_t;

typedef struct key {
    sfKeyCode key_sword;
    sfKeyCode key_magic;
    sfKeyCode key_inventory;
    sfKeyCode key_move_left;
    sfKeyCode key_move_up;
    sfKeyCode key_move_right;
    sfKeyCode key_move_down;
    sfKeyCode key_competencies;
    sfKeyCode key_dialogue;
    sfKeyCode key_pause;
} key_game_t;

typedef struct game {
    sfRenderWindow *window;
    sfView *view;
    quest_t quest;
    sfSprite *competencies;
    bool is_compet;
    sfVideoMode video_mode;
    player_t player;
    enemy_t **enemy;
    inv_t inv;
    object_t **obj;
    object_t *draw_obj;
    sfMusic *music[5];
    pause_t pause_game;
    profil_t profil_game;
    option_t option;
    key_game_t key;
    int status_pause;
    int status_settings;
    char *filename;
    int status_profil;
    sfEvent event;
    sfTexture *screenshot;
    int fd;
    status_bar_t status_bar;
    pnj_t all_pnj[2];
    sfVertexArray *rain;
} game_t;

typedef struct mouse {
    sfTexture *texture_main_mouse;
    sfSprite *main_mouse;
    sfVector2f position_mouse;
} mouse_t;

enum OBJS {
    BACK = 0,
    TREE = 1,
    HOUSE = 2,
    RIVER = 3,
    SIGN = 4
};

enum MUSIC {
    MENU_MUSIC = 0,
    MAIN_MUSIC = 1,
    KILL_SOUND = 2,
    HIT_SCORPIO = 3,
    HIT_NINJA = 4
};

enum ALLOC_OBJ {
    ALLOC_OBJECT = 6,
    ALLOC_BACK = 2,
    ALLOC_TREE = 40,
    ALLOC_HOUSE = 17,
    ALLOC_MAX = 40
};

enum ENEMY {
    SCORPIO = 0,
    BOSS = 1
};

enum ALLOC_ENEMY {
    ALLOC_ENEMY = 2,
    ALLOC_SCORPIO = 2,
    ALLOC_BOSS = 3
};

enum DAMAGE_ENEMY {
    DAMAGE_SCORPIO = 10,
    DAMAGE_BOSS = 30
};

enum KEY_GAME {
    KEY_MOVE_UP = 1,
    KEY_MOVE_DOWN = 2,
    KEY_MOVE_RIGHT = 3,
    KEY_MOVE_LEFT = 4,
    KEY_SWORD = 5,
    KEY_MAGIC = 6,
    KEY_DASH = 7,
    KEY_COMPETENCIES = 8,
    KEY_DIALOGUE = 9,
    KEY_INVENTORY = 10
};

/*
** fichier.c
*/
void init_game(all_t *);
void init_window(game_t *);
void create_background_game(game_t *);
void display_profil_game(menu_t *, mouse_t *, game_t *, int *);
void create_sprite_tree(game_t *);
void create_mouse(mouse_t *);
object_t init_object(char *, sfVector2f, sfIntRect);
void init_tree(game_t *);
void init_house(object_t **obj);
void init_river(game_t *);
void init_sign(game_t *);
void init_pause(game_t *);
player_t init_player(char *, sfVector2f, sfIntRect);
void init_player2(player_t *player);
void init_objects(game_t *);
enemy_t **init_enemy(void);
void main_game(all_t *, int *);
void display_game_menu(menu_t *, mouse_t *, game_t *, int *);
void manage_mouse_move_main(sfMouseMoveEvent, mouse_t *);
void display_settings_game(menu_t *, mouse_t *, game_t *, int *);
void click_button_settings(sfMouseMoveEvent, menu_t *, game_t *);
void game_function(game_t *, mouse_t *, int *);
void destroy_game(all_t *);
void character_manager(player_t *charac, object_t **obj);
void draw_objects_in_order(player_t *, object_t *, game_t *);
object_t *sort_objects(object_t *);
void init_hit_rect_object(object_t **obj);
bool is_collide(player_t player, object_t **obj, int *nbr);
void replace_player(player_t *charac);
void replace_player_object(player_t *charac, object_t **obj);
void manage_scorpio(game_t *game, enemy_t *scorpio, player_t *player);
void anim_scorpio(enemy_t *scorpio, player_t *player, game_t *game);
bool is_in_range(enemy_t *enemy, player_t *player, float range);
bool watch_in_direction(player_t *player, enemy_t *enemy);
void rev_enemy(enemy_t *enemy, bool verif);
void run_timer_respawn(enemy_t *boss);
void target_player(player_t *target, enemy_t *enemy, float speed);
void manage_boss(game_t *game, enemy_t *boss, player_t *player);
void anim_boss(enemy_t *boss, player_t *player, game_t *game);
void follow_player(enemy_t *boss, player_t *player);
void hit_boss(enemy_t *boss, player_t *player, game_t *game);
void hit_player(enemy_t *, int, player_t *, sfRenderWindow *);
player_stat_t init_player_stat(void);
void init_boss_data(enemy_t *enemy);
enemy_t *init_boss(enemy_t *enemy);
void init_boss_pos_and_life(enemy_t *enemy);
void dash_animation(player_t *player);
void attack_animation(player_t *player);
void punch_animation(player_t *player);
void walk_animation(player_t *player);
void rev_sprite(player_t *player, bool verif);
void init_competencies(game_t *game);
void manage_competencies(game_t *game, player_t *player);
void manage_pnj(game_t *game);
sfText *create_new_text_page(char *message);
void active_next_quest(quest_t *quest, pnj_t *pnj, player_t *player,
    game_t *game);
quest_t init_quest(void);
void check_move(player_t *charac);
void move_and_dash(player_t *charac, object_t **obj);
void draw_pnj(sfRenderWindow *window, game_t *game);
void init_pnj(game_t *game);
void boss_hurt(game_t *game, enemy_t *boss, player_t *player, int damage);
void scorpio_hurt(game_t *game, enemy_t *scorpio, player_t *player, int damage);
void stop_music_and_close_game(game_t *game);
void init_stat_panel(player_stat_t *, sfFont *);
void manage_stat_panel(sfRenderWindow *, player_stat_t, sfVector2f);
void init_hit_rect_object(object_t **);
bool is_collide(player_t, object_t **, int *);
void replace_player(player_t *);
void replace_player_object(player_t *, object_t **);
void manage_scorpio(game_t *, enemy_t *, player_t *);
bool is_in_range(enemy_t *, player_t *, float);
bool watch_in_direction(player_t *, enemy_t *);
void rev_enemy(enemy_t *, bool);
void run_timer_respawn(enemy_t *);
void target_player(player_t *, enemy_t *, float);
void manage_boss(game_t *, enemy_t *, player_t *);
void follow_player(enemy_t *, player_t *);
void get_save_fonction_in_game(game_t *, player_t *);

#endif /* _GAME_H_ */
