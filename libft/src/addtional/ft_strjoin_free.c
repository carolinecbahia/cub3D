/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:25:16 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:46:02 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*joins two strings and frees inputs based on bit flags in to_free.*/

char	*ft_strjoin_free(char *s1, char *s2, int to_free)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	if (!s1 || !s2)
	{
		if (to_free & 1)
			free(s1);
		if (to_free & 2)
			free(s2);
		return (NULL);
	}
	joined = ft_strjoin(s1, s2);
	if (to_free & 1)
		free(s1);
	if (to_free & 2)
		free(s2);
	return (joined);
}
