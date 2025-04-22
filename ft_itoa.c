/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:56:29 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:56:32 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief - helper function, count how many memory chars should be allocated.
 * @param n: The integer to process.
 * @return c: the number of char allocation needed (included the - signe).
 */
static int	int_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

/**
 * @brief - helper function to conver an unsigned int to char via recursion 
 * @param n: The integer to convert.
 * @param c: pointer to memory to write a single digit.
 *   The recursion here is a bit tricky because I don't want to reverse the
 *   resulting string at the end of the process.
 *   so I start from the rightmost index and fill in reverse, recursively. 
 */
static void	digi_to_char(char *c, unsigned int n)
{
	if (n >= 10)
		digi_to_char(c - 1, n / 10);
	*c = (n % 10) + '0';
}

/**
 * @brief - Allocates memory (using malloc(3)) and returns a string
 *        representing the integer received as an argument.
 *        Negative numbers must be handled.
 * @param n: The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 * bellow I mention the algo steps used (so I don't forget it in the future)
 * 1- Calculate length (including sign)
 * 2- Allocate memory -> exactly the required bytes (len + 1) bytes.
 * 3- Fill the string recursively from the end.
 * 4- Insert '-' manually if negative and.
 *  5- Null-terminate at the end
 */
char	*ft_itoa(int n)
{
	long long int	d;
	int				l;
	char			*c;

	l = int_len(n);
	c = (char *)malloc(l + 1);
	if (!c)
		return (NULL);
	c[l] = '\0';
	if (n < 0)
	{
		d = -((long long int)n);
		c[0] = '-';
	}
	else
		d = (long long int)n;
	digi_to_char(c + l - 1, d);
	return (c);
}
/**
 * Note : here I put in comment the iterative approach just for refrence
 * iterative approach is more efficient in term of stack memory usage
 * I did it via recursion just cuz I dont't relly get recursion that well.
char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		if (n < 0 && len == 0)
			str[0] = '-';
	}
	return (str);
}
 */
