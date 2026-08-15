/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:51 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 13:39:40 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_colors(char *line, char type)
{
	if (type == 'F')
		return (ft_strncmp(line, "F", 1) == 0);
	if (type == 'C')
		return (ft_strncmp(line, "C", 1) == 0);
	return (0);
}

static char	*extract_rgb_values(char *line)
{
	int	i;

	i = 1;
	if (line[i] != ' ' && line[i] != '\t')
		return (NULL);
	while (line[i] == ' ' || line[i] == '\t')
			i++;
	if (line[i] == '\0')
		return (NULL);
	return (&line[i]);
}

int	validate_rgb_values(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (return_error("╰┈➤ Invalid red value! 🔴\n", 0));
	if (g < 0 || g > 255)
		return (return_error("╰┈➤ Invalid green value! 🟢\n", 0));
	if (b < 0 || b > 255)
		return (return_error("╰┈➤ Invalid blue value! 🔵\n", 0));
	return (1);
}

int	save_color(int *slot, int r, int g, int b)
{
	if (*slot == -1)
	{
		*slot = (r << 24) | (g << 16) | (b << 8) | 0xFF;
		return (1);
	}
	return (return_error("╰┈➤ Duplicated color!\n", 0));
}

int	parse_color_line(char *line, t_map *map)
{
	char	*rgb;
	int		r;
	int		g;
	int		b;

	if (!find_colors(line, 'F') && !find_colors(line, 'C'))
		return (return_error("╰┈➤ Invalid color identifier!\n", 0));
	rgb = extract_rgb_values(line);
	if (!rgb)
		return (return_error("╰┈➤ Invalid RGB format!\n", 0));
	if (!parse_rgb(rgb, &r, &g, &b))
		return (0);
	if (!validate_rgb_values(r, g, b))
		return (0);
	if (find_colors(line, 'F'))
		return (save_color(&map->floor_color, r, g, b));
	if (find_colors(line, 'C'))
		return (save_color(&map->ceiling_color, r, g, b));
	return (0);
}
