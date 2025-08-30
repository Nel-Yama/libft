/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:58:19 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:58:22 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Outputs the character ’c’ to the specified file descriptor.
 * @param c: The character to output.
 * @param fd: The file descriptor on which to write.
 * @return None
 */
int	ft_putchar_fd(int c, int fd)
{
	int				ret;
	unsigned char	uc;

	uc = (unsigned char)c;
	ret = write(fd, &uc, 1);
	return (ret);
}
