/*
** EPITECH PROJECT, 2018
** MY BASIC FONCTION TWO
** File description:
** my_basic_fonction_two.c
*/

#include "rpg.h"

int len_nb (int nb)
{
    int i = 0;

    if (nb >= 0 && nb <= 9) {
        i = 1;
    } else {
        while (nb != 0) {
            nb = nb / 10;
            i = i + 1;
        }
    }
    i = i + 1;
    return (i);
}

char *my_getchar(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (len_nb(i) + 1));
    int result = 0;

    if (nb >= 0 && nb <= 9) {
        str[i] = nb + 48;
    } else {
        while (nb != 0) {
            result = nb % 10;
            str[i] = result + 48;
            nb = nb / 10;
            i = i + 1;
        }
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

int my_getnbr(char const *str)
{
    int integer = 0;
    int a = 1;
    int i = 0;

    if (str == NULL)
        return (0);
    while ((*str <= '0' || *str >= '9') && *str != 0) {
        str = str + 1;
        i = i + 1;
    }
    if (i > 0 && *(str - 1) == '-')
        a = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        integer = integer * 10;
        integer = integer + *str - 48;
        str = str + 1;
    }
    integer = integer * a;
    return (integer);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int size_str = len - 1;
    int i = 0;
    int temp = 0;
    int mid = size_str / 2;

    while (i <= mid) {
        temp = str[i];
        str[i] = str[size_str];
        str[size_str] = temp;
        i = i + 1;
        size_str = size_str - 1;
    }
    return (str);
}
