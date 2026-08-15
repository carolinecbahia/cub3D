/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:33:52 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:31:09 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether c is a 7-bit unsigned char 
value that fits into the ASCII character set.*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
