/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:08:02 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 01:03:11 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../libft/inc/libft.h"

char	**create_matrix(char *map_content)
{
	char	**all_lines;
	char	**matrix;
	int	count = 0;
	int	map_lines = 0;
	int	i = 0;

	if (!map_content)
		return (NULL);
	all_lines = ft_split(map_content, '\n');
	if (!all_lines)
		return (NULL);
	// Conta quantas linhas tem no mapa (a partir da linha 7)
	while (all_lines[count])
		count++;
	if (count <= 6)
	{
		ft_free_matrix(all_lines);
		return (NULL);
	}
	map_lines = count - 6;
	matrix = malloc(sizeof(char *) * (map_lines + 1));
	if (!matrix)
	{
		ft_free_matrix(all_lines);
		return (NULL);
	}
	for (i = 0; i < map_lines; i++)
		matrix[i] = ft_strdup(all_lines[i + 6]);
	matrix[map_lines] = NULL;
	ft_free_matrix(all_lines);
	return (matrix);
}

char	**dup_matrix(char **matrix)
{
	char	**matrix_copy;
	int		y;

	y = 0;
	while (matrix[y])
		y++;
	matrix_copy = (char **)malloc(sizeof(char *) * (y + 1));
	if (!matrix_copy)
		return (NULL);
	y = 0;
	while (matrix[y])
	{
		matrix_copy[y] = ft_strdup(matrix[y]);
		if (!matrix_copy[y])
		{
			ft_free_matrix(matrix_copy);
			return (NULL);
		}
		y++;
	}
	matrix_copy[y] = NULL;
	return (matrix_copy);
}
