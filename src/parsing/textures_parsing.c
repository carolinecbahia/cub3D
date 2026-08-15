/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:53:48 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 15:02:48 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	valid_texture_line(char *line, char dir)
{
	if (dir == 'N')
		return (ft_strncmp(line, "NO", 2) == 0);
	if (dir == 'S')
		return (ft_strncmp(line, "SO", 2) == 0);
	if (dir == 'W')
		return (ft_strncmp(line, "WE", 2) == 0);
	if (dir == 'E')
		return (ft_strncmp(line, "EA", 2) == 0);
	return (0);
}

static int	valid_texture_path(char *path)
{
	int	fd;

	if (!check_file_extension(path, ".png")
		&& !check_file_extension(path, ".xpm42"))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static char	*extract_texture_path(char *line)
{
	int	i;

	i = 2;
	if (line[i] != ' ' && line[i] != '\t')
		return (NULL);
	while (line[i] == ' ' || line[i] == '\t')
			i++;
	if (line[i] == '\0')
		return (NULL);
	return (&line[i]);
}

static int	save_texture(char **slot, char *path)
{
	if (!*slot)
	{
		*slot = ft_strdup(path);
		if (!*slot)
			return (return_error("╰┈➤ Failed to save texture!\n", 0));
		return (1);
	}
	return (return_error("╰┈➤ Duplicated texture!\n", 0));
}

int	parse_texture_line(char *line, t_map *map)
{
	char	*path;

	path = extract_texture_path(line);
	if (path == NULL)
		return (return_error("╰┈➤ Path not found!\n", 0));
	if (!valid_texture_path(path))
		return (return_error("╰┈➤ Invalid path! \n", 0));
	if (valid_texture_line(line, 'N'))
		return (save_texture(&map->textures_path[TEX_NO], path));
	if (valid_texture_line(line, 'S'))
		return (save_texture(&map->textures_path[TEX_SO], path));
	if (valid_texture_line(line, 'W'))
		return (save_texture(&map->textures_path[TEX_WE], path));
	if (valid_texture_line(line, 'E'))
		return (save_texture(&map->textures_path[TEX_EA], path));
	return (return_error("╰┈➤ Invalid texture identifier! 🧱\n", 0));
}
