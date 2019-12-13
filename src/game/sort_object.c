/*
** EPITECH PROJECT, 2018
** sort_object.c
** File description:
** function srot_obj
*/

#include "rpg.h"

object_t *sort_objects(object_t *obj)
{
    object_t save;

    for (int i = 0; i < ALLOC_TREE + ALLOC_HOUSE; i++)
        for (int k = i + 1; k < ALLOC_TREE + ALLOC_HOUSE; k++)
            if (obj[i].pos.y > obj[k].pos.y) {
                save = obj[i];
                obj[i] = obj[k];
                obj[k] = save;
            }
    return obj;
}
