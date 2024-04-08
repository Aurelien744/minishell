/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Day08
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int sepa(char letter, char separator)
{
    if (letter != separator)
        return (0);
    else
        return (1);
}

int countmyletter(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        size++;
    }
    return (size);
}

static char **end_tab(char **tab, int x, int y)
{
    tab[x][y] = '\0';
    x++;
    tab[x] = NULL;
    return (tab);
}

char **put_tab(char *str, char **tab, char sep)
{
    int x = 0;
    int y = 0;
    int j = 0;

    for (; sepa(str[j], sep) == 1 && str[j] != '\0'; j++);
    for (; str[j] != '\0'; j++) {
        if ((sepa(str[j], sep) == 1) && (sepa(str[j + 1], sep) == 1)) {
            continue;
        }
        if ((sepa(str[j], sep) == 1)) {
            tab[x][y] = '\0';
            x++;
            y = 0;
        } else {
            tab[x][y] = str[j];
            y++;
        }
    }
    tab = end_tab(tab, x, y);
    return tab;
}

char **my_str_to_word_array(char *str, char sep)
{
    char **tab = NULL;
    int nbw = 1;
    int s = 0;

    if (str[0] == '\0') {
        tab = malloc(sizeof(char *) *1);
        tab[0] = NULL;
        return (tab);
    }
    for (int i = 0; str[i] != '\0'; i++)
        if (i != 0 && (sepa(str[i], sep) == 0) && (sepa(str[i - 1], sep) == 1))
            nbw++;
    tab = malloc(sizeof(char *) * (nbw + 1));
    tab[nbw] = 0;
    s = countmyletter(str);
    for (int j = 0; j < nbw; j++)
        tab[j] = malloc(sizeof(char) *(s + 1));
    if (nbw != 0)
        tab = put_tab(str, tab, sep);
    return (tab);
}
