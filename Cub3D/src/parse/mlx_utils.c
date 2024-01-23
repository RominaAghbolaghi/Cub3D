/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:21:27 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 22:59:40 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

bool	empty_line(char *str, int space)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (space == 1)
		{
			if (!ft_isprint(str[i]) || str[i] == ' ')
				i++;
			else
				return (false);
		}
		else
		{
			if (!ft_isprint(str[i]))
				i++;
			else
				return (false);
		}
	}
	return (true);
}

/* ************************************************************************** */

int	init_path_wall(t_cubddd *all)
{
	all->path_wall = (char **)malloc(sizeof(char *) * (4 + 1));
	if (!all->path_wall)
		bad_end(all, "Malloc failed for path_wall.");
	all->path_wall[WE] = NULL;
	all->path_wall[NO] = NULL;
	all->path_wall[EA] = NULL;
	all->path_wall[SO] = NULL;
	return (-1);
}

/* ************************************************************************** */
