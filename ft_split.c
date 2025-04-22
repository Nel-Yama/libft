/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:58:59 by nel-yama          #+#    #+#             */
/*   Updated: 2025/04/22 20:59:01 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	trimmedstr_len(char const *s, char c,
		size_t *start, size_t *end)
{
	if (!s || (ft_strlen(s) == 0))
		return ;
	*start = 0;
	while ((s[*start] == c) && s[*start])
		(*start)++;
	*end = ft_strlen(s) - 1;
	while ((*end > *start) && (s[*end] == c))
		(*end)--;
}

static char	**substr_list_alloc(char const *s, char c, int *nbr_substr)
{
	char	**substr_list;
	size_t	i;
	size_t	end;

	if (!s)
		return (NULL);
	trimmedstr_len(s, c, &i, &end);
	*nbr_substr = 0;
	if (*s == '\0' || end < i)
	{
		substr_list = (char **)malloc(sizeof(char *));
		return (substr_list);
	}
	while (i <= end)
	{
		if (s[i] != c)
		{
			(*nbr_substr)++;
			while ((i + 1 <= end) && s[i + 1] != c)
				i++;
		}
		i++;
	}
	substr_list = (char **)malloc((*nbr_substr + 1) * sizeof(char *));
	return (substr_list);
}

static char	*substr_alloc(char const *s, char c, int *i, int *sl)
{
	char	*substr;
	int		start;

	if (!s)
		return (NULL);
	*sl = 0;
	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
	{
		(*sl)++;
		(*i)++;
	}
	substr = NULL;
	if (*sl != 0)
	{
		substr = (char *)malloc(*sl + 1);
		if (substr)
			ft_strlcpy(substr, s + start, *sl + 1);
	}
	return (substr);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * @brief - Allocates memory (using malloc(3)) and returns an array of
 *          strings obtained by splitting ’s’ using the character ’c’
 *          as a delimiter. The array must end with a NULL pointer.
 * @param s: The string to be split.
 * @param c: The delimiter character.
 * @return The array of new strings resulting from the split.
 *         NULL if the allocation fails.
 * !!! function crash in case s is NULL pointer.
 */
char	**ft_split(char const *s, char c)
{
	char	**substr_list;
	int		nbr_substr;
	int		count;
	int		sl;
	int		i;

	substr_list = substr_list_alloc(s, c, &nbr_substr);
	if (!substr_list)
		return (NULL);
	i = 0;
	count = 0;
	while (count < nbr_substr)
	{
		substr_list[count] = substr_alloc(s, c, &i, &sl);
		if (!substr_list[count])
		{
			free_split(substr_list);
			return (NULL);
		}
		count++;
	}
	if (substr_list)
		substr_list[count] = (void *)0;
	return (substr_list);
}
/**
int main()
{
        char    s[] = "-----ad-----be-----cf----";
        char    c   = '-';
        int     n = 0;
        char **p;
        p = ft_split(s, c);
    while (p[n])
    {
        printf("|%s|\n", p[n]);
        n++;
    }
    if (!p[0])
    {
        printf("empty||\n");
        n++;
    }
	if (p)
	{
		printf("freeing the list pointer");
		free_split(p);
	}
    return 0;
}
 */
