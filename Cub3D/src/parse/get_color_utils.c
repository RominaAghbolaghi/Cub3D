/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:14:00 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 22:59:37 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

bool	check_rgb(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(&str[i]) < 0 || ft_atoi(&str[i]) > 255)
		return (false);
	return (true);
}

/* ************************************************************************** */

int	skip_spacecomma(int i, char *str, t_cubddd *all)
{
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != ',')
		bad_end(all, "This is not correct RGB, so is an error.");
	while (ft_isspace(str[++i]))
		;
	return (i);
}

/* ************************************************************************** */

static void	if_exist(t_cubddd *all, int type)
{
	if (type == C && all->ceiling.b != -1
		&& all->ceiling.g != -1 && all->ceiling.r != -1)
		bad_end(all, "Ceiling color is duplicated.");
	if (type == F && all->floor.b != -1
		&& all->floor.g != -1 && all->floor.r != -1)
		bad_end(all, "Floor color is duplicated.");
}

/* ************************************************************************** */

int	color_loop(t_cubddd *all, char *str, char c, int type)
{
	int	i;

	i = 0;
	if_exist(all, type);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == c)
		i++;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

/* ************************************************************************** */