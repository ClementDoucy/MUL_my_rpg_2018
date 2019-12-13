/*
** EPITECH PROJECT, 2019
** particle.h
** File description:
** header file for particle
*/

#pragma once

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Vertex.h>
#include <stdbool.h>

sfVertexArray *create_rain(void);
void draw_all_rains(sfVertexArray *, sfRenderWindow *);
sfVertexArray *create_blood_effect(void);
void draw_blood_effect(sfVertexArray *, sfVector2f, sfRenderWindow *, bool *);
