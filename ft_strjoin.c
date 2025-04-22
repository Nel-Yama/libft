/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:00:38 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:00:39 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Allocates memory (using malloc(3)) and returns a new string,
 *          which is the result of concatenating ’s1’ and ’s2’.
 * @param s1: The prefix string.
 * @param s2: The suffix string.
 * @return The substring. Or NULL if the allocation fails.
 * Tuisted logic "i < (lens1 + lens2)" is used to avoid 2 while loops.
 * !!! Edge case when s1 or s2 is NULL a NULL pointer is returned.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s = malloc(lens1 + lens2 + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < (lens1 + lens2))
	{
		if (i < lens1)
			s[i] = s1[i];
		else
			s[i] = s2[i - lens1];
		i++;
	}
	s[i] = '\0';
	return (s);
}
