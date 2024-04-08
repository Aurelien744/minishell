/*
** EPITECH PROJECT, 2024
** builtins
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/struct.h"

void unset_all(mini_t *mini)
{
    if (error_unset(mini) == 1)
        return;
    for (int i = 1; mini->tab_clean[i] != NULL; i++) {
        my_unsetenv(mini, i);
    }
}

int my_builtins(mini_t *mini, char **env)
{
    int rtn = 0;

    if (my_strcmp(mini->tab_clean[0], "env") == 0) {
        display_env(mini, mini->linked);
        return (0);
    }
    if (my_strcmp(mini->tab_clean[0], "setenv") == 0) {
        my_setenv(mini);
        return (0);
    }
    if (my_strcmp(mini->tab_clean[0], "unsetenv") == 0) {
        unset_all(mini);
        return (0);
    }
    if (my_strcmp(mini->tab_clean[0], "cd") == 0) {
        rtn = my_cd(mini);
        return (rtn);
    }
    return (shell_cmd(mini, env));
}
