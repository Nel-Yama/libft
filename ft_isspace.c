/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:55:45 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/27 16:55:45 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief : check if a character is a whitespace character 
           (including space, tab, newline, etc.)
 * @param c : char to check if it's a space or not.
 * @return : 1 if c is a space char, 0 otherwise;
 * space chars in ascii are as follow : 
 * Space (' ', ASCII 32)
 * Tab ('\t', ASCII 9)
 * Line feed ('\n', ASCII 10)
 * Vertical tab ('\v', ASCII 11)
 * Form feed ('\f', ASCII 12)
 * Carriage return ('\r', ASCII 13)
 */
int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ((uc >= 9 && uc <= 13) || uc == 32)
		return (1);
	return (0);
}
