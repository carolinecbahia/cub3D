/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:55:18 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 00:17:27 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <fcntl.h>
#include <unistd.h>

int check_file_extension(char *filename)
{
    int len = strlen(filename);
    if (len < 4 || strcmp(filename + len - 4, ".cub") != 0)
    {
        ft_err("wrong extension!");
        return (0);
    }
    return (1);
}

char	*map_reader(int fd)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*map_content;
	char	*temp;

	map_content = ft_strdup("");
	if (!map_content)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(map_content, buffer);
		free(map_content);
		map_content = temp;
		if (!map_content)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		ft_printf("Error\nReading file failed\n");
		return (NULL);
	}
	return (map_content);
}

char	*open_and_read_map(char *file)
{
	int		fd;
	char	*map_content;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Failed to read map file", 2);
		return (NULL);
	}
	map_content = map_reader(fd);
	close (fd);
	if (!map_content)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Failed to read map file", 2);
		return (NULL);
	}
	return (map_content);
}

int validate_file(t_map map)
{
	(void)map;
	return (0);
}

t_map parse_map(t_map map)
{
	(void)map;
	t_map dummy = {0};
	return dummy;
}
