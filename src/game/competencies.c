/*
** EPITECH PROJECT, 2019
** competencies
** File description:
** init and draw the competencies panel
*/

#include "rpg.h"

void manage_competencies(game_t *game, player_t *player)
{
    static sfClock *clock = NULL;
    sfVector2f pos = {player->pos.x - 600, player->pos.y - 300};

    if (!clock)
        clock = sfClock_create();
    sfSprite_setPosition(game->competencies, pos);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.2 &&
        sfKeyboard_isKeyPressed(sfKeyC)) {
        if (game->is_compet)
            game->is_compet = false;
        else
            game->is_compet = true;
        sfClock_restart(clock);
    }
    if (game->is_compet)
        sfRenderWindow_drawSprite(game->window, game->competencies, NULL);
}

void init_competencies(game_t *game)
{
    sfTexture *text = sfTexture_createFromFile("assets/GAME/competencies.jpg",
        NULL);

    game->competencies = sfSprite_create();
    sfSprite_setTexture(game->competencies, text, sfFalse);
    sfSprite_setPosition(game->competencies, (sfVector2f) {0, 0});
    sfSprite_setTextureRect(game->competencies, (sfIntRect) {0, 0, 1195, 668});
    game->is_compet = false;
}