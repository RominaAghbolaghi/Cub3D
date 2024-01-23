/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:09:31 by rmohamma          #+#    #+#             */
/*   Updated: 2024/01/09 22:30:06 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	draw_ceil_floor(t_cubddd *all)
{
	unsigned int	*pixel;
	unsigned int	half_screen;

	pixel = (unsigned int *)all->img.addr;
	half_screen = WIN_WIDTH * WIN_HEIGHT / 2;
	while (half_screen-- > 0)
		*pixel++ = all->data.ceiling_color;
	half_screen = WIN_WIDTH * WIN_HEIGHT / 2;
	while (half_screen-- > 0)
		*pixel++ = all->data.floor_color;
}

/* ************************************************************************** */

void	create_game(t_cubddd *all)
{
	all->img.img = mlx_new_image(all->mlx, WIN_WIDTH, WIN_HEIGHT);/*This function generates a new image or graphical buffer with the specified dimensions
	 (width and height) and returns a pointer (void *) to this newly created image.*/
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
			&all->img.line_len, &all->img.endian);
	draw_ceil_floor(all);
	ft_raycasting(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
}

/* ************************************************************************** */

static void	check_wall_too_hight(float *text_factor, unsigned int *wall_height,
		float screen_shift)
{
	if ((*wall_height) > WIN_HEIGHT)
	{/* This scaling factor of 0.5 might be chosen for reasons related to visual aesthetics or to control 
	the extent of adjustment. It's common to use a fraction of the difference to avoid excessive adjustments 
	that could distort the texture too much.*/
		(*text_factor) = 0.5f * ((*wall_height) - WIN_HEIGHT) * screen_shift;/*screen_shift ensuring that 
		the texture aligns properly with the visible part of the wall on the screen.*/
		(*wall_height) = WIN_HEIGHT;
	}
}

/* ************************************************************************** */

void	draw_line(t_cubddd *all, int width, float dist)
{
	unsigned int	*screen_buff;
	unsigned int	*text_pixel;
	unsigned int	wall_height;
	float			text_factor;
	float			screen_shift;

	wall_height = (float)WIN_HEIGHT / dist;
	text_factor = 0.0f;/* the position within the texture*/
	screen_shift = (float)all->text[all->text_index].img_height / wall_height;/*the increment in the texture for each pixel in the wall segment.*/
	check_wall_too_hight(&text_factor, &wall_height, screen_shift);
	/*Set initial positions for reading from the texture (text_pixel) and writing to the screen (screen_buff).*/
	text_pixel = (unsigned int *)all->text[all->text_index].addr;
	/*This calculates the total number of pixels in a row of the original texture image*/
	text_pixel += (int)((float)all->text_width
			* all->text[all->text_index].img_width);
	screen_buff = (unsigned int *)all->img.addr
		+ width + (WIN_HEIGHT - wall_height) / 2 * WIN_WIDTH;
		/*(unsigned int *)all->img.addr: all->img.addr represents the starting address of the screen buffer. 
		Casting it to (unsigned int *) is done to treat it as a pointer to unsigned integers, 
		likely the data type used for storing pixel information.

width: This is the current pixel column being rendered. It represents the horizontal position within
 the screen buffer.

(WIN_HEIGHT - wall_height) / 2: This term calculates the vertical offset needed to center the rendered 
wall height within the window. WIN_HEIGHT is the total height of the window, and wall_height is the 
calculated height of the wall. Subtracting wall_height from WIN_HEIGHT and dividing by 2 gives 
the top offset to center the wall vertically.

* WIN_WIDTH: This term scales the vertical offset by the width of the window (WIN_WIDTH).
 It ensures that the calculated offset is applied in terms of pixels in the horizontal direction.*/
	while (wall_height-- > 0)
	{/*the color of each pixel on the wall is determined by sampling the texture at the current text_factor. 
	This involves reading the color information from the texture image based on the calculated position.*/
		*screen_buff = *(text_pixel + ((int)text_factor)
				* all->text[all->text_index].img_width);/*This line assigns the color of the current pixel 
				on the wall to the corresponding position in the screen buffer.*/
		screen_buff += WIN_WIDTH;/*represents the width of the window, and this operation moves to the next row
		 in the window.*/
		text_factor += screen_shift;/* As the ray moves along the wall, the text_factor 
		is incremented to sample the texture at different positions.
		the next position in the texture for the next pixel in the wall. */
	}/*The while loop continues iterating for each pixel in the height of the wall, and with each iteration, 
	it performs the operations mentioned above to draw the line (textured wall) on the screen buffer.
	 The loop ends when the entire height of the wall has been covered.*/
}

/* ************************************************************************** */
