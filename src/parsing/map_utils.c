/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:08:02 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:20:30 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../libft/inc/libft.h"

int	open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return_error("File not opened!\n", -1);
	}
	return (fd);
}

char	**read_lines(char *filename)
{
	int		fd;
	int		line_count;
	int		i;
	char	*buffer;
	char	**file_lines;

	fd = open_file(filename);
	line_count = count_lines(fd);
	close(fd);
	file_lines = malloc(sizeof(char *) * (line_count + 1));
	fd = open_file(filename);
	i = 0;
	while((buffer = get_next_line(fd)))
	{
		file_lines[i] = buffer;
		i++;
	}
	file_lines[i] = NULL;
	close(fd);
	return(file_lines);
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
