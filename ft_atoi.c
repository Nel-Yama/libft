/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:53:47 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:53:59 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks if the string has more than 19 digit in which case it will
 *     overflow "long long int" so we know to immediatle return without
 *     calculating the number and we return the same value the std does.
 * @param str : string of which initial part will be converted to int.
 * @return  -1 if positif overflow is detected.
 *           0  if negatif overflow is detected.
 *           1  if str can be stored in "unsigned long long int".
 */
static int	str_overflows(const char *str, int s)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (s == 1 && i > 19)
		return (-1);
	else if (s == -1 && i > 19)
		return (0);
	else
		return (1);
}

/**
 * @brief -  this function will only run if str can be stored in
 *            "unsigned long long int". 
 *        it covers the rest where n is calculted but can overflow when 
 *        casted to int type.
 * @param n : which is the resulting number of the input string.
 * @param s : the signe of the resulting calculated number.
 * @return  -1 if positif overflow is detected.
 *           0  if negatif overflow is detected.
 *           (int)(s*n)  if str can be stored in "long long int".
 */
static int	check_overflows(unsigned long long int n, int s)
{
	unsigned long long	max;
	unsigned long long	min;

	max = 9223372036854775807;
	min = (unsigned long long)9223372036854775807 + 1;
	if (s == 1 && n > max)
		return (-1);
	else if (s == -1 && n > min)
		return (0);
	else
		return ((int)(s * n));
}

/**
 * @brief converts the initial portion of the string
 *      pointed to by str to int representation.
 * @param str : string of which initial part will be converted to int.
 * @return  the corresponding int of the initial part of str.
 * !!! the std function atoi crash if a null pointer is passed as argument
 *     so does my implementation to keep exactly the same behavior.
 * Overflow examples : 9223372036854700075800709645678600000000
 *                    -92233720368547000758000709645678600000000
 */
int	ft_atoi(const char *str)
{
	long long int	n;
	long long int	s;
	size_t			i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (str_overflows(str + i, (int)s) <= 0)
		return (str_overflows(str + i, (int)s));
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n = check_overflows(n, (int)s);
	return (n);
}
/*
#include <stdio.h>

int main(void)
{
    char    s[] = "-92233720368547000758000709645678600000000";
    int     i1 = ft_atoi(s);
    int     i2 = atoi(s);
    
    printf("my : |%d|\n", i1);
    printf("std: |%d|\n", i2);
    return (0);
}
*/
