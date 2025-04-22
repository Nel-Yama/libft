/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:01:43 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:01:45 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Helper function to check if a string contains char c
 * @param s: The string to be browse looking for c.
 * @param c: The char to check if exist in s.
 * @return 1 if the string s contains character c, 0 otherwise.
 */
static int	is_char_in_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief - Allocates memory (using malloc(3)) and returns a copy of ’s1’
 *         with characters from ’set’ removed from the beginning and the end.
 * @param s1: The string to be trimmed.
 * @param set: The string containing the set of characters to be removed.
 * @return The trimmed string. Or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	l;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	l = ft_strlen(s1);
	start = 0;
	end = l;
	while (s1[start] && is_char_in_str(set, s1[start]))
		start++;
	while (end > start && is_char_in_str(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}
