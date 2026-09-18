/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:34:37 by ccavalca          #+#    #+#             */
/*   Updated: 2026/09/18 14:39:15 by anunes-o         ###   ########.fr       */
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
		ft_putstr_fd("\nErrorFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (NULL);
	}
	return (texture);
}

int	load_all_textures(t_game *game)
{
	int	i;

	if (!game)
		return (FAILURE);
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

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i])
		{
			mlx_delete_texture(game->textures[i]);
			game->textures[i] = NULL;
		}
		i++;
	}
}
