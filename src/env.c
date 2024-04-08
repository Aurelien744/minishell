/*
** EPITECH PROJECT, 2024
** env
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/struct.h"

int error_unset(mini_t *mini)
{
    if (mini->tab_clean[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (1);
    }
    return (0);
}

void my_unsetenv(mini_t *mini, int i)
{
    linked_t *prev = mini->linked;
    linked_t *current = prev->next;

    if (my_strncmp(mini->tab_clean[i], prev->line,
    my_strlen(mini->tab_clean[i])) == 0) {
        mini->linked = mini->linked->next;
        return;
    }
    while (current != NULL) {
        if (my_strncmp(mini->tab_clean[i], current->line,
        my_strlen(mini->tab_clean[i])) == 0 &&
        current->line[my_strlen(mini->tab_clean[i])] == '=') {
            prev->next = current->next;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void display_env(mini_t *mini, linked_t *list)
{
    while (list != NULL) {
        my_putstr(list->line);
        my_putstr("\n");
        list = list->next;
    }
}

static char *second_arg(mini_t *mini, char *line)
{
    if (mini->tab_clean[2] != NULL) {
        line = my_strcat(line, mini->tab_clean[2]);
    }
    return (line);
}

int already_exist(mini_t *mini, linked_t *list)
{
    char *line = NULL;

    while (list != NULL) {
        if (my_strncmp(mini->tab_clean[1], list->line,
        my_strlen(mini->tab_clean[1])) == 0) {
            line = my_strcat(mini->tab_clean[1], "=");
            line = second_arg(mini, line);
            list->line = my_strdup(line);
            return (1);
        }
        list = list->next;
    }
}

static int set_isok(mini_t *mini)
{
    for (int i = 0; mini->tab_clean[1][i] != '\0'; i++) {
        if ((mini->tab_clean[1][0] < 'a' || mini->tab_clean[1][0] > 'z') &&
        (mini->tab_clean[1][0] < 'A' || mini->tab_clean[1][0] > 'Z')) {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return (84);
        }
        if (mini->tab_clean[1][i] < '0' || mini->tab_clean[1][i] > '9' &&
        mini->tab_clean[1][i] < 'A' || mini->tab_clean[1][i] > 'Z' &&
        mini->tab_clean[1][i] < 'a' || mini->tab_clean[1][i] > 'z') {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return (84);
        }
    }
    return (0);
}

int my_setenv(mini_t *mini)
{
    char *line = NULL;

    if (mini->tab_clean[1] == NULL) {
        display_env(mini, mini->linked);
        return (0);
    }
    if (set_isok(mini) == 84)
        return (0);
    if (already_exist(mini, mini->linked) == 1)
        return (0);
    line = my_strcat(mini->tab_clean[1], "=");
    if (mini->tab_clean[2] != NULL)
        line = my_strcat(line, mini->tab_clean[2]);
    put_in_list(&mini->linked, line);
}
