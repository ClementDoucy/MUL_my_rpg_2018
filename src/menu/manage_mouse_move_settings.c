/*
** EPITECH PROJECT, 2018
** manage_mouse_move_settings.c
** File description:
** manage mouse move for game settings
*/

#include "rpg.h"

void manage_mouse_move_settings_two(sfMouseMoveEvent event, menu_t *menu)
{
    if (event.x <= 1498 && event.x >= 1388 && event.y <= 939 &&
        event.y >= 825)
        sfText_setString(menu->text[9].text,
        "Key move right (right arrow for default)");
    if (event.x <= 1633 && event.x >= 1523 && event.y <= 939 &&
        event.y >= 825)
        sfText_setString(menu->text[9].text,
        "Key move down (down arrow for default)");
    if (event.x <= 1757 && event.x >= 1645 && event.y <= 546 &&
        event.y >= 441)
        sfText_setString(menu->text[9].text,
        "Key competencies (C for default)");
    if (event.x <= 1757 && event.x >= 1645 && event.y <= 679 &&
        event.y >= 567)
        sfText_setString(menu->text[9].text,
        "Key to dialogue (F for default)");
    if (event.x <= 1757 && event.x >= 1645 && event.y <= 813 &&
        event.y >= 700)
        sfText_setString(menu->text[9].text,
        "Key to dash (Shift for default)");
}

void manage_mouse_move_settings(sfMouseMoveEvent event, menu_t *menu)
{
    if (event.x <= 1119 && event.x >= 1023 && event.y <= 546 &&
        event.y >= 441)
        sfText_setString(menu->text[9].text,
        "Key attack Sword (space for default)");
    if (event.x <= 1119 && event.x >= 1023 && event.y <= 679 &&
        event.y >= 567)
        sfText_setString(menu->text[9].text,
        "Key attack magic (W for default)");
    if (event.x <= 1119 && event.x >= 1023 && event.y <= 813 &&
        event.y >= 700)
        sfText_setString(menu->text[9].text,
        "Key inventory (E for default)");
    if (event.x <= 1231 && event.x >= 1119 && event.y <= 939 &&
        event.y >= 825)
        sfText_setString(menu->text[9].text,
        "Key move left (left arrow for default)");
    if (event.x <= 1363 && event.x >= 1256 && event.y <= 939 &&
        event.y >= 825)
        sfText_setString(menu->text[9].text,
        "Key move up (up arrow for default)");
    manage_mouse_move_settings_two(event, menu);
}
