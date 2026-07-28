/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:51 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:22:57 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

static int	find_colors(char *line, char type)
{
	if (type == 'F')
		return (ft_strncmp(line, "F ", 2) == 0);
	if (type == 'C')
		return (ft_strncmp(line, "C ", 2) == 0);
	return (0);
}

#pragma GCC diagnostic pop

void	parse_color_line(char **lines __attribute__((unused)))
{

}
