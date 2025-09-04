/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart_helper_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:01:44 by nel-yama          #+#    #+#             */
/*   Updated: 2025/08/31 18:00:37 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allocate_sub_str(t_split *split, int k, int i, int j)
{
	int	quote;

	quote = 0;
	j = i;
	while (split->s[i] && !is_char_in_str(split->sep, split->s[i]))
	{
		if (ft_isquote(split->s[i]) && !ft_is_escaped(split->s, i))
			skip_quoted(split, &i);
		else
			skip_unquoted(split, &i);
	}
	quote = ft_strcount_char(split->s + j, i - j, '\'');
	quote += ft_strcount_char(split->s + j, i - j, '\"');
	split->str_list[k] = (char *)malloc(i - j + 1 - quote);
	if (!split->str_list[k])
	{
		free_split(split->str_list);
		split->str_list = NULL;
	}
}

static void	copy_sub_str(t_split *split, int k, int *i, int j)
{
	int	end;

	end = *i;
	while (split->s[*i] && !is_char_in_str(split->sep, split->s[*i]))
	{
		j = *i;
		if (ft_isquote(split->s[*i]) && !ft_is_escaped(split->s, *i))
		{
			skip_quoted(split, i);
			j++;
			if (!split->s[*i] && *i > 0 && !ft_isquote(split->s[*i - 1]))
				j--;
			ft_strlcpy(split->str_list[k] + j - end - 1, split->s + j, *i - j);
			end += 2;
		}
		else
		{
			skip_unquoted(split, i);
			ft_strlcpy(split->str_list[k] + j - end, split->s + j, *i - j + 1);
		}
	}
}

void	create_sub_str(t_split *split, int *i, int k)
{
	int	j;

	skip_separators(split, i);
	if (!split->s[*i])
		return ;
	j = *i;
	allocate_sub_str(split, k, *i, j);
	copy_sub_str(split, k, i, j);
}
