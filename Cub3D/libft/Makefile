# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2021/10/15 08:41:44 by jsauveur          #+#    #+#              #
# #    Updated: 2023/12/17 21:57:50 by jsauveur         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

SHELL		= /bin/sh

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
CFLAGSRAM	= -g3 -fsanitize=address

RM 			= rm -rf

OBJ_DIR		= obj
SRC_DIR		= src
INCLUDE		= -I include

SRCS		=								\
				find_sign.c					\
				ft_atoi.c					\
				ft_isdigit.c				\
				ft_isprint.c				\
				ft_isspace.c				\
				ft_putstr_fd.c				\
				ft_split.c					\
				ft_strchr.c					\
				ft_strcmp.c					\
				ft_strjoin.c				\
				ft_strlen.c					\
				ft_strtrim.c				\
				ft_substr.c					\
				str_isdigit.c				\
				${addprefix get_next_line/,	\
					get_next_line_utils.c	\
					get_next_line.c			\
				}							\
				${addprefix printf/,		\
					ft_lowerhex.c			\
					ft_printbase.c			\
					ft_printf.c				\
					ft_putchar.c			\
					ft_putnbr.c				\
					ft_putstr.c				\
					ft_unsign.c				\
					ft_upperhex.c			\
					ft_point.c				\
				}							\

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJS)
	@ar -rcs $@ $^
	@ranlib $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "Compiling $< to $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean		:
	@$(RM) $(OBJ_DIR)

fclean		: clean
	@$(RM) $(NAME)

re			: fclean all
