/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/13 22:11:05 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Uso: ./cub3D <mapa.cub>\n");
		return (1);
	}
	printf("=== INICIO DO PARSER ===\n");
	printf("[1] Inicializando map...\n");
	map = init_map(argv[1]);
	printf("[2] Chamando parse_file...\n");
	if (parse_file(argv[1], &map) == FAILURE) //comparação tem que ser com FAILURE (-1), estava comparando com 0 e tava retornando erro sempre por SUCESS = 0
	{
	printf("[ERRO] parse_file falhou!\n");
	return (1);
	}
	printf("[OK] parse_file terminou com sucesso!\n\n");
	printf("=== MAP ===\n");
	printf("map_path: %s\n", map.map_path);
	printf("width: %d\n", map.width);
	printf("height: %d\n", map.height);
	printf("player_x: %d\n", map.player_x);
	printf("player_y: %d\n", map.player_y);
	printf("player_dir: %c\n", map.player_dir);
	printf("\n=== GRID ===\n");
	for (int i = 0; i < map.height; i++)
		printf("[%02d] \"%s\"\n", i, map.grid[i]);
	printf("\n=== TEXTURES ===\n");
	printf("NO: %s\n", map.textures_path[0]);
	printf("SO: %s\n", map.textures_path[1]);
	printf("WE: %s\n", map.textures_path[2]);
	printf("EA: %s\n", map.textures_path[3]);
	printf("\n=== COLORS ===\n");
	printf("Floor: %d\n", map.floor_color);
	printf("Ceiling: %d\n", map.ceiling_color);
	cleanup_map(&map, NULL);
	printf("\n=== FIM ===\n");
	return (0);
}
