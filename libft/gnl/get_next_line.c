/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:01:49 by ccavalca          #+#    #+#             */
/*   Updated: 2025/08/14 16:42:32 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_and_null(char **ptr1, char **ptr2, int index)
{
	if ((index == 1 || index == 3) && ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if ((index == 2 || index == 3) && ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

static char	*read_to_stash(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_and_null(stash, NULL, 1));
	bytes_read = 1;
	while (!ft_strchr_gnl(*stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_and_null(stash, &buffer, 3));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(*stash, buffer);
		if (!temp)
			return (ft_free_and_null(stash, &buffer, 3));
		if (*stash)
			free(*stash);
		*stash = temp;
	}
	ft_free_and_null(&buffer, NULL, 1);
	return (*stash);
}

static char	*get_line_from_stash(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		line = ft_substr_gnl(stash, 0, i + 1);
	else
		line = ft_substr_gnl(stash, 0, i);
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	len;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	len = ft_strlen_gnl(stash);
	if (stash[i] == '\n' && (len - i - 1) > 0)
		new_stash = ft_substr_gnl(stash, i + 1, len - i - 1);
	else
		new_stash = NULL;
	ft_free_and_null(&stash, NULL, 1);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, &stash);
	if (!stash || !*stash)
		ft_free_and_null(&stash, NULL, 1);
	line = get_line_from_stash(stash);
	if (!line)
		return (ft_free_and_null(&stash, NULL, 1));
	stash = update_stash(stash);
	return (line);
}
