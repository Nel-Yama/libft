/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nassr.elyamani@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:55:05 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/19 16:22:51 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief identical to strchr(), except it locates the last occurrence of c.
 * @param s : string to browse
 * @param c : char to locate last occurence in string s
 * @return pointer to last occurence of c in s.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	cast_c;

	p = NULL;
	if (!s)
		return (NULL);
	cast_c = (char)c;
	while (*s)
	{
		if (*s == cast_c)
			p = (char *)s;
		s++;
	}
	if (*s == cast_c)
		p = (char *)s;
	return (p);
}
