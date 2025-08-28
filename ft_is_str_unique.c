/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_unique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:27:08 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/27 16:27:08 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief : checks if all characters in a given string are unique.
 * @param str : pointer to the string to check.
 * @return : 1 if all chars in str are unique (or str is empty/null)
 *           0 if any character appears more than once.
 * Algo : Iterates through each char in str until the null terminator (\0).
 *        For each character str[i] : 
 *              Casts it to unsigned char to ensure consistent indexing 
 *      into hash_table (avoids issues with signed char or extended ASCII).
 *              Checks if hash_table[(unsigned char)str[i]] is non-zero 
 *    (i.e., the character was seen before)
 *              If so, returns 0 (not unique). Otherwise, marks the char 
 *       as seen by setting hash_table[(unsigned char)str[i]] = 1.
 */
int	ft_is_str_unique(const char *str)
{
	size_t			i;
	unsigned char	hash_table[256];

	if (!str || !(*str))
		return (1);
	i = 0;
	ft_bzero(hash_table, sizeof(hash_table));
	while (str[i])
	{
		if (hash_table[(unsigned char)str[i]])
			return (0);
		hash_table[(unsigned char)str[i]] = 1;
		i++;
	}
	return (1);
}
