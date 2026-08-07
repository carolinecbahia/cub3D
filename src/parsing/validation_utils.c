/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:30:15 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:23:58 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_all_textures(t_map *map)
{
	int i;

	i = 0;
	while(i < TEX_COUNT)
	{
		if (!map->textures_path[i])
			return (return_error("Missing texture\n", 0));
		i++;
	}
	return (1);
}

int	check_all_colors(t_map *map)
{
	if (map->floor_color == -1 || map->ceiling_color == -1)
		return (return_error("Missing color\n", 0));
	return (1);
}

int	check_file_extension(char *filename, char *extension)
{
	size_t len;
	size_t ext_len;

	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (len < ext_len)
		return (return_error("Wrong file extension!\n", 0));
	if (ft_strcmp(filename + len - ext_len, extension) != 0)
		return (return_error("Wrong file extension!\n", 0));
	return (1);
}
