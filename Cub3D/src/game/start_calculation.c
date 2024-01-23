/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:31:41 by rmohamma          #+#    #+#             */
/*   Updated: 2024/01/09 22:24:15 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	init_texture_files(t_cubddd *all)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (all->path_wall[i] == NULL)
			bad_end(all, "No path for texture file.");
	/*is used to load an XPM (X PixMap) file and create an image object from it. */
		all->text[i].img = mlx_xpm_file_to_image(all->mlx, all->path_wall[i],
				&all->text[i].img_width, &all->text[i].img_height);/* will be filled with the width and height of the image*/
		if (all->text[i].img == NULL)
			bad_end(all, "Read texture file failure. "
				"(Wrong path, incorrect format...)");
		/*provide information about the image data that can be useful when manipulating
				 pixel values or interacting with the image.*/
		all->text[i].addr = mlx_get_data_addr(all->text[i].img,
				&all->text[i].bpp, &all->text[i].line_len,
				&all->text[i].endian);/*It returns a pointer to the image data, typically stored as a character array (char *),
				 allowing further manipulation or processing of the image data.*/
	}
}

/* ************************************************************************** */

static void	init_file_data(t_cubddd *all)
{
	all->mlx = mlx_init();
	if (!all->mlx)
		ft_error("Connection is failed.");
	init_texture_files(all);
	all->win = mlx_new_window(all->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");/*is used to create a new window. */
	if (!all->win)
	{
		free(all->mlx);
		ft_error("Mlx_new_window() failed.");
	}
}

/* ************************************************************************** */

static int	close_destroy(t_cubddd *all)
{
	ft_putstr(RED"Thanks for playing!\n"RESET_C);
	destroy_game(all);
	exit(0);
}
/* ************************************************************************** */

void	start_calculation(t_cubddd *all)
{
	player_pos_view(all);
	init_file_data(all);
	create_game(all);
	mlx_hook(all->win, DestroyNotify, 0, &close_destroy, all);
	mlx_hook(all->win, KeyPress, KeyPressMask, &key_touch, all);
	mlx_loop(all->mlx);
}

/* ************************************************************************** */
