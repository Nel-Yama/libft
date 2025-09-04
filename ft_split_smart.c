/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:22:19 by nel-yama          #+#    #+#             */
/*   Updated: 2025/08/31 17:17:34 by nel-yama         ###   ########.fr       */
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
static void	split_edge_case(t_split *split)
{
	if (!split->s[0])
	{
		split->str_list = (char **)malloc(sizeof(char *));
		if (!split->str_list)
			return ;
		split->str_list[0] = NULL;
		return ;
	}
	if (!split->sep[0])
	{
		split->str_list = (char **)malloc(2 * sizeof(char *));
		if (!split->str_list)
			return ;
		split->str_list[0] = ft_strdup(split->s);
		if (!split->str_list[0])
		{
			free(split->str_list);
			split->str_list = NULL;
			return ;
		}
		split->str_list[1] = NULL;
		return ;
	}
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
static char	**str_split(t_split *split)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < split->str_list_cnt)
	{
		create_sub_str(split, &i, k);
		if (!split->str_list)
			break ;
		k++;
	}
	return (split->str_list);
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
static char	**str_list_alloc(t_split *split)
{
	count_substrings(split);
	split->str_list = (char **)malloc(((split->str_list_cnt) + 1)
			* sizeof(char *));
	if (!split->str_list)
		return (NULL);
	split->str_list[split->str_list_cnt] = NULL;
	if (!str_split(split))
		return (NULL);
	return (split->str_list);
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
char	**ft_split_smart(char *s, char *sep)
{
	t_split	split;

	if (!s || !sep)
		return (NULL);
	split.s = s;
	split.sep = sep;
	if (!split.s[0] || !split.sep[0])
	{
		split_edge_case(&split);
		return (split.str_list);
	}
	split.trimmed_s = ft_strtrim(split.s, split.sep);
	if (!split.trimmed_s)
		return (NULL);
	str_list_alloc(&split);
	free(split.trimmed_s);
	return (split.str_list);
}
/**
#include <stdio.h>
#include "libft.h"

int main(void)
{
	//char *test_str = "hello 'this is'abc'quoted' simple";
	char *test_str = "hello'this is'abc'quoted'simple";
	//char *test_str = "hello 'world test' \"this \\\"is\\\" a test\" simple";
//    0: [hello],
//    1: [world test],
//    2: [this \"is\" a test],
//    3: [simple]

	char *sep = " ";  // space as separator
	printf("|%s|\n", test_str);
	char **result = ft_split_smart(test_str, sep);

	if (!result)
	{
		printf("Split failed\n");
		return 1;
	}
	for (int i = 0; result[i] != NULL; i++)
	printf("Token %d: [%s]\n", i, result[i]);

	// Free memory
	for (int i = 0; result[i] != NULL; i++)
		free(result[i]);
	free(result);
	return 0;
}
**/
