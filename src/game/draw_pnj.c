/*
** EPITECH PROJECT, 2019
** draw_pnj
** File description:
** draw pnj functions
*/

#include "rpg.h"

void set_pos_and_draw_pnj(sfRenderWindow *window, game_t *game, int *i)
{
    sfRenderWindow_drawSprite(window, game->all_pnj[0].icon, NULL);
    sfSprite_setPosition(game->all_pnj[0].box,
        (sfVector2f) {game->player.pos.x - 400, game->player.pos.y + 350});
    sfText_setPosition(game->all_pnj[0].txt[*i],
        (sfVector2f) {game->player.pos.x - 380, game->player.pos.y + 360});
    sfSprite_setPosition(game->all_pnj[0].pic,
        (sfVector2f) {game->player.pos.x - 540, game->player.pos.y + 350});
    sfRenderWindow_drawSprite(window, game->all_pnj[0].box, NULL);
    sfRenderWindow_drawSprite(window, game->all_pnj[0].pic, NULL);
    sfRenderWindow_drawText(game->window, game->all_pnj[0].txt[*i], NULL);
}


static void render_icon(sfRenderWindow *window, game_t *game, int *i)
{
    static bool save = false;
    static bool is_presse = false;

    if (game->all_pnj->message_is_display) {
        save = is_presse;
        is_presse = (sfKeyboard_isKeyPressed(sfKeyE)) ? true : false;
        if (save == false && is_presse == true)
            *i += 1;
        if (*i > game->quest.nbr_of_dialog) {
            if (!game->quest.is_quest[game->quest.quest_nbr]) {
                if (game->quest.quest_nbr != 0)
                    game->quest.is_quest[game->quest.quest_nbr - 1] = false;
                game->quest.is_quest[game->quest.quest_nbr] = true;
                game->quest.count = 0;
            }
            game->all_pnj->message_is_display = false;
            return;
        }
        set_pos_and_draw_pnj(window, game, i);
    }
}

static bool get_state_icon_rect(game_t * game)
{
    static bool state_icon_rect = false;

    if (game->all_pnj->pos.x + 100 >= game->player.pos.x &&
        game->all_pnj->pos.x - 150 <= game->player.pos.x &&
        game->all_pnj->pos.y + 200 >= game->player.pos.y &&
        game->all_pnj->pos.y - 100 <= game->player.pos.y) {
            if (sfKeyboard_isKeyPressed(sfKeyF))
                state_icon_rect = true;
    } else
        state_icon_rect = false;
    return state_icon_rect;
}

void anime_pnj(game_t *game)
{
    if (game->all_pnj[0].rect.left >= 166)
        game->all_pnj[0].rect.left = 0;
    else
        game->all_pnj[0].rect.left += 83;
    if (game->all_pnj[0].icon_rect.left >= 1182)
        game->all_pnj[0].icon_rect.left = 0;
    else
        game->all_pnj[0].icon_rect.left += 160;
    sfSprite_setTextureRect(game->all_pnj[0].icon, game->all_pnj[0].icon_rect);
    sfSprite_setTextureRect(game->all_pnj[0].sprite, game->all_pnj[0].rect);
}

void draw_pnj(sfRenderWindow *window, game_t *game)
{
    static sfClock *clock = NULL;
    static int i = 0;

    if (!clock)
        clock = sfClock_create();
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.15) {
        anime_pnj(game);
        sfClock_restart(clock);
    }
    game->all_pnj->message_is_display = get_state_icon_rect(game);
    if (game->all_pnj->message_is_display == false)
        i = 0;
    render_icon(window, game, &i);
    sfRenderWindow_drawSprite(window, game->all_pnj[0].sprite, NULL);
}