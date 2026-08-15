/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:40:36 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/13 22:15:48 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_textures(char **file_lines, t_map *map)
{
	int	i;

	i = 0;
	while (file_lines[i])
	{
		if (valid_texture_line(file_lines[i], 'N')
			|| valid_texture_line(file_lines[i], 'S')
			|| valid_texture_line(file_lines[i], 'W')
			|| valid_texture_line(file_lines[i], 'E'))
		{
			if (!parse_texture_line(file_lines[i], map))
				return (0);
		}
		i++;
	}
	if (!check_all_textures(map))
		return (0);
	return (1);
}

int	parse_colors(char **file_lines, t_map *map)
{
	int	i;

	i = 0;
	while (file_lines[i])
	{
		if (find_colors(file_lines[i], 'F') || find_colors(file_lines[i], 'C'))
		{
			if (!parse_color_line(file_lines[i], map))
				return (0);
		}
		i++;
	}
	if (!check_all_colors(map))
		return (0);
	return (1);
}

int	parse_map(char **file_lines, t_map *map)
{
	int	start;

	start = find_map_start(file_lines);
	if (start < 0)
		return (0);
	if (!read_map_size(file_lines, start, map))
		return (0);
	if (!create_grid(map))
		return (0);
	if (!fill_map_grid(file_lines, start, map))
		return (0);
	if (!validate_map_content(map))
		return (0);
	return (1);
}

int	parse_file(char *filename, t_map *map)
{
	char	**file_lines;

	if (!validate_file(filename))
		return (FAILURE); //usar FAILURE
	file_lines = read_lines(filename);
	if (!file_lines)
		return (FAILURE); //usar FAILURE
	if (!(parse_textures(file_lines, map)))
	{
		cleanup_map(map, file_lines);
		return (FAILURE);
	}
	if (!(parse_colors(file_lines, map)))
	{
		cleanup_map(map, file_lines);
		return (FAILURE);
	}
	if (!(parse_map(file_lines, map)))
	{
		cleanup_map(map, file_lines);
		return (FAILURE);
	}
	ft_free_matrix(file_lines);
	return (SUCCESS);
}
