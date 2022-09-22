/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:30:02 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/19 16:07:46 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	first_and_last_row(char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != '-')
			ft_exit("Error: Open border");
		str++;
	}
}

void	col_border(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = t_map.cols - 1;
	while (s[i] == '-' && s[i] != '\0')
		i++;
	while (s[j] == '-' && j >= 0)
		j--;
	if (s[i] != '1' || s[j] != '1')
	{
		printf("%d %d\n", i, j);
		ft_exit("Error: Open border");
	}
}
