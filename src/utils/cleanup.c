/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:23:32 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/13 22:03:58 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	cleanup_map(t_map	*map, char **file_lines)
{
	int	i;

	if (file_lines)
		ft_free_matrix(file_lines);
	if (!map)
		return ;
	ft_free_matrix(map->grid);
	// free(map->map_path); DOUBLE FREE
	i = 0;
	while (i < 4)
	{
		if (map->textures_path[i])
			free(map->textures_path[i]);
		i++;
	}
}
