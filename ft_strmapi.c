/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:01:06 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 21:01:08 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Applies the function f to each character of the string s,
 *          passing its index as the first argument and the character
 *          itself as the second. A new string is created (using malloc(3))
 *	    to store the results from the successive applications of f.
 * @param s: The string to iterate over.
 * @param f: The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 *         Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*f_s;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	f_s = (char *)malloc(len + 1);
	if (!f_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		f_s[i] = f(i, s[i]);
		i++;
	}
	f_s[i] = '\0';
	return (f_s);
}
