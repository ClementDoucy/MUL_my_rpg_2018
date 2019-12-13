/*
** EPITECH PROJECT, 2019
** particle.c
** File description:
** manage particle
*/

#include <string.h>
#include <stdlib.h>
#include "particle.h"

static const sfColor rain_color = {95, 158, 160, 200};
static const sfVector2f rain_pos = {3900, 200};

sfVertexArray *create_rain(void)
{
    sfVertexArray *rain = sfVertexArray_create();
    sfVertex vertex[2];

    sfVertexArray_setPrimitiveType(rain, sfLines);
    vertex[0].position = rain_pos;
    vertex[0].color = rain_color;
    vertex[1].position = (sfVector2f){rain_pos.x - 10, rain_pos.y + 50};
    vertex[1].color = rain_color;
    for (int i = 0; i < 48; i++) {
        sfVertexArray_append(rain, vertex[0]);
        sfVertexArray_append(rain, vertex[1]);
        vertex[0].position.x += 40;
        vertex[1].position.x += 40;
    }
    return rain;
}

void move_rain(sfVertexArray *rain)
{
    size_t size = sfVertexArray_getVertexCount(rain);
    sfVertex *vertex[size];

    for (size_t i = 0; i < size; i++) {
        vertex[i] = sfVertexArray_getVertex(rain, i);
        vertex[i]->position.y++;
        if (vertex[i]->position.y >= rain_pos.y + 1080 && i % 2) {
            vertex[i]->position.y = rain_pos.y + 60;
            vertex[i - 1]->position.y = rain_pos.y + 10;
        }
    }
    sfVertexArray_clear(rain);
    for (size_t i = 0; i < size; i++)
        sfVertexArray_append(rain, (*vertex)[i]);
}

void add_wave_rain(sfVertexArray *rain)
{
    sfVertex vertex[2];

    vertex[0].position = rain_pos;
    vertex[0].color = rain_color;
    vertex[1].position = (sfVector2f){rain_pos.x - 10, rain_pos.y + 50};
    vertex[1].color = rain_color;
    for (int i = 0; i < 48; i++) {
        sfVertexArray_append(rain, vertex[0]);
        sfVertexArray_append(rain, vertex[1]);
        vertex[0].position.x += 40;
        vertex[1].position.x += 40;
    }
}

void draw_all_rains(sfVertexArray *rain, sfRenderWindow *win)
{
    static sfClock *c1 = NULL;
    static sfClock *c2 = NULL;
    static int i = 0;

    if (!c1) {
        c1 = sfClock_create();
        c2 = sfClock_create();
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(c1)) > 0.1) {
        move_rain(rain);
        sfClock_restart(c1);
    }
    if (i < 13 && sfTime_asSeconds(sfClock_getElapsedTime(c2)) > 0.4) {
        add_wave_rain(rain);
        i++;
        sfClock_restart(c2);
    }
    sfRenderWindow_drawVertexArray(win, rain, NULL);
}
