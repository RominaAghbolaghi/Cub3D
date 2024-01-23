/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:21 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 23:01:26 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

int	rgb_to_hex(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

/* ************************************************************************** */

bool	is_texture(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == 'N' && strs[i][1] == 'O')
			return (true);
		else if (strs[i][0] == 'S' && strs[i][1] == 'O')
			return (true);
		else if (strs[i][0] == 'W' && strs[i][1] == 'E')
			return (true);
		else if (strs[i][0] == 'E' && strs[i][1] == 'A')
			return (true);
		i++;
	}
	return (false);
}

/* ************************************************************************** */

bool	is_color(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == 'F' || strs[i][0] == 'C')
			return (true);
		i++;
	}
	return (false);
}

/* ************************************************************************** */

void	only_onemap(char **file, t_cubddd *all)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (ft_isspace(file[i][j]))
				j++;
			else
				break ;
		}
		if (ft_isdigit(file[i][j]))
			break ;
		i++;
	}
	while (file[i] && (str_isdigit(file[i]) || empty_line(file[i], 0)))
		i++;
	if (file[i] != NULL)
		bad_end(all, "Map is not conform");
}

/* ************************************************************************** */
