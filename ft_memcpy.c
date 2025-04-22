/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:57:33 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:57:51 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - copies n bytes from memory area src to memory area dst.
 *        If dst and src overlap, behavior is undefined.
 *        Applications in which dst and src might overlap
 *        should use memmove(3) instead.
 * @param dst : pointer to destination memory.
 * @param src : pointer to source memory
 * @return original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udst;
	size_t				i;

	udst = (unsigned char *)dst;
	usrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}
