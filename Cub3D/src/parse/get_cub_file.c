/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauveur <jsauveur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:23 by rmohamma          #+#    #+#             */
/*   Updated: 2023/12/17 22:55:06 by jsauveur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_fileline(char *file, t_cubddd *all)
{
	char	*line;
	int		nb_line;
	int		fd;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		bad_end(all, "Open file failure.");
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		bad_end(all, "File empty.");
	}
	while (line != NULL)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_line);
}

static void	get_line(t_cubddd *all, int i, int j, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		bad_end(all, "File empty.");
	while (line)
	{
		j = -1;
		all->file[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (all->file[i] == NULL)
		{
			close(fd);
			free(line);
			bad_end(all, "Malloc issues.");
		}
		while (line[++j] != '\0')
			all->file[i][j] = line[j];
		all->file[i][j] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	all->file[i] = NULL;
	close(fd);
}

void	get_file(char *path, t_cubddd *all)
{
	int		file_len;
	int		fd;

	fd = 0;
	file_len = get_fileline(path, all);
	all->file = malloc(sizeof(char *) * (file_len + 1));
	if (all->file == NULL)
	{
		close(fd);
		bad_end(all, "Malloc issues.");
	}
	fd = open (path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		bad_end(all, "Open failure");
	}
	get_line(all, 0, 0, fd);
}
