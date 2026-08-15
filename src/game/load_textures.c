/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:34:37 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/14 23:00:24 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static mlx_texture_t	*load_single_texture(char *path)
{
	mlx_texture_t	*texture;

	if (!path)
		return (NULL);
	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (NULL);
	}
	return (texture);
}

int	load_all_textures(t_game *game)
{
    int i;

	i = 0;
	while (i < 4)
	{
		game->textures[i] = load_single_texture(game->map.textures_path[i]);
		if (!game->textures[i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	destroy_textures(t_game *game)
{
	int	i;

    i = 0;
	while (i < 4)
	{
		if (game->textures[i])
			mlx_delete_texture(game->textures[i]);
		i++;
	}
}
