/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:08:02 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/13 15:52:33 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../libft/inc/libft.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return_error("File not opened!\n", -1);
	}
	return (fd);
}

static	int	fill_file_lines(char *filename, char **file_lines)
{
	int		fd;
	int		i;
	char	*buffer;

	fd = open_file(filename);
	if (fd == -1)
		return (0);
	i = 0;
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		file_lines[i] = ft_strtrim(buffer, "\n");
		free(buffer);
		if (!file_lines[i])
		{
			close(fd);
			return (0);
		}
		i++;
		buffer = get_next_line(fd);
	}
	close(fd);
	return (1);
}

char	**read_lines(char *filename)
{
	int		fd;
	char	**file_lines;
	int		line_count;

	fd = open_file(filename);
	line_count = count_lines(fd);
	close(fd);
	file_lines = ft_calloc(line_count + 1, sizeof(char *));
	if (!file_lines)
		return (NULL);
	if (!fill_file_lines(filename, file_lines))
	{
		ft_free_matrix(file_lines);
		return (NULL);
	}
	return (file_lines);
}

t_map	init_map(char *filename)
{
	t_map	map;

	map.map_path = ft_strdup(filename);
	map.grid = NULL;
	map.width = 0;
	map.height = 0;
	ft_memset(map.textures_path, 0, sizeof(map.textures_path));
	map.floor_color = -1;
	map.ceiling_color = -1;
	map.player_x = 0;
	map.player_y = 0;
	map.player_dir = 0;
	return (map);
}
