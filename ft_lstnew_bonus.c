/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:49:39 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:49:44 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Allocates memory (using malloc(3)) and returns a new node.
 *          The ’content’ member variable is initialized with the given
 *          parameter ’content’. The variable ’next’ is initialized to NULL.
 * @param content: The content to store in the new node.
 * @return - A pointer to the new node.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
