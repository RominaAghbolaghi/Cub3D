# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 13:34:14 by rmohamma          #+#    #+#              #
#    Updated: 2023/12/18 02:40:37 by jsauveur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	-I/usr/local/include -I$(INC_DIR) -Imlx_linux
LIBFT		=	$(LIBFT_PATH)/libft.a
MLX			=	$(MLX_PATH)/libmlx.a

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR 	=	includes/
LIBFT_PATH	=	libft/
MLX_PATH	=	minilibx-linux/

SRC_FILES	=								\
				main.c						\
				${addprefix event/,			\
					key_events.c			\
				}							\
				${addprefix free/,			\
					destroy_game.c			\
					ft_error.c				\
				}							\
				${addprefix game/,			\
					player_view.c			\
					start_calculation.c		\
				}							\
				${addprefix image/,			\
					draw_game.c				\
					ray_casting.c			\
				}							\
				${addprefix init/,			\
					init_cubddd.c			\
				}							\
				${addprefix parse/,			\
					get_color_utils.c		\
					get_color.c				\
					get_cub_file.c			\
					get_map.c				\
					mlx_utils.c				\
					parse_map.c				\
					parse_utils.c			\
					parsing.c				\
				}							\


INC			=	$(addprefix -I, $(INC_DIR))
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
DEP			=	$(OBJ:.o=.d)


all	:	$(NAME) $(LIBFT)

$(LIBFT)	:
	@$(MAKE) -C $(LIBFT_PATH) all

$(MLX):
	@$(MAKE) -C $(MLX_PATH) all

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(BGreen)******* Cub3D: Compilation complete! *******$(BEnd)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(INC) -o $(NAME) $(LIBFT) -lXext -lX11 -lm -lz -L$(MLX_PATH) -lmlx -Lmlx_linux


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if not exist $(@D) mkdir $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INC) -Imlx_linux -MMD -MP -o $@ -c $<

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME) $(LIBFT)
	@echo "$(BBlue)******* Cleanup complete! *******$(BEnd)"

re: fclean all

.PHONY: libft minilibx all clean fclean re mlx

BGreen=\033[1;32m
BBlue=\033[1;34m
BEnd=\033[0m
