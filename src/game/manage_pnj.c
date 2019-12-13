/*
** EPITECH PROJECT, 2018
** manage_pnj.c
** File description:
** file for move pnj and manage mouvement
*/

#include "rpg.h"

void change_quest_one(quest_t *quest, pnj_t *pnj, player_t *player)
{
    char *t_1 = "Now your warm up is over.\nWe can begin serious things ";
    char *t_2 = "You have to fight the terrible Jojo.\nYou will recognize him";

    t_1 = my_strcat(t_1, player->name);
    t_2 = my_strcat(t_2, " with his mask and his unstoppable ninja attacks!");
    if (quest->quest_nbr == 0) {
        quest->nbr_of_dialog = 3;
        pnj->txt[0] = create_new_text_page("Nice job! You succeed!");
        pnj->txt[1] = create_new_text_page(t_1);
        pnj->txt[2] = create_new_text_page(t_2);
        pnj->txt[3] = create_new_text_page("Good luck hero chosen by fate!");
    }
}

void change_quest(quest_t *quest, pnj_t *pnj, player_t *player)
{
    char *t_1 = "But Jojo is back from the dead and bring 2 friends";

    change_quest_one(quest, pnj, player);
    if (quest->quest_nbr == 1) {
        quest->nbr_of_dialog = 1;
        pnj->txt[0] = create_new_text_page("Nice job! You succeed!");
        pnj->txt[1] = create_new_text_page(
            "Now that you beat Jojo\nCan you kill 25 scorpions?");
    }
    if (quest->quest_nbr == 2) {
        quest->nbr_of_dialog = 1;
        t_1 = my_strcat(t_1, "to revenge.\nGo face them.");
        pnj->txt[0] = create_new_text_page(
            "Nice job! You beat all the scorpio!");
        pnj->txt[1] = create_new_text_page(t_1);
    }
    if (quest->quest_nbr >= 3) {
        quest->nbr_of_dialog = 0;
        pnj->txt[0] = create_new_text_page(
            "Nice job! You beat them all! You are the new chief of the place!");
    }
}

void active_next_quest(quest_t *quest, pnj_t *pnj, player_t *player,
    game_t *game)
{
    if (quest->count == quest->goal && quest->is_quest[quest->quest_nbr]) {
        change_quest(quest, pnj, player);
        quest->quest_nbr = quest->quest_nbr + 1;
        if (quest->quest_nbr == 1)
            game->enemy[BOSS][0].is_alive = true;
        if (quest->quest_nbr == 3) {
            game->enemy[BOSS][0].life = 300;
            sfSprite_setPosition(game->enemy[BOSS][0].sprite,
                (sfVector2f) {3000, 2000});
            game->enemy[BOSS][0].is_alive = true;
            game->enemy[BOSS][1].is_alive = true;
            game->enemy[BOSS][2].is_alive = true;
        }
    }
}

void quest_view(game_t *game, quest_t *quest)
{
    char *monster;
    char *str = my_strcat(" / ", int_to_str(quest->goal));
    sfVector2f pos = {game->player.pos.x + 500, game->player.pos.y - 350};

    if (quest->is_quest[0] || quest->is_quest[2])
        monster = my_strcat("Scorpio :  ", int_to_str(quest->count));
    else
        monster = my_strcat("Ninja :  ", int_to_str(quest->count));
    str = my_strcat(monster, str);
    sfText_setString(quest->txt, str);
    sfText_setPosition(quest->txt, pos);
    sfRenderWindow_drawText(game->window, quest->txt, NULL);
}

void manage_pnj(game_t *game)
{
    draw_pnj(game->window, game);
    if (game->quest.is_quest[0])
        game->quest.goal = 8;
    if (game->quest.is_quest[1])
        game->quest.goal = 1;
    if (game->quest.is_quest[2])
        game->quest.goal = 25;
    if (game->quest.is_quest[3])
        game->quest.goal = 3;
    if (game->quest.is_quest[0] || game->quest.is_quest[1]
        || game->quest.is_quest[2] || game->quest.is_quest[3])
        quest_view(game, &game->quest);
    active_next_quest(&game->quest, game->all_pnj, &game->player, game);
}