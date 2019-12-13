/*
** EPITECH PROJECT, 2019
** object_collider
** File description:
** collide functions of objects
*/

#include "rpg.h"

bool is_on_surface(sfVector2f pos, object_t obj)
{
    sfVector2f pos_obj = sfSprite_getPosition(obj.sprite);
    pos_obj.x = pos_obj.x + obj.hit_rect.left;
    pos_obj.y = pos_obj.y + obj.hit_rect.top;
    int width = obj.hit_rect.width;
    int height = obj.hit_rect.height;

    if (pos.x >= pos_obj.x
        && pos.x <= pos_obj.x + width) {
        if (pos.y >= pos_obj.y
            && pos.y <= pos_obj.y + height)
            return true;
    }
    return false;
}

bool test_points(sfVector2f *coords, object_t obj, sfVector2f *co,
    sfVector2f *co2)
{
    for (int i = 0; i != 4; i++) {
        if (is_on_surface(coords[i], obj))
            return true;
    }
    if (is_on_surface(co[0], obj) || is_on_surface(co[1], obj)
        || is_on_surface (co[2], obj) || is_on_surface(co[3], obj) ||
        is_on_surface(co2[0], obj) || is_on_surface(co2[1], obj)
        || is_on_surface (co2[2], obj) || is_on_surface(co2[3], obj))
        return true;
    return false;
}

bool check_all_points(player_t player, sfVector2f *coords, object_t obj)
{
    sfVector2f co[4];
    sfVector2f co2[4];

    co[0] = (sfVector2f) {player.pos.x + player.rect.width / 3, player.pos.y};
    co[1] = (sfVector2f) {player.pos.x, player.rect.height / 3 + player.pos.y};
    co[2] = (sfVector2f) {player.pos.x + player.rect.width / 3,
        player.pos.y + player.rect.height};
    co[3] = (sfVector2f) {player.pos.x + player.rect.width,
        player.pos.y + player.rect.height / 3};
    co2[0] = (sfVector2f) {player.pos.x + (player.rect.width / 3) * 2,
        player.pos.y};
    co2[1] = (sfVector2f) {player.pos.x,
        (player.rect.height / 3) * 2 + player.pos.y};
    co2[2] = (sfVector2f) {player.pos.x + (player.rect.width / 3) * 2,
        player.pos.y + player.rect.height};
    co2[3] = (sfVector2f) {player.pos.x + player.rect.width,
        player.pos.y + (player.rect.height / 3) * 2};

    return (test_points(coords, obj, co, co2));
}

bool check_colliders(player_t player, object_t **obj, int *nbr,
    sfVector2f *coords)
{
    if (nbr[0] == TREE)
        for (int j = 0; j != ALLOC_TREE; j++)
            if (check_all_points(player, coords, obj[nbr[0]][j])) {
                nbr[1] = j;
                return true;
            }
    if (nbr[0] == HOUSE)
        for (int j = 0; j != ALLOC_HOUSE; j++)
            if (check_all_points(player, coords, obj[nbr[0]][j])) {
                nbr[1] = j;
                return true;
            }
    return false;
}

bool is_collide(player_t player, object_t **obj, int *nbr)
{
    sfVector2f coords[4];

    coords[0] = (sfVector2f) {player.pos.x, player.pos.y};
    coords[1] = (sfVector2f) {player.pos.x + player.rect.width, player.pos.y};
    coords[2] = (sfVector2f) {player.pos.x, player.pos.y + player.rect.height};
    coords[3] = (sfVector2f) {player.pos.x + player.rect.width,
        player.pos.y + player.rect.height};
    for (int i = 1; i != 3; i++) {
        nbr[0] = i;
        if (check_colliders(player, obj, nbr, coords))
            return true;
    }
    return false;
}
