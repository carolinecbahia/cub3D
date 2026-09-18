/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 23:48:32 by ccavalca          #+#    #+#             */
/*   Updated: 2026/09/18 15:42:16 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_err(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

int	return_error(char *msg, int err)
{
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (err);
}

void	print_texture_error(char *path)
{
	ft_putstr_fd("Error\nFailed to load texture: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
