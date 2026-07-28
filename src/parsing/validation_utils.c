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

int	validate_texture_path(t_map *map __attribute__((unused)))
{
	return (1);
}

int		validate_rgb(t_map *map __attribute__((unused)))
{
	return (1);
}

int	check_file_extension(char *filename, char *extension)
{
	size_t len;

	len = ft_strlen(filename);
	if (ft_strcmp(filename + len - 4, extension) != 0)
		return (return_error("Wrong file extension!\n", 0));
	return (1);
}
