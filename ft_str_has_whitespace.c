/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_has_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:18:58 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/27 17:18:58 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief : checks if any of the chars of a string is a white space.
 * @param str : pointer to the string to browse.
 * @return : 1 if a white space is found, 0 otherwise.
 */
int	ft_str_has_whitespace(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isspace(*str))
			return (1);
		str++;
	}
	return (0);
}
