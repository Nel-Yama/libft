/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:56:33 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/23 00:56:33 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Iterates through the list ’lst’, applies the function ’f’
 *          to each node’s content, and creates a new list resulting of
 *          the successive applications of the function ’f’.
 *    The ’del’ function is used to delete the content of a node if needed.
 * @param lst: The address of a pointer to a node.
 * @param f: The address of the function applied to each node’s content.
 * @param del: The address of the function
 *             used to delete a node’s content if needed.
 * @return  The new list. Or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	while (lst)
	{
	}
	return (new_list);
}
