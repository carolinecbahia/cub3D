/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:53:48 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:23:19 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

static int	valid_texture_line(char *line, char dir)
{
	if (dir == 'N')
		return (ft_strncmp(line, "NO ", 3) == 0);
	if (dir == 'S')
		return (ft_strncmp(line, "SO ", 3) == 0);
	if (dir == 'W')
		return (ft_strncmp(line, "WE ", 3) == 0);
	if (dir == 'E')
		return (ft_strncmp(line, "EA ", 3) == 0);
	return (0);
}

static int	valid_texture_path(char *path __attribute__((unused)))
{
	return (0);
}

static int	check_duplicate_textures(t_map *map, char dir)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open_file(map->map_path);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (valid_texture_line(line, dir))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count > 1)
		return (0);
	return (1);
}

#pragma GCC diagnostic pop

int	validate_texture_slot(char **slot __attribute__((unused)), t_map *map __attribute__((unused)), char dir __attribute__((unused)))
{
	return (0);
}

void	parse_texture_line(char *line, t_map *map)
{

}
