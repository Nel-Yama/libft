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

void	allocate_sub_str(t_split *split, int *i, int k)
{
	int	j;

	skip_separators(split, i);
	if (!split->s[*i])
		return ;
	j = *i;
	if ((split->s[*i] == '"' || split->s[*i] == '\'')
		&& !is_escaped(split->s, *i))
	{
		j++;
		skip_quoted(split, i);
		if (*i > j)
			(*i)--;
	}
	else
		skip_unquoted(split, i);
	if (*i - j + 1 > 0)
		split->str_list[k] = (char *)malloc((*i - j + 1) * sizeof(char));
	if (!split->str_list[k])
	{
		free_split(split->str_list);
		split->str_list = NULL;
		return ;
	}
	if (*i - j + 1 > 0)
		ft_strlcpy(split->str_list[k], split->s + j, *i - j + 1);
}
