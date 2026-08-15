/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:24:42 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:45:27 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns the node at index in the list, or NULL if out of range.*/

t_list	*ft_lst_get_node(t_list *lst, int index)
{
	if (index < 0)
		return (NULL);
	while (lst && index > 0)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}
