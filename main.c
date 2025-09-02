/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 08:46:57 by nel-yama          #+#    #+#             */
/*   Updated: 2025/09/02 08:46:57 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_split(char **split)
{
	int	i;

	if (!split)
	{
		printf("Split failed\n");
		return ;
	}
	i = 0;
	while (split[i])
	{
		printf("Token %d: [%s]\n", i, result[i]);
		i++;
	}
}
/**
int	main(void)
{
	char	*str;
	char	*sep;
	char	**split;

	str = "hello 'this is'abc'quoted' simple";
	printf("|%s|\n", str);
	split = ft_split_smart(str, sep);
	print_split(split);
	free_split(split);

	str = "hello 'this is'abc'quoted' simple";
	printf("|%s|\n", str);
	split = ft_split_smart(str, sep);
	print_split(split);
	free_split(split);

	str = "hello 'this is'abc'quoted' simple";
	printf("|%s|\n", str);
	split = ft_split_smart(str, sep);
	print_split(split);
	free_split(split);

	str = "hello 'this is'abc'quoted' simple";
	printf("|%s|\n", str);
	split = ft_split_smart(str, sep);
	print_split(split);
	free_split(split);	

	return (0);
}**/
