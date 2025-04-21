/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nassr.elyamani@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:47:18 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/06 23:47:18 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief converts the initial portion of the string
 *      pointed to by str to int representation.
 * @param str : string of which initial part will be converted to int.
 * @return  the corresponding int of the initial part of str.
 */
int	ft_atoi(const char *str)
{
	long long int	n;
	long long int	s;
	size_t			i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(s * n));
}
