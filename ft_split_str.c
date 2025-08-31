/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:22:19 by nel-yama          #+#    #+#             */
/*   Updated: 2025/08/28 21:22:19 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * split_edge_case:
 *   Handles edge cases for ft_split_str:
 *     - empty input string: returns array containing only NULL
 *     - empty delimiter string: returns array containing copy of s
 *
 * Parameters:
 *   s - the input string
 *   c - the delimiter string
 *
 * Returns:
 *   Dynamically allocated array of strings, or NULL on allocation failure
 */
static char	**split_edge_case(char *s, char *c)
{
	char	**split;

	if (!s[0])
	{
		split = (char **)malloc(sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	if (!c[0])
	{
		split = (char **)malloc(2 * sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = ft_strdup(s);
		if (!split[0])
		{
			free(split);
			return (NULL);
		}
		split[1] = NULL;
		return (split);
	}
	return (NULL);
}

/*
 * str_split:
 *   Fills the pre-allocated array `split` with substrings of `s`
 *   separated by delimiters `c`.
 *
 * Parameters:
 *   split - pre-allocated array of strings
 *   s - the trimmed input string
 *   c - the delimiter string
 *   sub_str_nbr - number of substrings to fill
 *
 * Returns:
 *   The same array `split` on success, or NULL if allocation fails
 *   (frees split on failure)
 */
static char	**str_split(char **split, char *s, char *c, int *sub_str_nbr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < *sub_str_nbr)
	{
		while (s[i] && is_char_in_str(c, s[i]))
			i++;
		if (s[i])
		{
			j = i;
			while (s[i] && !is_char_in_str(c, s[i]))
				i++;
		}
		split[k] = (char *)malloc((i - j) * sizeof(char));
		if (!split[k])
			return (free_split(split), NULL);
		ft_strlcpy(split[k], s + j, i - j);
		k++;
	}
	return (split);
}

/*
 * str_list_alloc:
 *   Counts the number of substrings in `s` separated by delimiters `c`,
 *   allocates an array of char* of appropriate size, and calls str_split
 *   to fill it.
 *
 * Parameters:
 *   s - the trimmed input string
 *   c - the delimiter string
 *   sub_str_nbr - pointer to an int
 *		where the number of substrings will be stored
 * Returns:
 *   Dynamically allocated array of strings, or NULL on allocation failure
 */
static char	**str_list_alloc(char *s, char *c, int *sub_str_nbr)
{
	char	**str_list;
	int		i;

	*sub_str_nbr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_char_in_str(c, s[i]))
			i++;
		if (s[i])
		{
			(*sub_str_nbr)++;
			while (s[i] && !is_char_in_str(c, s[i]))
				i++;
		}
	}
	str_list = (char **)malloc(((*sub_str_nbr) + 1) * sizeof(char *));
	if (!str_list)
		return (NULL);
	str_list[*sub_str_nbr] = NULL;
	if (!str_split(str_list, s, c, sub_str_nbr))
		return (NULL);
	return (str_list);
}

/*
 * ft_split_str:
 *   Splits a string `s` into an array of strings using the delimiters
 *   specified in `c`. Returns a NULL-terminated array of strings.
 *   Handles edge cases: empty string or empty delimiter.
 *
 * Parameters:
 *   s - the input string to split
 *   c - a string containing all delimiter characters
 *
 * Returns:
 *   A dynamically allocated array of strings (NULL-terminated),
 *   or NULL if allocation fails or input is NULL.
 */
char	**ft_split_str(char *s, char *c)
{
	char	*trimmed_s;
	char	**split;
	int		sub_str_nbr;

	if (!s || !c)
		return (NULL);
	if (!s[0] || !c[0])
	{
		split = split_edge_case(s, c);
		return (split);
	}
	trimmed_s = ft_strtrim(s, c);
	if (!trimmed_s)
		return (NULL);
	split = str_list_alloc(trimmed_s, c, &sub_str_nbr);
	free(trimmed_s);
	return (split);
}
