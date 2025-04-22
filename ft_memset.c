/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:58:06 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:58:08 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief writes len bytes of value c (converted to an unsigned char)
 *      to the string b.
 * @param b : pointer to string to overwrite len bytes.
 * @param c : char that will be used to overwrite len bytes of b.
 * @param len : number of bytes to overwite.
 * @return function returns its first argument.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*ub;

	ub = (unsigned char *) b;
	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ub[i] = uc;
		i++;
	}
	return (b);
}
