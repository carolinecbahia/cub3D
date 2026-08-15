/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:10:24 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:28:49 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

/*erases the data in the n bytes of the memory 
starting at the location pointed to by s, 
by writing zeros (bytes containing '\0') to that area.*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
