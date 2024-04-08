/*
** EPITECH PROJECT, 2024
** pipe_list
** File description:
** minishell2
*/

#include "my.h"
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

int list_pipe(pipe_list_t **node, char *cmd)
{
    struct pipe_list_s *newnode = malloc(sizeof(*newnode));
    struct pipe_list_s *current = *node;

    newnode->cmd = cmd;
    newnode->next = NULL;
    if (*node == NULL) {
        *node = newnode;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = newnode;
    }
    return (0);
}
