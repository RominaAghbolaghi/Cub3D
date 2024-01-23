/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:27:24 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 23:17:56 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define RESET_C "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define L_YELLOW "\033[93m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define L_MAGENTA "\033[95m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define DEFAUT "\033[39m"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 680

# define M_PI 3.14159265358979323846

# define WE 0
# define NO 1
# define EA 2
# define SO 3
# define F 4
# define C 5

typedef struct s_xy
{
	float	y;
	float	x;
}	t_xy;

typedef struct s_map
{
	float	view_angle;
	t_xy	pos;
	t_xy	dir;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
}	t_map;

typedef struct s_ray
{
	t_xy	dir;
	int		step_x;
	int		step_y;
	t_xy	side_vert;
	t_xy	side_horz;
	float	side_vert_dist;
	float	side_horz_dist;
	float	side_vert_remain;
	float	side_horz_remain;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_data
{
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			**map;
	int				map_line;
	int				row_max;
}	t_data;

typedef struct s_cubddd
{
	void	*mlx;
	void	*win;
	char	**file;
	char	**path_wall;
	int		text_index;
	float	text_width;
	float	text_height;
	t_img	img;
	t_map	map;
	t_ray	ray;
	t_data	data;
	t_rgb	floor;
	t_rgb	ceiling;
	t_img	*text;
}	t_cubddd;

#endif
