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

void	skip_word(t_split *split, int *i, int *j, int *end)
{
	if (ft_isquote(split->s[*i]) && !ft_is_escaped(split->s, *i))
	{
		(*j)++;
		skip_quoted(split, i);
		*end = *i - 1;
	}
	else
	{
		skip_unquoted(split, i);
		*end = *i;
	}
}

void	allocate_sub_str(t_split *split, int *i, int k)
{
	int	j;
	int	end;

	skip_separators(split, i);
	if (!split->s[*i])
		return ;
	j = *i;
	skip_word(split, i, &j, &end);
	if (end - j > 0)
		split->str_list[k] = (char *)malloc((end - j + 1) * sizeof(char));
	if (!split->str_list[k])
	{
		free_split(split->str_list);
		split->str_list = NULL;
		return ;
	}
	if (end - j > 0)
		ft_strlcpy(split->str_list[k], split->s + j, end - j + 1);
}
