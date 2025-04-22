/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:54:11 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:54:13 by nel-yama         ###   ########.fr       */
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
