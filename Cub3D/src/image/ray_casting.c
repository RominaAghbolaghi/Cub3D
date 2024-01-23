/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:03 by rmohamma          #+#    #+#             */
/*   Updated: 2024/01/09 23:47:53 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	init_ray(t_cubddd *all, t_ray *ray, float angle)
{
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	/*The DDA algorithm will always jump exactly one square each loop, either a
	 square in the x-direction, or a square in the y-direction. If it has to go
	  in the negative or positive x-direction, and the negative or positive 
	  y-direction will depend on the direction of the ray, and this fact will be 
	  stored in stepX and stepY. Those variables are always either -1 or +1*/
	ray->step_x = find_sign(ray->dir.x);
	ray->step_y = find_sign(ray->dir.y);
	/*Horizontal Movement (X-axis): The step in the x-dimension (left and right) determines 
	how the ray moves horizontally across the grid. A positive step might mean moving to the right, 
	while a negative step means moving to the left.

Vertical Movement (Y-axis): The step in the y-dimension (up and down) determines how the ray moves 
vertically across the grid. A positive step might mean moving downwards, while a negative step means 
moving upwards.*/
	ray->side_vert.x = (int)all->map.pos.x;/*the vertical and horizontal intersections 
	of the ray with the grid based on the player's position */
	if (ray->step_x > 0)
		ray->side_vert.x += 1.0f;/*that the ray starts from the next grid cell in the positive direction.*/
	ray->side_horz.y = (int)all->map.pos.y;
	if (ray->step_y > 0)
		ray->side_horz.y += 1.0f;
}

/* ************************************************************************** */

static void	get_ray_elements(t_cubddd *all, t_ray *ray)
{
	if (ray->step_x != 0)
	{/*Calculation of ray->side_vert.y determines the y-coordinate of the intersection point between the ray and the grid lines in the y-direction. */
		ray->side_vert.y = all->map.pos.y + ray->dir.y / ray->dir.x
			* (ray->side_vert.x - all->map.pos.x);/*The ratio ray->dir.y / ray->dir.x calculates the slope of the ray. This slope defines how steep or flat 
			the ray's trajectory is in the 2D space. A positive slope indicates an upward direction (increasing y with increasing x), a negative slope indicates a
			 downward direction (decreasing y with increasing x), and a zero slope represents a horizontal path.*/
		ray->side_vert_dist = sqrt(pow(all->map.pos.x - ray->side_vert.x, 2.0)
				+ pow(all->map.pos.y - ray->side_vert.y, 2.0));
		ray->side_vert_remain = ray->side_vert.y - (int)ray->side_vert.y;
		if (ray->step_x > 0)
			ray->side_vert_remain = 1 - ray->side_vert_remain;/*These adjustments are common in raycasting algorithms to handle texture mapping or accurate 
		collision detection, especially when the ray's direction affects how intersections with grid lines are processed or interpreted in a grid-based environment.*/
		/*Without this adjustment, the rendered textures might appear incorrectly positioned or collisions might not align precisely with grid boundaries, */
	}
	else
		ray->side_vert_dist = INFINITY;
	if (ray->step_y != 0)
	{
		ray->side_horz.x = all->map.pos.x + ray->dir.x / ray->dir.y
			* (ray->side_horz.y - all->map.pos.y);
		ray->side_horz_dist = sqrt(pow(all->map.pos.x - ray->side_horz.x, 2.0)
				+ pow(all->map.pos.y - ray->side_horz.y, 2.0));
		ray->side_horz_remain = ray->side_horz.x - (int)ray->side_horz.x;
		if (ray->step_y > 0)
			ray->side_horz_remain = 1 - ray->side_horz_remain;
	}
	else
		ray->side_horz_dist = INFINITY;
}

/* ************************************************************************** */

static float	hit_wall_color(t_cubddd *all, float distance,
				int color_index, float wall_hit)
{
	all->text_index = color_index;
	all->text_width = wall_hit;
	return (distance);
}

/* ************************************************************************** */

float	ray_shoot(t_cubddd *all, float start_angle)
{
	t_ray	ray;

	init_ray(all, &ray, start_angle);
	while (1)
	{
		get_ray_elements(all, &ray);
		if (ray.side_vert_dist < ray.side_horz_dist)/*Checks if the vertical intersection distance is smaller than the horizontal intersection distance. 
		If true, it means the next vertical intersection point is closer than the horizontal one.*/
		{
			if (all->data.map[(int)ray.side_vert.y]
				[(int)ray.side_vert.x + (ray.step_x - 1) / 2] == '1')/*The adjustment (ray.step_x - 1) / 2 in the x-coordinate might ensure the ray's 
				intersection point aligns correctly with the grid cells containing walls*/
				return (hit_wall_color(all, ray.side_vert_dist, ray.step_x + 1,
						ray.side_vert_remain));/* ray.step_x + 1 to be sure the ray's intersection point aligns correctly with the grid cells containing walls. */
			else
				ray.side_vert.x += ray.step_x;
		}
		else
		{
			if (all->data.map[(int)ray.side_horz.y + (ray.step_y - 1) / 2]
				[(int)ray.side_horz.x] == '1')
				return (hit_wall_color(all, ray.side_horz_dist, ray.step_y + 1,
						ray.side_horz_remain));
			else
				ray.side_horz.y += ray.step_y;
		}
	}
}

/* ************************************************************************** */

void	ft_raycasting(t_cubddd *all)
{
	int					x_axis;
	float				incr_per_pixel;
	float				start_angle;
	float				distance;
	static float		fov;

	fov = 60 * M_PI / 180;
	start_angle = all->map.view_angle - fov / 2;
	incr_per_pixel = fov / (WIN_WIDTH - 1);
	x_axis = -1;
	while (++x_axis < WIN_WIDTH)
	{
		distance = ray_shoot(all, start_angle);
		draw_line(all, x_axis, distance
			* cos(all->map.view_angle - start_angle));
		start_angle += incr_per_pixel;
	}
}

/* ************************************************************************** */
