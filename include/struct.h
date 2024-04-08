/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** minishell1
*/

#ifndef STRUCU_H_
    #define STRUCU_H_
    #include <sys/wait.h>

typedef struct linked_s {
    struct linked_s *next;
    char *line;
}linked_t;

typedef struct pipe_list_s {
    struct pipe_list_s *next;
    char *cmd;
    char **cmd_tab;
    char *bin_cmd;
}pipe_list_t;

typedef struct mini_s {
    pid_t child1;
    int rtn;
    char *input;
    char *cleaned;
    char **tab_clean;
    char **path;
    char *full_cmd;
    char *oldpwd;
    char *nooldpwd;
    char **pipe_tab;
    int pipe_nb;
    char *clean_cmd;
    linked_t *linked;
    pipe_list_t *pipe_list;
}mini_t;

#endif
