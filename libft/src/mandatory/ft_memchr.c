/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:05:50 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:52:19 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*scans memory for the first occurrence of a byte value.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		find;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	find = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == find)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
