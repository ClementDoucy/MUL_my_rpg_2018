/*
** EPITECH PROJECT, 2018
** START GAME MY RPG
** File description:
** start_game.c
*/

#include "particle.h"
#include "rpg.h"

void analyse_events_game(game_t *game, int *status)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            *status = 8;
        if (sfKeyboard_isKeyPressed(sfKeyQ) == 1)
            *status = 8;
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
                game->status_pause = 1;
        if (game->event.type == sfEvtKeyReleased &&
            game->event.key.code == sfKeyI)
            *status = (*status == 2 ? 7 : 2);
    }
}

void display_enemy(game_t *game, object_t *draw_obj, int i, int j)
{
    float enemy_y;

    if (j == SCORPIO) {
        for (int k = 0; k != ALLOC_SCORPIO; k++) {
            enemy_y = game->enemy[j][k].pos.y - 60;
            if (enemy_y > draw_obj[i].pos.y && (&draw_obj[i+1] == NULL ||
                enemy_y < draw_obj[i+1].pos.y))
                sfRenderWindow_drawSprite(game->window,
                    game->enemy[j][k].sprite, NULL);
        }
    }
    if (j == BOSS && (game->quest.is_quest[1] || game->quest.is_quest[3])) {
        for (int k = 0; k != ALLOC_BOSS; k++) {
            enemy_y = game->enemy[j][k].pos.y - 60;
            if (enemy_y > draw_obj[i].pos.y && (&draw_obj[i+1] == NULL ||
                enemy_y < draw_obj[i+1].pos.y) && game->enemy[j][k].is_alive)
                sfRenderWindow_drawSprite(game->window,
                    game->enemy[j][k].sprite, NULL);
        }
    }
}

void draw_objects_in_order(player_t *player, object_t *draw_obj, game_t *game)
{
    float player_y = player->pos.y - 60;

    sfRenderWindow_drawSprite(game->window, game->obj[BACK][1].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->obj[BACK][0].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    for (int i = 1; i != ALLOC_TREE + ALLOC_HOUSE; i++) {
        sfRenderWindow_drawSprite(game->window, draw_obj[i].sprite, NULL);
        if (player_y > draw_obj[i].pos.y && (&draw_obj[i+1] == NULL ||
            player_y < draw_obj[i+1].pos.y))
            sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
        for (int j = 0; j != ALLOC_ENEMY; j++)
            display_enemy(game, draw_obj, i, j);
    }
    player->text_pos.x = player->pos.x + 350;
    player->text_pos.y = player->pos.y - 450;
    sfText_setPosition(player->text, player->text_pos);
}

void manage_exp(game_t *game, player_t *player)
{
    sfVector2f pos_bar = {player->pos.x + 673, player->pos.y - 387};
    int percent = (100 * player->exp) / player->max_exp;
    int width = player->exp_bar.total_width * percent / 100;
    sfIntRect rect = {0, 0, width, 16};
    char *str = my_strcat("LVL ", int_to_str(player->lvl));

    if (player->exp >= player->max_exp) {
        player->lvl = player->lvl + 1;
        player->exp = player->exp - player->max_exp;
        player->max_exp = player->max_exp * 2;
    }
    sfText_setString(player->exp_bar.txt_lvl, str);
    sfText_setPosition(player->exp_bar.txt_lvl,
        (sfVector2f) {player->pos.x + 680, player->pos.y - 500});
    sfSprite_setTextureRect(player->exp_bar.bar, rect);
    sfSprite_setPosition(player->exp_bar.bar, pos_bar);
    sfRenderWindow_drawText(game->window, player->exp_bar.txt_lvl, NULL);
    sfRenderWindow_drawSprite(game->window, player->exp_bar.bar, NULL);
    free(str);
}

void game_function(game_t *game, mouse_t *mouse, int *status)
{
    if (game->status_pause == 0) {
        draw_objects_in_order(&game->player, game->draw_obj, game);
        sfView_setCenter(game->view, game->player.pos);
        sfRenderWindow_setView(game->window, game->view);
        character_manager(&game->player, game->obj);
        manage_scorpio(game, game->enemy[SCORPIO], &game->player);
        manage_boss(game, game->enemy[BOSS], &game->player);
        manage_pnj(game);
        draw_items_in_world(game->inv.items, game->window);
        manage_competencies(game, &game->player);
    } else
        display_pause_game(game, &game->pause_game, mouse, status);
    sfView_setCenter(game->view, game->player.pos);
    sfRenderWindow_drawText(game->window, game->player.text, NULL);
    loot_items(game->inv.items, game->player.pos);
    analyse_events_game(game, status);
    manage_status_bar(game);
    manage_exp(game, &game->player);
    manage_stat_panel(
        game->window, game->player.stat, game->player.pos);
    draw_all_rains(game->rain, game->window);
}
