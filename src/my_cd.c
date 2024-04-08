/*
** EPITECH PROJECT, 2024
** my_cd
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/struct.h"

int updt_oldpwd(mini_t *mini)
{
    linked_t *current = mini->linked;
    char *newold = malloc(sizeof(char) * 256);

    free(mini->oldpwd);
    mini->oldpwd = malloc(sizeof(char) * 256);
    mini->oldpwd[0] = '\0';
    getcwd(newold, 256);
    mini->oldpwd = my_strcat(mini->oldpwd, "OLDPWD=");
    mini->oldpwd = my_strcat(mini->oldpwd, newold);
    while (current != NULL) {
        if (my_strncmp(current->line, "OLDPWD=", 7) == 0) {
            current->line = malloc(my_strlen(mini->oldpwd) + 9);
            my_strcpy(current->line, mini->oldpwd);
            free(newold);
            return (1);
        }
        current = current->next;
    }
    return (0);
}

char *find_oldpwd(mini_t *mini)
{
    linked_t *current = mini->linked;
    char *oldpwd = NULL;

    while (current != NULL) {
        if (my_strncmp(current->line, "OLDPWD=", 7) == 0) {
            oldpwd = my_strdup(current->line + 7);
            return (oldpwd);
        }
        current = current->next;
    }
    return oldpwd;
}

void past_dir(mini_t *mini)
{
    char *back_pos = malloc(sizeof(char) * 256);
    char *save = malloc(sizeof(char) * 256);

    back_pos = find_oldpwd(mini);
    if (back_pos == NULL) {
        save = my_strdup(mini->nooldpwd);
        getcwd(mini->nooldpwd, 256);
        chdir(save);
        return;
    }
    updt_oldpwd(mini);
    getcwd(mini->nooldpwd, 256);
    chdir(back_pos);
    free(back_pos);
}

static char *find_home(mini_t *mini)
{
    linked_t *current = mini->linked;
    char *home;

    while (current != NULL) {
        if (my_strncmp(current->line, "HOME=", 5) == 0) {
            home = my_strdup(current->line + 5);
            return (home);
        }
        current = current->next;
    }
}

void home_dir(mini_t *mini)
{
    char *go_home = malloc(sizeof(char) * 256);

    go_home = find_home(mini);
    updt_oldpwd(mini);
    getcwd(mini->nooldpwd, 256);
    chdir(go_home);
    free(go_home);
}

static int error_path(char *path)
{
    struct stat st;

    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            return 0;
        } else {
            my_putstr(path);
            my_putstr(": Not a directory.\n");
            return 1;
        }
    } else {
        my_putstr(path);
        my_putstr(": No such file or directory.\n");
        return 1;
    }
}

int my_cd(mini_t *mini)
{
    int rtn = 0;

    if (mini->tab_clean[1] == NULL ||
    my_strcmp(mini->tab_clean[1], "~") == 0) {
        home_dir(mini);
        return (0);
    }
    if (my_strcmp(mini->tab_clean[1], "-") == 0) {
        past_dir(mini);
        return 0;
    }
    updt_oldpwd(mini);
    rtn = error_path(mini->tab_clean[1]);
    if (rtn == 0) {
        getcwd(mini->nooldpwd, 256);
        chdir(mini->tab_clean[1]);
    }
    return (rtn);
}
