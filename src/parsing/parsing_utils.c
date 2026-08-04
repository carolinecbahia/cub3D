/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:48:30 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 12:32:02 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int count_lines(int fd)
{
	char	*line;
	int		count;
	
	count = 0;
	line = NULL;
	while((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	return (count);
}