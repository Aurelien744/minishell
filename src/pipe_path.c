/*
** EPITECH PROJECT, 2024
** pipe_path
** File description:
** minishell2
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <sys/wait.h>

void second_cmd(pid_t child1, pid_t child2, int pipefd[2], pipe_list_t **cur)
{
    child2 = fork();
    if (child2 == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
        execve((*cur)->next->bin_cmd, (*cur)->next->cmd_tab, NULL);
        exit(EXIT_FAILURE);
    } else {
        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(child1, NULL, 0);
        waitpid(child2, NULL, 0);
    }
}

void execute_command(mini_t *mini, pipe_list_t **cur)
{
    int pipefd[2];
    pid_t child1;
    pid_t child2;

    pipe(pipefd);
    child1 = fork();
    if (child1 == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execve((*cur)->bin_cmd, (*cur)->cmd_tab, NULL);
        exit(EXIT_FAILURE);
    } else {
        second_cmd(child1, child2, pipefd, cur);
    }
}

static char *pipe_find(char *command, mini_t *mini)
{
    char *line;
    char *fail = malloc(sizeof(char) * 1080);
    char *cpy = malloc(sizeof(char) * 1080);

    cpy[0] = '\0';
    fail[0] = '\0';
    fail = my_strcpy(fail, command);
    for (int i = 0; mini->path[i] != NULL; i++) {
        cpy = my_strcpy(cpy, mini->path[i]);
        line = my_strcat(cpy, "/");
        line = my_strcat(line, command);
        if (access(line, F_OK) == 0)
            return (line);
    }
    return (fail);
}

int concatenate_pipe_cmd(mini_t *mini)
{
    pipe_list_t *current = mini->pipe_list;

    while (current != NULL) {
        current->bin_cmd = pipe_find(current->cmd_tab[0], mini);
        current = current->next;
    }
}
