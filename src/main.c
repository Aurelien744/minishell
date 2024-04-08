/*
** EPITECH PROJECT, 2024
** main
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/struct.h"

int main(int ac, char **av, char **env)
{
    int caca = 0;
    mini_t *mini = malloc(sizeof(mini_t));

    mini->path = NULL;
    mini->full_cmd = NULL;
    mini->oldpwd = NULL;
    mini->nooldpwd = malloc(sizeof(char) * 256);
    mini->nooldpwd[0] = '\0';
    if (ac != 1)
        return (84);
    my_list(mini, env);
    caca = minishell(mini, env);
    return (caca);
}
