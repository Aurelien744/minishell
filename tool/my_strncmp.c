/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** Day06
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/struct.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n - 1; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}
