/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:19:59 by nel-yama          #+#    #+#             */
/*   Updated: 2025/08/31 17:30:01 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

typedef struct s_split
{
	char	*s;
	char	*sep;
	char	*trimmed_s;
	char	**str_list;
	int		str_list_cnt;
}			t_split;

void	free_split(char **split);
void	skip_separators(t_split *split, int *i);
void	skip_quoted(t_split *split, int *i);
void	skip_unquoted(t_split *split, int *i);
void	count_substrings(t_split *split);
void	allocate_sub_str(t_split *split, int *i, int k);
char	**ft_split_str(char *s, char *c);
char	**ft_split_smart(char *s, char *sep);

#endif
