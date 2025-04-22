/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:59:06 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:59:08 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - function locates the first occurrence of c (converted to a char)
 *      in the string pointed to by s.  The terminating null character is
 *      considered to be part of the string; therefore if c is ‘\0’,
 *      the function locates the terminating ‘\0’.
 * I only use pointer "p" to adhere to the declaration "const char *c"
 * @param s : pointer to string
 * @param c : character to be located whithing string
 * @return pointer to the located character,
 *       or NULL if the character does not appear in the string
 */
char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	cast_c;

	if (!s)
		return (NULL);
	p = (char *)s;
	cast_c = (char)c;
	while (*p)
	{
		if (*p == cast_c)
			return (p);
		p++;
	}
	if (*p == cast_c)
		return (p);
	return (NULL);
}
