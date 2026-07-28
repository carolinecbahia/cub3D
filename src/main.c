/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/18 00:13:11 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (return_error("Wrong number of arguments.\n[USAGE]./cub3D /maps/valid_map.cub", 1));
	map = (t_map){0};
	map.map_path = argv[1];
	if (!validate_map(&map))
		return (return_error("Invalid map!", 1));
	else
		ft_printf("Ready to continue\n");
	return (0);
}
