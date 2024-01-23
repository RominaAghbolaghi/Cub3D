/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:52:13 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 23:06:30 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* ************************************************************************** */

static void	check_args(char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file.");
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		free(line);
		ft_error("Your file is empty. =$");
	}
	while (line && empty_line(line, 1))
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			free(line);
			ft_error("Your file is empty. =$");
		}
	}
	free(line);
}

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_cubddd	all;
	size_t		len;

	if (argc != 2)
		ft_error("Wrong number of Arguments, no game !");
	len = ft_strlen(argv[1]);
	if (ft_strcmp(&argv[1][len - ft_strlen(".cub")], ".cub"))
		ft_error("The card file name is incorrect. We need .cub !");
	check_args(argv);
	init_cubddd(&all);
	parse_cub(&all, argv[1]);
	start_calculation(&all);
	return (0);
}

/* ************************************************************************** */
