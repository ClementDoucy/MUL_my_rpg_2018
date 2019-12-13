/*
** EPITECH PROJECT, 2018
** manage_mouse_click_settings.c
** File description:
** manage mouse click for settings game
*/

#include "rpg.h"

void manage_mouse_click_settings_four(sfMouseButtonEvent event, menu_t *menu,
                                    int *key)
{
    if (event.x <= 1757 && event.x >= 1645 && event.y <= 813 &&
        event.y >= 700) {
        sfText_setString(menu->text[9].text,
        "Select other touch for dash");
        *key = KEY_DASH;
    }
}

void manage_mouse_click_settings_three(sfMouseButtonEvent event, menu_t *menu,
                                    int *key)
{
    if (event.x <= 1633 && event.x >= 1523 && event.y <= 939 &&
        event.y >= 825) {
        sfText_setString(menu->text[9].text,
        "Select other touch for move down");
        *key = KEY_MOVE_DOWN;
    }
    if (event.x <= 1757 && event.x >= 1645 && event.y <= 546 &&
        event.y >= 441) {
        sfText_setString(menu->text[9].text,
        "Select other touch for competencies");
        *key = KEY_COMPETENCIES;
    }
    if (event.x <= 1757 && event.x >= 1645 && event.y <= 679 &&
        event.y >= 567) {
        sfText_setString(menu->text[9].text,
        "Select other touch for dialogue");
        *key = KEY_DIALOGUE;
    }
    manage_mouse_click_settings_four(event, menu, key);
}

void manage_mouse_click_settings_two(sfMouseButtonEvent event, menu_t *menu,
                                    int *key)
{
    if (event.x <= 1231 && event.x >= 1119 && event.y <= 939 &&
        event.y >= 825) {
        sfText_setString(menu->text[9].text,
        "Select other touch for move left");
        *key = KEY_MOVE_LEFT;
    }
    if (event.x <= 1363 && event.x >= 1256 && event.y <= 939 &&
        event.y >= 825) {
        sfText_setString(menu->text[9].text,
        "Select other touch for move up");
        *key = KEY_MOVE_UP;
    }
    if (event.x <= 1498 && event.x >= 1388 && event.y <= 939 &&
        event.y >= 825) {
        sfText_setString(menu->text[9].text,
        "Select other touch for move right");
        *key = KEY_MOVE_RIGHT;
    }
    manage_mouse_click_settings_three(event, menu, key);
}

void manage_mouse_click_settings(sfMouseButtonEvent event, menu_t *menu,
                                int *key)
{
    if (event.x <= 1119 && event.x >= 1023 && event.y <= 546 &&
        event.y >= 441) {
        sfText_setString(menu->text[9].text,
        "Select other touch for attack sword");
        *key = KEY_SWORD;
    }
    if (event.x <= 1119 && event.x >= 1023 && event.y <= 679 &&
        event.y >= 567) {
        sfText_setString(menu->text[9].text,
        "Select other touch for attack magic");
        *key = KEY_MAGIC;
    }
    if (event.x <= 1119 && event.x >= 1023 && event.y <= 813 &&
        event.y >= 700) {
        sfText_setString(menu->text[9].text,
        "Select other touch for inventory");
        *key = KEY_INVENTORY;
    }
    manage_mouse_click_settings_two(event, menu, key);
}
