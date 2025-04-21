/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nassr.elyamani@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:43:45 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/07 22:43:45 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief writes n zeroed bytes to the string s.
 *      If n is zero, bzero() does nothing.
 * @param s : pointer to string ofwhich n bytes will be overwritten by zeros.
 * @param n : number of bytes to overwrite with zeros.
 * @return None.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*us;

	us = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		us[i] = 0;
		i++;
	}
}
