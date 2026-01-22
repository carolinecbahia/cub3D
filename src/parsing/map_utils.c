/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:08:02 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 22:08:11 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**create_matrix(char *map_content)
{
	char	**matrix;

	if (!map_content)
		return (NULL);
	matrix = ft_split(map_content, '\n');
	if (!matrix)
		return (NULL);
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
