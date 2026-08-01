/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 23:48:32 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 14:29:42 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_err(char *msg)
{
	printf("Error: %s!\n", msg);
}

int	return_error(char *msg, int err)
{
	printf("Error: %s\n", msg);
	return (err);
}