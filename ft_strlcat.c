/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:00:45 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:00:47 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief appends string src to the end of dst.
 *      It will append at most dstsize - strlen(dst) - 1 characters.
 *      It will then NUL-terminate, unless dstsize is 0 or the original
 *      dst string was longer than dstsize (in practice this should not
 *      happen as it means that either dstsize is incorrect or
 *      that dst is not a proper string).
 *  !!! If the src and dst strings overlap, the behavior is undefined.
 * @param dest : pointer to beginning  where src will be concatenated
 * @param src : pointer to string to be appended at the end of dest
 * @param destsize : maximum size of dest
 * @return pointer to dest
 */
size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	while (dlen < destsize && dest[dlen])
		dlen++;
	slen = 0;
	while (src[slen])
		slen++;
	if (destsize <= dlen)
		return (destsize + slen);
	i = 0;
	while (src[i] && (dlen + i) < (destsize - 1))
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
