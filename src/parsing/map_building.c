/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:40:36 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:21:48 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

static int line_len_no_nl(char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\0')
	{
		len++;
	}
	return (len);
}

static int copy_line_to_row(char *row __attribute__((unused)), char *line __attribute__((unused)), int width __attribute__((unused)))
{
	return (0);
}

static int is_map_block_line(char *line)
{
	int i;

	i = 0;
	if (line[i] == 'F' || line[i] == 'C')
		return (0);
	if (ft_strncmp(line, "NO ", 3) || ft_strncmp(line, "SE ", 3)
		|| ft_strncmp(line, "EA ", 3) || ft_strncmp(line, "WE ", 3))
		return (0);
	return (1);
}

static int is_blank_line(char *line)
{
	if (line == NULL || line[0] == '\0')
	{
		return (0);
	}
	return (1);
}

#pragma GCC diagnostic pop

int build_map_row(char **grid __attribute__((unused)), int i __attribute__((unused)), char *line __attribute__((unused)), int width __attribute__((unused)))
{
	return (0);
}
