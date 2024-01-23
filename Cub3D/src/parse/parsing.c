/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:34 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 23:01:15 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

void	recup_path_wall(t_cubddd *all, int index, int j, char *strs)
{
	int	k;

	while (strs[j] && (!ft_isprint(strs[j]) || strs[j] == ' '))
			j++;
	k = j;
	while (strs[k] && (ft_isprint(strs[k]) && strs[k] != ' '))
			k++;
	if (strs[k] != '\n' && strs[k] != ' ')
		bad_end(all, "Texture files fail.");
	if (strs[j])
	{
		if (!all->path_wall[index])
			all->path_wall[index] = ft_substr(&strs[j], 0, k - j);
		else
			bad_end(all, "Texture files fail.");
	}
	all->text_index = index;
}

/* ************************************************************************** */

static void	get_texture(t_cubddd *all)
{
	int	j;
	int	i;

	i = -1;
	while (all->file[++i])
	{
		j = 0;
		while (all->file[i][j] && (!ft_isprint(all->file[i][j])
				|| all->file[i][j] == ' '))
			j++;
		if (all->file[i][j] == 'N' && all->file[i][j + 1] == 'O')
			recup_path_wall(all, NO, j + 2, all->file[i]);
		else if (all->file[i][j] == 'S' && all->file[i][j + 1] == 'O')
			recup_path_wall(all, SO, j + 2, all->file[i]);
		else if (all->file[i][j] == 'W' && all->file[i][j + 1] == 'E')
			recup_path_wall(all, WE, j + 2, all->file[i]);
		else if (all->file[i][j] == 'E' && all->file[i][j + 1] == 'A')
			recup_path_wall(all, EA, j + 2, all->file[i]);
	}
	all->path_wall[4] = NULL;
}

/* ************************************************************************** */

static void	check_file(char **map, t_cubddd *all)
{
	int	i;
	int	j;
	int	len_type;

	i = -1;
	while (map[++i])
	{
		len_type = ft_strlen(map[i]);
		j = 0;
		while (map[i][j] && (!ft_isprint(map[i][j]) || map[i][j] == ' '))
			j++;
		if (!(len_type > 3
				&& (((map[i][j] == 'N' || map[i][j] == 'S')
				&& map[i][j + 1] == 'O')
				|| (map[i][j] == 'E' && map[i][j + 1] == 'A')
				|| (map[i][j] == 'W' && map[i][j + 1] == 'E')))
			&& !(len_type > 2
				&& ((map[i][j] == 'F') || (map[i][j] == 'C')))
			&& (!empty_line(map[i], 0))
			&& !(map[i][j] == '1'))
			bad_end(all, "Invalid text file.");
	}
}

/* ************************************************************************** */

void	parse_cub(t_cubddd *all, char *map_name)
{
	get_file(map_name, all);
	init_path_wall(all);
	if (is_texture(all->file))
		get_texture(all);
	if (is_color(all->file))
	{
		get_color(all);
		if (all->floor.r == -1 || all->ceiling.r == -1)
			bad_end(all, "You forget floor or ceiling. Take care!");
		all->data.floor_color = rgb_to_hex(all->floor);
		all->data.ceiling_color = rgb_to_hex(all->ceiling);
	}
	else
		bad_end(all, "File not conform.");
	check_file(all->file, all);
	only_onemap(all->file, all);
	get_map(all);
	parse_map(all);
	if (all->path_wall == NULL || all->text == NULL
		|| all->data.map == NULL)
		bad_end(all, "File cub not conform.");
}

/* ************************************************************************** */
