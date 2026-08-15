/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:37:23 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:54:07 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*duplicates the string s into a new allocated buffer.*/

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*aloc;

	size = ft_strlen(s) + 1;
	aloc = (char *)malloc(size);
	if (aloc == NULL)
		return (NULL);
	else
		ft_strlcpy(aloc, s, size);
	return (aloc);
}
