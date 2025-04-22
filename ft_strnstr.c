/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:01:27 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:01:27 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locates the first occurrence of the null-terminated string needle
 *      in the string haystack, where not more than len characters are
 *      searched. Characters that appear after a ‘\0’ char aren't searched.
 * @param haystack : big string where we look for the occurence of needle.
 * @param needle   : small string that we try to find in hastack.
 * @param len      : length of needle we try to find in haystack
 * @return If needle is an empty string, haystack is returned;
 *       if needle occurs nowhere in haystack, NULL is returned;
 *       otherwise a pointer to the first character of the first
 *       occurrence of needle is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j) < len
			&& (haystack[i + j] == needle[j]))
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
