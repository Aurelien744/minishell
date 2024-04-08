/*
** EPITECH PROJECT, 2024
** linked_list
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/struct.h"

int put_in_list(linked_t **linked, char *line)
{
    struct linked_s *newnode = malloc(sizeof(*newnode));
    struct linked_s *current = *linked;

    newnode->line = line;
    newnode->next = NULL;
    if (*linked == NULL) {
        *linked = newnode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
    return 0;
}

int my_list(mini_t *mini, char **env)
{
    mini->linked = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        put_in_list(&mini->linked, env[i]);
    }
    return (0);
}
