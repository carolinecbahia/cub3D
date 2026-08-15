/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:48:30 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 13:22:34 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

int	parse_rgb(char *rgb_str, int *r, int *g, int *b)
{
	char	**rgb_values;
	int		i;

	rgb_values = ft_split(rgb_str, ',');
	if (!rgb_values)
		return (return_error("╰┈➤ Failed to split RGB values!\n", 0));
	i = 0;
	while (rgb_values[i])
		i++;
	if (i != 3)
	{
		ft_free_matrix(rgb_values);
		return (return_error("╰┈➤ Invalid RGB format!\n", 0));
	}
	*r = ft_atoi(rgb_values[0]);
	*g = ft_atoi(rgb_values[1]);
	*b = ft_atoi(rgb_values[2]);
	ft_free_matrix(rgb_values);
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '0') && (line[i] != '1') && (line[i] != 'N')
			&& (line[i] != 'S') && (line[i] != 'E') && (line[i] != 'W')
			&& (line[i] != ' ') && (line[i] != '\t'))
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_line(char	*line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}
	if (line[i] == '\0')
		return (1);
	return (0);
}
