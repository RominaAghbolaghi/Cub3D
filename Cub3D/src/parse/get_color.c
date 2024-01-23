/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:53 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/18 09:34:48 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	*check_ceiling(t_cubddd *all, char *str)
{
	int	i;

	i = color_loop(all, str, 'C', C);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		bad_end(all, "This is not correct RGB, so is an error.");
	all->ceiling.r = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, all);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		bad_end(all, "This is not correct RGB, so is an error.");
	all->ceiling.g = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, all);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		bad_end(all, "This is not correct RGB, so is an error.");
	all->ceiling.b = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		bad_end(all, "This is not correct RGB, so is an error.");
	return (NULL);
}

/* ************************************************************************** */

static void	*check_floor(t_cubddd *all, char *str)
{
	int	i;

	i = color_loop(all, str, 'F', F);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		bad_end(all, "This is not correct RGB, so is an error.");
	all->floor.r = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, all);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		bad_end(all, "This is not correct RGB, so is an error.");
	all->floor.g = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, all);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		bad_end(all, "This is not correct RGB, so is an error.");
	all->floor.b = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		bad_end(all, "This is not correct RGB, so is an error.");
	return (NULL);
}

/* ************************************************************************** */

void	get_color(t_cubddd *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->file[i])
	{
		j = 0;
		while (all->file[i][j] && (!ft_isprint(all->file[i][j])
				|| all->file[i][j] == ' '))
			j++;
		if (all->file[i][j] == 'F')
			check_floor(all, all->file[i]);
		else if (all->file[i][j] == 'C')
			check_ceiling(all, all->file[i]);
		i++;
	}
}

/* ************************************************************************** */
