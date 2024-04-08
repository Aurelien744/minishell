##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/linked_list.c	\
		src/minishell.c	\
		src/builtins.c	\
		src/str_available.c	\
		src/shell_cmd.c	\
		src/env.c	\
		src/my_cd.c	\
		src/my_signals.c	\
		src/clean_semicolon.c	\
		src/key_char.c	\
		src/my_pipe.c	\
		src/pipe_list.c	\
		src/pipe_path.c	\
		tool/my_putstr.c	\
		tool/my_strlen.c	\
		tool/my_strcmp.c	\
		tool/my_str_to_word_array.c	\
		tool/my_strncmp.c	\
		tool/my_strcat.c	\
		tool/my_strdup.c	\
		tool/my_strcpy.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS += -g -I./include/

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -g -o $(NAME) $(OBJ) -L.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
