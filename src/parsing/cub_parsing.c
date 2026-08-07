/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:40:36 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:21:48 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_textures(char **file_lines, t_map *map)
{
	int	i;

	i = 0;
	while(file_lines[i])
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

