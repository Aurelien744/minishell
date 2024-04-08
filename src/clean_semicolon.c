/*
** EPITECH PROJECT, 2024
** clean_semicolon
** File description:
** minishell2
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

char *sapce_semicolon(int *next, char *clean_str, int *a)
{
    if (*next == 1) {
        clean_str[*a] = ' ';
        *a = *a + 1;
        *next = 0;
    }
    return (clean_str);
}

char *clean_semicolon(char *dirty)
{
    int a = 0;
    int next = 0;
    int x;
    char *clear = malloc(sizeof(char) * my_strlen(dirty) + 1);

    for (x = 0; (dirty[x] == ' ' || dirty[x] == '\t'); x++);
    for (int i = x; dirty[i] != '\0'; i++) {
        if ((dirty[i] == ' ' || dirty[i] == '\t'))
            next = 1;
        if (dirty[i] != ' ' && dirty[i] != '\t') {
            sapce_semicolon(&next, clear, &a);
            clear[a] = dirty[i];
            a++;
        }
    }
    clear[a] = '\0';
    return (clear);
}
