/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

int semi_colon(mini_t *mini, char **env)
{
    int size = my_strlen(mini->cleaned);
    char **semicolon;

    if (mini->cleaned[size - 1] == ';')
        mini->cleaned[size - 1] = '\0';
    semicolon = my_str_to_word_array(mini->cleaned, ';');
    for (int i = 0; semicolon[i] != NULL; i++) {
        semicolon[i] = clean_semicolon(semicolon[i]);
        key_char(semicolon[i], mini);
        mini->clean_cmd = clean_semicolon(semicolon[i]);
        if (my_strcmp(mini->cleaned, "exit") == 0)
            return 1;
        mini->tab_clean = my_str_to_word_array(semicolon[i], ' ');
        mini->rtn = my_builtins(mini, env);
    }
}

int minishell(mini_t *mini, char **env)
{
    char *b;
    size_t bufsize = 32;
    size_t characters;

    mini->input = malloc(sizeof(char) * 1080);
    b = mini->input;
    while (1) {
        if (isatty(0) != 0)
            my_putstr("$> ");
        characters = getline(&b, &bufsize, stdin);
        if (characters == -1)
            return (mini->rtn);
        str_available(mini);
        if (my_strcmp(mini->input, "\n") == 0)
            continue;
        if (semi_colon(mini, env) == 1)
            return 0;
    }
}
