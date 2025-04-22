/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:54:22 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:54:23 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - function contiguously allocates enough space for count objects
 *        that are size bytes of memory each and returns a pointer to
 *        the allocated memory.  The allocated memory is filled with
 *        bytes of value zero.
 * @param count : number of object to reserve memory for.
 * @param size  : size of each object to reserve memory for.
 * @return - a pointer to allocated memory.  If there is an error,
 *         they return a NULL pointer and set errno to ENOMEM.
 * !!! -  In the first check we handle the case where calloc can be overflowwed
 *        which is a known trap of calloc, where it might reserve less memory
 *        than was required and then program will try to acees that memory that
 *        was not reserved.
 * max_size = (size_t)-1 ->
 * 	  to find out the maximum size of memory we cast -1 to size_t
 *        so that it will be rounded to the maximum value.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	max_size;

	max_size = (size_t)-1;
	if (size != 0 && count > max_size / size)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	if (count * size > 0)
		ft_bzero(p, count * size);
	return (p);
}
