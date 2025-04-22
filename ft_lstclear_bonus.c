/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:58:56 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 23:33:41 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief -  Deletes and frees the given node and all its
 *          successors, using the function ’del’ and free(3).
 *          Finally, set the pointer to the list to NULL.
 * @param lst: The address of a pointer to a node.
 * @param del: The address of the function used to delete the content 
 *             of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
