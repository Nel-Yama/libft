/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nassr.elyamani@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:12:57 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/17 19:12:57 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Outputs the character ’c’ to the specified file descriptor.
 * @param c: The character to output.
 * @param fd: The file descriptor on which to write.
 * @return None
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
