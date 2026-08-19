/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:17:49 by anunes-o          #+#    #+#             */
/*   Updated: 2026/08/19 16:18:28 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static t_vectors	next_point(t_vectors point, int direction)
{
	if (direction == 0)
		point.y--;
	else if (direction == 1)
		point.y++;
	else if (direction == 2)
		point.x--;
	else
		point.x++;
	return (point);
}

static int	add_neighbor(t_flood *flood, t_vectors point)
{
	char	cell;

	if (point.y < 0 || point.y >= flood->map->height
		|| point.x < 0 || point.x >= flood->map->width)
		return (0);
	if (flood->visited[point.y][point.x])
		return (1);
	cell = flood->map->grid[point.y][point.x];
	if (cell == ' ' || cell == '\0')
		return (0);
	if (cell == WALL || (cell != EMPTY && !is_player(cell)))
		return (1);
	flood->visited[point.y][point.x] = 1;
	flood->stack[flood->top++] = point;
	return (1);
}

static int	process_neighbors(t_flood *flood, t_vectors current)
{
	t_vectors	next;
	int			i;

	i = 0;
	while (i < 4)
	{
		next = next_point(current, i);
		if (!add_neighbor(flood, next))
			return (0);
		i++;
	}
	return (1);
}

int	flood_fill_iterative(t_map *map, int **visited, int y, int x)
{
	t_flood		flood;
	t_vectors	current;

	flood.map = map;
	flood.visited = visited;
	flood.stack = malloc(map->height * map->width * sizeof(t_vectors));
	if (!flood.stack)
		return (0);
	flood.top = 0;
	current = (t_vectors){x, y};
	visited[y][x] = 1;
	flood.stack[flood.top++] = current;
	while (flood.top > 0)
	{
		current = flood.stack[--flood.top];
		if (!process_neighbors(&flood, current))
			return (free(flood.stack), 0);
	}
	free (flood.stack);
	return (1);
}

int	free_visited(int **visited, int height, int result)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
	return (result);
}
