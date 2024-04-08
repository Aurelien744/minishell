/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** minishell1
*/

#ifndef MY_H_
    #define MY_H_
    #include "./struct.h"

int my_list(mini_t *mini, char **env);
int minishell(mini_t *mini, char **env);
int my_putstr(char const *str);
void my_putchar(char c);
int str_available(mini_t *mini);
int my_builtins(mini_t *mini, char **env);
int my_strlen(char const *str);
void display_env(mini_t *mini, linked_t *list);
char **my_str_to_word_array(char *str, char sep);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int shell_cmd(mini_t *mini, char **env);
char *my_strcat(char *dest, char const *src);
int my_cd(mini_t *mini);
int put_in_list(linked_t **linked, char *line);
int my_setenv(mini_t *mini);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
void my_unsetenv(mini_t *mini, int i);
int is_asegv(int status);
int error_unset(mini_t *mini);
char *clean_semicolon(char *dirty);
int key_char(char *str, mini_t *mini);
int list_pipe(pipe_list_t **node, char *cmd);
int my_pipe(mini_t *mini);
int concatenate_pipe_cmd(mini_t *mini);
void execute_command(mini_t *mini, pipe_list_t **cur);

#endif
