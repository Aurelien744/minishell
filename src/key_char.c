/*
** EPITECH PROJECT, 2024
** key_char.c
** File description:
** minishell2
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

int key_char(char *str, mini_t *mini)
{
    mini->pipe_nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|')
            mini->pipe_nb++;
    }
}
