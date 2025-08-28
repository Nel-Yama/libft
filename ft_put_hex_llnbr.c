/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_llnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:26:33 by nel-yama          #+#    #+#             */
/*   Updated: 2025/05/08 07:26:33 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief : recursively writes an unsigned number in
 *           the given base to the specified file descriptor.
 * @param nbr : the number to write on file descriptor fd.
 * @param base : pointer to the base string.
 * @param fd   : the file descriptor where to write the result.
 * !!!! point of attention : 
 * No error handling for write: If write fails (e.g., fd is invalid),
 * ...  the function doesn’t handle it.
 * Assumption of valid base: The function assumes base is valid
 * ... (checked by check_valid_base) and that ft_strlen(base) is non-zero.
 */
static void	ft_write_unsignednbr_base(unsigned long long nbr,
			const char *base, int *counter, int fd)
{
	int					c;
	unsigned long long	len_base;

	len_base = ft_strlen(base);
	if (nbr >= len_base)
		ft_write_unsignednbr_base(nbr / len_base, base, counter, fd);
	c = base[nbr % len_base];
	write(fd, &c, 1);
	(*counter)++;
}

/**
 * @brief : main function that handles printing
 * ...      a signed integer in the specified base.
 * @param nbr : number to print.
 * @param base : base in where the number should be printed.
 * @param fd  : the file descriptor where the printing should be.
 * !!! Point of attention : 
 * Invalid fd values could cause write to fail,
 */
int	ft_put_hex_llnbr(unsigned long long nbr, int fd)
{
	int			counter;

	counter = 0;
	write(fd, "0x", 2);
	counter += 2;
	ft_write_unsignednbr_base(nbr, "0123456789abcdef", &counter, fd);
	return (counter);
}

int	ft_put_ptr(void *p, int fd)
{
	int					counter;
	unsigned long long	n;

	if (!p)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	n = (unsigned long long)p;
	counter = ft_put_hex_llnbr(n, fd);
	return (counter);
}
