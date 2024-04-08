/*
** EPITECH PROJECT, 2024
** str_available
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/struct.h"

char *right_nb_spaces(int *next, char *clean_str, int *a)
{
    if (*next == 1) {
        clean_str[*a] = ' ';
        *a = *a + 1;
        *next = 0;
    }
    return (clean_str);
}

char *clean_str(mini_t *mini)
{
    int a = 0;
    int next = 0;
    int x;

    mini->cleaned = malloc(sizeof(char) * my_strlen(mini->input) + 1);
    for (x = 0; (mini->input[x] == ' ' || mini->input[x] == '\t'); x++);
    for (int i = x; mini->input[i] != '\0'; i++) {
        if ((mini->input[i] == ' ' || mini->input[i] == '\t'))
            next = 1;
        if (mini->input[i] != ' ' && mini->input[i] != '\t') {
            right_nb_spaces(&next, mini->cleaned, &a);
            mini->cleaned[a] = mini->input[i];
            a++;
        }
    }
    mini->cleaned[a - 1] = '\0';
    if (mini->cleaned[a - 2] == ' ')
        mini->cleaned[a - 2] = '\0';
    return (mini->cleaned);
}

static int check_last_pipe(mini_t *mini)
{
    int size = my_strlen(mini->cleaned);

    size = size - 1;
    for (; mini->cleaned[size] != '|'; size--) {
        if (mini->cleaned[size] != ' ' && mini->cleaned[size] != '|')
            return (0);
    }
    return 1;
}

static int check_first_pipe(mini_t *mini)
{
    for (int i = 0; mini->cleaned[i] != '|'; i++) {
        if (mini->cleaned[i] != ' ' && mini->cleaned[i] != '|')
            return 0;
    }
    return 1;
}

int str_available(mini_t *mini)
{
    clean_str(mini);
    if (check_first_pipe(mini) == 0 && check_last_pipe(mini) == 0)
        return (0);
    my_putstr("Invalid null command.\n");
    mini->input = my_strcpy(mini->input, "\n");
    return (0);
}
