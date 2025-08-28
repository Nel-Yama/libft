/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:49:06 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:49:11 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Adds the node ’new’ at the beginning of the list.
 * @param lst: The address of a pointer to the first node of a list.
 * @param new: The address of a pointer to the node to be added.
 * @return None
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
