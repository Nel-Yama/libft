/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:57:03 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:57:05 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - function locates the first occurrence of c
 *        (converted to an unsigned char) in string s.
 * @param s : pointer to first memory byte.
 * @param c : char to look for in s.
 * @param n : number of bytes of s to look in for c.
 * @return pointer to first occurence of c or NULL if c is not found in s.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;
	size_t				i;

	us = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (us[i] == uc)
			return ((void *)(us + i));
		i++;
	}
	return (NULL);
}
