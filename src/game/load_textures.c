/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:34:37 by ccavalca          #+#    #+#             */
/*   Updated: 2026/09/18 15:43:21 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_png_texture(t_wall_texture *wall, char *path)
{
	wall->texture = mlx_load_png(path);
	if (!wall->texture)
	{
		print_texture_error(path);
		return (FAILURE);
	}
	wall->xpm = NULL;
	wall->type = TEXTURE_PNG;
	return (SUCCESS);
}

static int	load_xpm_texture(t_wall_texture *wall, char *path)
{
	wall->xpm = mlx_load_xpm42(path);
	if (!wall->xpm)
	{
		print_texture_error(path);
		return (FAILURE);
	}
	wall->texture = &wall->xpm->texture;
	wall->type = TEXTURE_XPM42;
	return (SUCCESS);
}

static int	load_single_texture(t_wall_texture *wall, char *path)
{
	if (!wall || !path)
		return (FAILURE);
	wall->texture = NULL;
	wall->xpm = NULL;
	wall->type = TEXTURE_NONE;
	if (check_file_extension(path, ".png"))
		return (load_png_texture(wall, path));
	if (check_file_extension(path, ".xpm42"))
		return (load_xpm_texture(wall, path));
	print_texture_error(path);
	return (FAILURE);
}

int	load_all_textures(t_game *game)
{
	int	i;

	if (!game)
		return (FAILURE);
	i = 0;
	while (i < 4)
	{
		if (load_single_texture(&game->textures[i],
				game->map.textures_path[i]) == FAILURE)
		{
			destroy_textures(game);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

void	destroy_single_texture(t_wall_texture *wall)
{
	if (!wall)
		return ;
	if (wall->type == TEXTURE_XPM42 && wall->xpm)
		mlx_delete_xpm42(wall->xpm);
	else if (wall->type == TEXTURE_PNG && wall->texture)
		mlx_delete_texture(wall->texture);
	wall->texture = NULL;
	wall->xpm = NULL;
	wall->type = TEXTURE_NONE;
}
