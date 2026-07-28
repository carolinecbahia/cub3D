/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:43:34 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:21:31 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

static void fill_row_with_spaces(char *row __attribute__((unused)), int width __attribute__((unused)))
{

}

static int alloc_rows(char **grid __attribute__((unused)), int height __attribute__((unused)), int width __attribute__((unused)))
{
	return (0);
}

static void free_partial_rows(char **grid __attribute__((unused)), int last __attribute__((unused)))
{

}

#pragma GCC diagnostic pop

char	**dup_grid(t_map *map __attribute__((unused)))
{
	return (NULL);
}

