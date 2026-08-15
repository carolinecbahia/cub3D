/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:24:52 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:45:40 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns the number of strings in a null-terminated matrix.*/

size_t	ft_matrix_len(char **matrix)
{
	size_t	len;

	if (!matrix)
		return (0);
	len = 0;
	while (matrix[len])
		len++;
	return (len);
}
