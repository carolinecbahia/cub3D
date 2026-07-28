/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:55:18 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:22:04 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"

static int find_map_start(t_map *map __attribute__((unused)))
{
	return (0);
}

static int read_map_size(t_map *map __attribute__((unused)), int start __attribute__((unused)), int *h __attribute__((unused)), int *w __attribute__((unused)))
{
	return (0);
}

char	**create_grid(t_map *map __attribute__((unused)))
{
	return (NULL);
}

static int fill_map_grid(t_map *map __attribute__((unused)), int start __attribute__((unused)))
{
	return (0);
}

void find_player(t_map *map __attribute__((unused)), int *px __attribute__((unused)), int *py __attribute__((unused)), char *dir __attribute__((unused)))
{

}

#pragma GCC diagnostic pop

