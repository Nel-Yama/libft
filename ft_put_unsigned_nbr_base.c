/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:46:11 by nel-yama          #+#    #+#             */
/*   Updated: 2025/05/11 18:46:11 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief : validates the base string to ensure
 *	    it’s suitable for number conversion. 
 * @param base : pointer to the first element of the base.
 * @return : 1 if base is valid, 0 otherwise.
 * Potential improvement : 
 *   1- Handle non-ASCII characters.
 *   2- Checking for non-printable characters
 *      (e.g., control characters) in the base.
 */
static int	check_valid_base(const char *base)
{
	size_t	len_base;

	if (!base)
		return (0);
	len_base = ft_strlen(base);
	if (len_base <= 1)
		return (0);
	if (ft_strchr(base, '+') || ft_strchr(base, '-'))
		return (0);
	if (!ft_is_str_unique(base))
		return (0);
	if (ft_str_has_whitespace(base))
		return (0);
	return (1);
}

/**
 * @brief : recursively writes an unsigned number in
 8           the given base to the specified file descriptor.
 * @param nbr : the number to write on file descriptor fd.
 * @param base : pointer to the base string.
 * @param fd   : the file descriptor where to write the result.
 * !!!! point of attention : 
 * No error handling for write: If write fails (e.g., fd is invalid),
 * ...  the function doesn’t handle it.
 * Assumption of valid base: The function assumes base is valid
 * ... (checked by check_valid_base) and that ft_strlen(base) is non-zero.
 */
static void	ft_write_unsignednbr_base(long long nbr, const char *base,
			int *counter, int fd)
{
	int			c;
	long long	len_base;

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
int	ft_put_unsigned_nbr_base(unsigned int nbr, const char *base, int fd)
{
	unsigned int	n;
	int				counter;

	if (!check_valid_base(base))
		return (-1);
	n = (unsigned int)nbr;
	counter = 0;
	ft_write_unsignednbr_base(n, base, &counter, fd);
	return (counter);
}
