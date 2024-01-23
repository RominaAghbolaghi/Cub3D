/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:21:35 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/18 11:12:11 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static int	map_line(char **file, int i)
{
	int	line;
	int	j;

	line = 1;
	while (i-- > 0)
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\n')
			j++;
		if (ft_isdigit(file[i][j]) == 1)
			line++;
		else if (file[i][j] == '\0')
			break ;
	}
	return (line);
}

/* ************************************************************************** */

static ssize_t	length_line(char *line_map)
{
	int		i;
	ssize_t	length;

	i = -1;
	length = 0;
	while (line_map[++i])
	{
		if (line_map[i] == '\t')
		{
			length += 4;
		}
		else
			length++;
	}
	return (length);
}

/* ************************************************************************** */

static void	copy_into(t_data *data, char *map_line, int x)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map_line[++i])
	{
		if (map_line[i] == '\t')
		{
			data->map[x][j++] = ' ';
			data->map[x][j++] = ' ';
			data->map[x][j++] = ' ';
			data->map[x][j++] = ' ';
		}
		else
			data->map[x][j++] = map_line[i];
	}
	data->map[x][j] = '\0';
}

/* ************************************************************************** */

static void	map_into_data(int line, t_cubddd *all, char **map)
{
	int		i;
	size_t	length_max;

	i = 0;
	length_max = 0;
	while (i < line)
	{
		all->data.map[i] = malloc(sizeof(char) * (length_line(map[i]) + 1));
		if (!all->data.map[i])
			bad_end(all, "Malloc issues.");
		copy_into(&all->data, map[i], i);
		if (ft_strlen(all->data.map[i]) > length_max)
			length_max = ft_strlen(all->data.map[i]);
		i++;
	}
	all->data.row_max = length_max - 1;
	all->data.map[i] = NULL;
}

/* ************************************************************************** */

void	get_map(t_cubddd *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->file[i])
		i++;
	i--;
	while (all->file[i])
	{
		j = 0;
		while (all->file[i][j] == ' ' || all->file[i][j] == '\t'
				|| all->file[i][j] == '\n')
			j++;
		if (ft_isdigit(all->file[i][j]))
			break ;
		else if (all->file[i][j] != '\0')
			bad_end(all, "Map not at the end.");
		i--;
	}
	all->data.map_line = map_line(all->file, i);
	all->data.map = malloc(sizeof(char *) * (all->data.map_line + 1));
	if (!all->data.map)
		bad_end(all, "Malloc issues.");
	map_into_data(all->data.map_line, all, &all->file[i - all->data.map_line
		+ 1]);
}

/* ************************************************************************** */
