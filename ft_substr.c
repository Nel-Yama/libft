/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:01:49 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:01:51 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Allocates memory (using malloc(3)) and returns a substring from
 *          the string ’s’. The substring starts at index ’start’ and has
 *          a maximum length of ’len’.
 * @param s: The original string from which to create the substring.
 * @param start: The starting index of the substring within 's'.
 * @param len: The maximum length of the substring.
 * @return The substring. Or NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, 1));
	if (len > slen - start)
		len = slen - start;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
