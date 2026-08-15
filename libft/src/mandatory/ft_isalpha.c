/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:16:08 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:30:35 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks  for an alphabetic character; 
in the standard "C" locale, it is equivalent to (isupper(c) || islower(c)).*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
