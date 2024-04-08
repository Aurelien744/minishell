/*
** EPITECH PROJECT, 2024
** my_pipe
** File description:
** minishell2
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "struct.h"

static void separate_cmd_flag(mini_t *mini)
{
    pipe_list_t *current = mini->pipe_list;

    while (current != NULL) {
        current->cmd_tab = my_str_to_word_array(current->cmd, ' ');
        current = current->next;
    }
}

static void clean_all_pipe(mini_t *mini)
{
    for (int i = 0; mini->pipe_tab[i] != NULL; i++) {
        mini->pipe_tab[i] = clean_semicolon(mini->pipe_tab[i]);
        list_pipe(&mini->pipe_list, mini->pipe_tab[i]);
    }
    separate_cmd_flag(mini);
}

int valid_arg(mini_t *mini)
{
    mini->pipe_tab = my_str_to_word_array(mini->clean_cmd, '|');
    clean_all_pipe(mini);
}

void pipe_executor(mini_t *mini, int prevfd, pipe_list_t *cur, int pipefd[2])
{
    if (mini->child1 == 0) {
        if (cur != mini->pipe_list) {
            dup2(prevfd, STDIN_FILENO);
            close(prevfd);
        }
        if (cur->next != NULL)
            dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        if (execve(cur->bin_cmd, cur->cmd_tab, NULL) == -1) {
            write(STDERR_FILENO, cur->bin_cmd, my_strlen(cur->bin_cmd));
            write(STDERR_FILENO, ": Command not found.\n", 21);
            exit(EXIT_FAILURE);
        }
    } else {
        close(pipefd[1]);
        prevfd = pipefd[0];
        if (cur->next == NULL)
            waitpid(mini->child1, NULL, 0);
    }
}

int my_pipe(mini_t *mini)
{
    pipe_list_t *cur;
    int pipefd[2];
    int prevfd = STDIN_FILENO;

    mini->pipe_list = NULL;
    valid_arg(mini);
    concatenate_pipe_cmd(mini);
    cur = mini->pipe_list;
    while (cur != NULL) {
        pipe(pipefd);
        mini->child1 = fork();
        pipe_executor(mini, prevfd, cur, pipefd);
        cur = cur->next;
        prevfd = pipefd[0];
    }
    close(prevfd);
}
