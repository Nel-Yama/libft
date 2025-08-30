/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:58:50 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:58:52 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Outputs the string ’s’ to the specified file descriptor.
 * @param s: The string to output.
 * @param fd: The file descriptor on which to write.
 * @return number of printed characters.
 */
int	ft_putstr_fd(char *s, int fd)
{
	char	*counter;

	counter = s;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	return (s - counter);
}
