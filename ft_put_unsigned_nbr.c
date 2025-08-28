/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:21:16 by nel-yama          #+#    #+#             */
/*   Updated: 2025/05/06 10:21:16 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - Outputs the integer ’n’ to the specified file descriptor.
 * @param n: The integer to output.
 * @param fd: The file descriptor on which to write.
 * @return None.
 */
static void	ft_put_ulnbr(long long int n, int *counter, int fd)
{
	int	c;

	if (n >= 10)
		ft_put_ulnbr(n / 10, counter, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	(*counter)++;
}

int	ft_put_unsigned_nbr(unsigned int n, int fd)
{
	unsigned int	ln;
	int				counter;

	counter = 0;
	ln = (unsigned int)n;
	ft_put_ulnbr(ln, &counter, fd);
	return (counter);
}
