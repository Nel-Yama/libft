/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:58:43 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:58:44 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Outputs the integer ’n’ to the specified file descriptor.
 * @param n: The integer to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
 */
static void	ft_put_ulnbr(long long int n, int fd)
{
	int	c;

	if (n >= 10)
		ft_put_ulnbr(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	ln;

	ln = (long long int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	ft_put_ulnbr(ln, fd);
}
