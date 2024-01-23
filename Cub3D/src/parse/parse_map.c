/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:21:35 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/18 00:28:04 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static bool	check_elements(char **map)
{
	int		i;
	int		j;
	ssize_t	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != '\t' && map[i][j] != '\n' && map[i][j] != 'N'
				&& map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 'E')
				return (true);
			else if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != '\n')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1 || player == 0)
		return (true);
	return (false);
}

/* ************************************************************************** */

static bool	dfs(char **map, int i, int j, t_data *data)
{
	if (i == -1 || i == data->map_line - 1 || j == 0 || j == data->row_max - 1)
		return (false);
	if (map[i][j] == '0')
	{
		if (((i + 1 <= data->map_line - 2
					&& j > (int)ft_strlen(map[i + 1]) - 2)
				|| j >= (int)ft_strlen(map[i]) - 2)
			|| (i - 1 >= 0 && (j > (int)ft_strlen(map[i - 1]) - 2)))
			return (true);
	}
	if (map[i][j] == '1' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == '2')
		return (false);
	else if (map[i][j] == '0')
		map[i][j] = '2';
	else if (map[i][j] == ' ')
	{
		return (true);
	}
	if (dfs(map, i - 1, j, data) || dfs(map, i, j + 1, data)
		|| dfs(map, i + 1, j, data) || dfs(map, i, j - 1, data))
		return (true);
	return (false);
}

/* ************************************************************************** */

static bool	map_isclosed(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || i == (data->map_line - 1)
					|| j == 0 || j == (data->row_max)
					|| j == (int)ft_strlen(map[i]) - 2)
					return (true);
				if (dfs(map, i, j, data) == true)
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

/* ************************************************************************** */

static void	init_mapdir(t_map *map, char **maps, int i)
{
	while (maps[i])
	{
		if (ft_strchr(maps[i], 'N'))
		{
			map->dir.x = 0;
			map->dir.y = -1;
		}
		else if (ft_strchr(maps[i], 'E'))
		{
			map->dir.x = 1;
			map->dir.y = 0;
		}
		else if (ft_strchr(maps[i], 'S'))
		{
			map->dir.x = 0;
			map->dir.y = 1;
		}
		else if (ft_strchr(maps[i], 'W'))
		{
			map->dir.x = -1;
			map->dir.y = 0;
		}
		i++;
	}
}

/* ************************************************************************** */

void	parse_map(t_cubddd *all)
{
	char	**map_duplicate;

	map_duplicate = all->data.map;
	if (check_elements(all->data.map) == 1)
		bad_end(all, "Character not accepted or not only one player!");
	if (map_isclosed(map_duplicate, &all->data))
		bad_end(all, "Map not closed.");
	init_mapdir(&all->map, all->data.map, 0);
}
/* ************************************************************************** */
