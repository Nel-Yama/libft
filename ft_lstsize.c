/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:49:52 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:49:53 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Counts the number of nodes in the list.
 * @param lst: The beginning of the list.
 * @return The length of the list
 */
int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst)
	{
		lst_size++;
		lst = lst->next;
	}
	return (lst_size);
}
