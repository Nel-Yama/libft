/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nassr.elyamani@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:46:24 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/07 14:16:45 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief lexicographically compare n characters from the strings s1 and s2.
 * @param s1 : pointer to string 1.
 * @param s2 : pointer to string 2.
 * @param n  : number of characters to compare in both strings.
 * @return an integer greater than, equal to, or less than 0,
 *       as the string s1 is greater , equal to, or less than the string s2.
 * The comparison is using unsigned chars, so ‘\200’ is greater than ‘\0’.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;
	size_t				i;

	if (n == 0)
		return (0);
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	i = 0;
	while (us1[i] && us2[i] && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (us1[i] - us2[i]);
}
