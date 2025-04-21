/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nassr.elyamani@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:41:10 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/20 19:21:40 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

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
