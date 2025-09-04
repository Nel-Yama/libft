/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:04:09 by nel-yama          #+#    #+#             */
/*   Updated: 2025/08/31 16:59:05 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_separators(t_split *split, int *i)
{
	while (split->s[*i] && is_char_in_str(split->sep, split->s[*i]))
		(*i)++;
}

void	skip_quoted(t_split *split, int *i)
{
	char	quote;

	quote = split->s[*i];
	(*i)++;
	while (split->s[*i] && (split->s[*i] != quote
			|| ft_is_escaped(split->s, *i)))
		(*i)++;
	if (split->s[*i] == quote)
		(*i)++;
}

void	skip_unquoted(t_split *split, int *i)
{
	while ((split->s[*i] && !is_char_in_str(split->sep, split->s[*i]))
		&& (!ft_isquote(split->s[*i]) || ft_is_escaped(split->s, *i)))
		(*i)++;
}

void	count_substrings(t_split *split)
{
	int	i;

	i = 0;
	split->str_list_cnt = 0;
	while (split->s[i])
	{
		skip_separators(split, &i);
		if (!split->s[i])
			break ;
		while (split->s[i] && !is_char_in_str(split->sep, split->s[i]))
		{
			if ((split->s[i] == '"' || split->s[i] == '\'')
				&& !ft_is_escaped(split->s, i))
				skip_quoted(split, &i);
			else
				skip_unquoted(split, &i);
		}
		split->str_list_cnt++;
	}
}
