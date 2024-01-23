/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:49:48 by jsauveur          #+#    #+#             */
/*   Updated: 2023/12/17 19:50:01 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	player_view(char c, t_cubddd *all)
{
	if (c == 'N')
		all->map.view_angle = 1.5f * M_PI;
	else if (c == 'W')
		all->map.view_angle = M_PI;
	else if (c == 'S')
		all->map.view_angle = 0.5f * M_PI;
	else if (c == 'E')
		all->map.view_angle = 0.0f;
}

/* ************************************************************************** */

void	player_pos_view(t_cubddd *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->data.map[++i])
	{
		j = -1;
		while (all->data.map[i][++j])
		{
			if (ft_strchr("NWSE", all->data.map[i][j]))
			{
				all->map.pos.x = (float)j + 0.5f;
				all->map.pos.y = (float)i + 0.5f;
				player_view(all->data.map[i][j], all);
				return ;
			}
		}
	}
}

/* ************************************************************************** */
