/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:24:49 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:45:33 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_unlink_node(t_list **lst, t_list **prev,
	t_list **curr, void (*del)(void *))
{
	t_list	*next;

	next = (*curr)->next;
	if (*prev)
		(*prev)->next = next;
	else
		*lst = next;
	if (del)
		del((*curr)->content);
	free(*curr);
	*curr = next;
}

/*removes all list nodes whose content matches data_ref by cmp function.*/

void	ft_lst_remove_if(t_list **lst, void *data_ref,
	int (*cmp)(void *, void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*prev;

	if (!lst || !cmp)
		return ;
	curr = *lst;
	prev = NULL;
	while (curr)
	{
		if (cmp(curr->content, data_ref) == 0)
			ft_unlink_node(lst, &prev, &curr, del);
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
