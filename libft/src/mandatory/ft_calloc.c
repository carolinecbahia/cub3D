/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:25:19 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:29:24 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*allocates memory for an array of nmemb elements 
of size bytes each and returns a pointer to the
allocated memory.  The memory is set to zero.*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*aloc;

	if (nmemb > 0 && size > 0 && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	total = nmemb * size;
	aloc = malloc(total);
	if (aloc == NULL)
		return (NULL);
	ft_bzero(aloc, total);
	return (aloc);
}
