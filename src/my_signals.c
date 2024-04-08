/*
** EPITECH PROJECT, 2024
** my_signals
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "unistd.h"
#include "../include/my.h"
#include "../include/struct.h"

int is_asegv(int status)
{
    int signal = WTERMSIG(status);

    if (WIFSIGNALED(status)) {
        if (signal == SIGSEGV)
            write(1, "Segmentation fault", 18);
        if (signal == SIGFPE)
            write(1, "Floating exception", 18);
        if (WCOREDUMP(status)) {
            write(1, " (core dumped)\n", 15);
        } else {
            write(1, "\n", 1);
        }
        return (signal + 128);
    }
    return 0;
}
