/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:25:10 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:45:55 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*writes a string with optional ANSI color prefix and reset sequence.*/

void	ft_putstr_color_fd(char *s, const char *color, int fd)
{
	if (!s)
		return ;
	if (color)
		write(fd, color, ft_strlen(color));
	write(fd, s, ft_strlen(s));
	if (color)
		write(fd, "\033[0m", 4);
}
