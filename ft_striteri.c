/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:59:24 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:59:25 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Applies the function ’f’ to each character of the string passed
 *      as argument, passing its index as the first argument. Each character
 *      is passed by address to ’f’ so it can be modified if necessary.
 * @param s: The string to iterate over.
 * @param f: The function to apply to each character.
 * @return None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
