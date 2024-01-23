/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:31:33 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/18 11:10:11 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keycode_LINUX.h"
# include "struct.h"

/* ************************************************************************** */
// **INIT
/* ************************************************************************** */
/*   init_cubddd.c                                      :+:      :+:    :+:   */
void	init_cubddd(t_cubddd *all);

/* ************************************************************************** */
// **PARSE
/* ************************************************************************** */
/*   get_color_utils.c                                  :+:      :+:    :+:   */
bool	check_rgb(char *str);
int		skip_spacecomma(int i, char *str, t_cubddd *all);
int		color_loop(t_cubddd *all, char *str, char c, int type);
/*   get_color.c                                        :+:      :+:    :+:   */
void	get_color(t_cubddd *all);
/*   get_cub_file.c                                     :+:      :+:    :+:   */
void	get_file(char *path, t_cubddd *all);
/*   get_map.c                                          :+:      :+:    :+:   */
void	get_map(t_cubddd *all);
/*   parse_map.c                                        :+:      :+:    :+:   */
void	parse_map(t_cubddd *all);
/*   parse_utils.c                                      :+:      :+:    :+:   */
int		rgb_to_hex(t_rgb rgb);
bool	is_texture(char **strs);
bool	is_color(char **strs);
void	only_onemap(char **file, t_cubddd *all);
/*   parsing.c                                          :+:      :+:    :+:   */
void	parse_cub(t_cubddd *all, char *map_name);

/* ************************************************************************** */
// **IMAGE
/* ************************************************************************** */
/*   draw_game.c                                        :+:      :+:    :+:   */
void	create_game(t_cubddd *all);
void	draw_line(t_cubddd *all, int width, float dist);
/*   ray_casting.c                                      :+:      :+:    :+:   */
float	ray_shoot(t_cubddd *all, float start_angle);
void	ft_raycasting(t_cubddd *all);

/* ************************************************************************** */
// **GAME
/* ************************************************************************** */
/*   start_calculation.c                                :+:      :+:    :+:   */
void	start_calculation(t_cubddd *all);
/*   player_view.c                                      :+:      :+:    :+:   */
void	player_pos_view(t_cubddd *all);

/* ************************************************************************** */
// **EVENTS
/* ************************************************************************** */
/*   key_events.c                                       :+:      :+:    :+:   */
int		key_touch(int keysym, t_cubddd *all);

/* ************************************************************************** */
// **FREE
/* ************************************************************************** */
/*   destroy_game.c                                     :+:      :+:    :+:   */
void	destroy_game(t_cubddd *all);
void	bad_end(t_cubddd *all, char *msg);
/*   ft_error.c                                         :+:      :+:    :+:   */
void	ft_error(char *str);

/* ************************************************************************** */
// **UTILS
/* ************************************************************************** */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
bool	empty_line(char *str, int space);
int		init_path_wall(t_cubddd *all);

#endif
