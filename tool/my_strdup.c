/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Day08
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *alloc_str = malloc(sizeof(char) * (size + 1));
    int idx = 0;

    if (alloc_str == NULL)
        return (NULL);
    for (; idx < size; idx++)
        alloc_str[idx] = src[idx];
    alloc_str[idx] = '\0';
    return (alloc_str);
}
