/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:36:38 by rmohamma          #+#    #+#             */
/*   Updated: 2024/01/09 19:19:34 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	ft_action(t_cubddd *all, int dir)
{
	float	dist;
	float	dist_x;
	float	dist_y;
	float	angle;

	angle = all->map.view_angle + dir * M_PI / 2;
	dist_x = 0.1f * cos(angle);/*The intended movement distance(speed) serves as a threshold or reference
	 point for determining whether the player or object has moved too close to a wall.*/
	dist_y = 0.1f * sin(angle);
	dist = ray_shoot(all, find_sign(dist_y) * M_PI / 2);/*One raycast in the vertical direction (90 degrees to the left or right).*/
	if (dist * dist < dist_y * dist_y)
		dist_y = 0.0f;
	dist = ray_shoot(all, (1 - (find_sign(dist_x) + 1) / 2) * M_PI);/*Another raycast in the horizontal direction (180 degrees, 
	opposite to the current viewing angle).*/
	if (dist * dist < dist_x * dist_x)/*If the distance to an obstacle or wall is less than the intended movement distance, it signifies a potential collision.
**/
		dist_x = 0.0f;/*This action ensures that if a wall or obstacle is too close in the intended movement direction, the movement in that direction is 
		stopped to prevent the player or object from passing through walls or boundaries.*/
	dist = ray_shoot(all, angle);/*One raycast based on the current viewing angle.*/
	if (dist * dist < dist_x * dist_x + dist_y * dist_y)
	{
		if (find_sign(dist_y) * find_sign(dist_x) != 0)/*the inner condition is checking whether the player or object is moving diagonally.*/
			dist_x = 0.0f;/*the movement in the x-direction is stopped to prevent passing through corners.*/
	}
	all->map.pos.x += dist_x;
	all->map.pos.y += dist_y;
}

/* ************************************************************************** */

int	key_touch(int keycode, t_cubddd *all)
{
	if (all->win == NULL)
		return (true);
	if (keycode == XK_Escape || keycode == XK_q || keycode == XK_Q)
	{
		ft_putstr(RED"Thanks for playing!\n"RESET_C);
		destroy_game(all);
		exit(0);
	}
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_action(all, 0);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_action(all, 2);
	else if (keycode == KEY_LEFT)
		all->map.view_angle -= 0.03f * M_PI;
	else if (keycode == KEY_RIGHT)
		all->map.view_angle += 0.03f * M_PI;
	else if (keycode == KEY_A)
		ft_action(all, 3);
	else if (keycode == KEY_D)
		ft_action(all, 1);
	else
		return (false);
	mlx_destroy_image(all->mlx, all->img.img);
	create_game(all);
	return (false);
}

/* ************************************************************************** */
