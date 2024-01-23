/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubddd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:41:14 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 20:07:33 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h" 

/* ************************************************************************** */

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
	img->img_width = 0;
	img->img_height = 0;
}

/* ************************************************************************** */

static void	init_map(t_map *map)
{
	map->pos.x = 0;
	map->pos.y = 0;
	map->dir.x = 0;
	map->dir.y = 0;
	map->map_x = 0;
	map->map_y = 0;
	map->step_x = 0;
	map->step_y = 0;
}

/* ************************************************************************** */

static void	init_trgb(t_rgb *trgb)
{
	trgb->r = -1;
	trgb->g = -1;
	trgb->b = -1;
}

/* ************************************************************************** */

static void	init_data(t_data *data)
{
	data->ceiling_color = 0;
	data->floor_color = 0;
	data->map = NULL;
	data->map_line = 0;
	data->row_max = 0;
}

/* ************************************************************************** */

void	init_cubddd(t_cubddd *all)
{
	int	i;

	all->mlx = NULL;
	all->win = NULL;
	all->file = NULL;
	all->text_index = 0;
	all->text_width = 0.0f;
	all->text_height = 0.0f;
	init_img(&all->img);
	init_map(&all->map);
	all->text = (t_img *)malloc(sizeof(t_img) * 4);
	if (all->text == NULL)
		bad_end(all, "Malloc failed for texture");
	all->path_wall = NULL;
	init_img(all->text);
	i = -1;
	while (++i < 4)
		all->text[i].img = NULL;
	init_data(&all->data);
	init_trgb(&all->ceiling);
	init_trgb(&all->floor);
}

/* ************************************************************************** */
