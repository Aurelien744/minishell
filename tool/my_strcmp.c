/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Day06
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/struct.h"

int my_strcmp(char const *s1, char const *s2)
{
    if ((my_strlen(s1)) < my_strlen(s2))
        return (-1);
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
