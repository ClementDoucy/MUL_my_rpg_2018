/*
** EPITECH PROJECT, 2019
** blood.c
** File description:
** blood particle
*/

#include <math.h>
#include <stdbool.h>
#include "particle.h"

static const int radius = 30;

sfVertexArray *create_blood_effect(void)
{
    sfVertexArray *god_effect = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(god_effect, sfPoints);
    return god_effect;
}

static float resolve_circle_eq(sfVector2f pos, int x, int r)
{
    static bool check = false;
    float sol = sqrt(pow(r, 2) - pow(x - pos.x, 2));

    if (check)
        sol = pos.y - sol;
    else
        sol = pos.y + sol;
    check = !check;
    return sol;
}

static void update_blood_effect(sfVertexArray *blood, sfVector2f pos, int r)
{
    sfVertex vertex[2 * r];
    int x = pos.x - r;

    sfVertexArray_clear(blood);
    for (int i = 0; i < 2 * r; i += 1, x += 1) {
        vertex[i].color = sfRed;
        vertex[i].position.x = x;
        vertex[i].position.y = resolve_circle_eq(pos, x, r);
        sfVertexArray_append(blood, vertex[i]);
    }
}

void draw_blood_effect(
    sfVertexArray *god_effect, sfVector2f pos,
    sfRenderWindow *win, bool *check)
{
    static int r = 0;
    static sfClock *c1 = NULL;

    if (!c1)
        c1 = sfClock_create();
    if (!r) {
        r = radius;
        sfClock_restart(c1);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(c1)) > 0.5) {
        r = 0;
        *check = false;
        return;
    }
    r++;
    update_blood_effect(god_effect, pos, r);
    sfRenderWindow_drawVertexArray(win, god_effect, NULL);
}
