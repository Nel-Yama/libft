/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:00:52 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:00:53 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - copies up to dstsize - 1 characters from the string src to dst,
 *        NUL-terminating the result if dstsize is not 0.
 * @param dst : pointer to destination string.
 * @param src : ponter to source string
 * @param dstsize : maximum size of string including the NUL teminating char.
 * @return - the total length of the string the function tried to create.
 *            meaning the function should return the length of src.
 * !!! - If the return value is >= dstsize, the output string has been truncated.
 *       It is the caller's responsibility to handle this.
 * If the src and dst strings overlap, the behavior is undefined.
 * bug : used "i < dstsize -1" in condition but when dstsize is equal 0
 *       it rounds to "4294967295"  so I changed the condition to 
 *       "i + 1 < dstsize"
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
