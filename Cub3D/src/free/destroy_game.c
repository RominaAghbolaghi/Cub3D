/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:44:53 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 23:10:52 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
	line = NULL;
}

/* ************************************************************************** */

void	free_texture(t_cubddd *all)
{
	int	i;

	i = 0;
	if (all->path_wall[WE])
		free(all->path_wall[WE]);
	if (all->path_wall[NO])
		free(all->path_wall[NO]);
	if (all->path_wall[EA])
		free(all->path_wall[2]);
	if (all->path_wall[SO])
		free(all->path_wall[SO]);
	while (i < 4)
	{
		if (all->text[i].img)
			mlx_destroy_image(all->mlx, all->text[i].img);
		i++;
	}
	free(all->path_wall);
	free(all->text);
}

/* ************************************************************************** */

void	free_data(t_data *data)
{
	if (data->map)
		free_line(data->map);
}

/* ************************************************************************** */

void	destroy_game(t_cubddd *all)
{
	if (all->file)
		free_line(all->file);
	free_texture(all);
	free_data(&all->data);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->img.img)
		mlx_destroy_image(all->mlx, all->img.img);
	if (all->mlx)
		mlx_destroy_display(all->mlx);
	free(all->mlx);
}

/* ************************************************************************** */

void	bad_end(t_cubddd *all, char *msg)
{
	destroy_game(all);
	ft_error(msg);
}

/* ************************************************************************** */
