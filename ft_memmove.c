/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:57:56 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:57:59 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - function copies len bytes from string src to string dst.
 *        The two strings may overlap; 
 *        The copy is always done in a non-destructive manner.
 * @param dst : pointer to destination memory.
 * @param src : pointer to source memory
 * @param len : number of bytes to copy from src to dst.
 * @return The original value of dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*usrc;
	unsigned char		*udst;
	size_t				i;

	if (dst == src || len == 0)
		return (dst);
	usrc = (const unsigned char *)src;
	udst = (unsigned char *)dst;
	i = 0;
	if (udst > usrc && udst < usrc + len)
	{
		while (len--)
			udst[len] = usrc[len];
	}
	else
	{
		while (i < len)
		{
			udst[i] = usrc[i];
			i++;
		}
	}
	return (dst);
}
