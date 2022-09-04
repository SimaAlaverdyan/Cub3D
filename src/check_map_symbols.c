/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:02:16 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/04 20:02:21 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_invalid_characters(void)
{
	int			i;
	size_t		j;
	int			is_there;

	is_there = 0;
	i = 1;
	while (i < t_map.rows)
	{
		j = 1;
		while (j < ft_strlen(t_map.tmp_map[i]))
		{
			if (t_map.tmp_map[i][j] != 'N' && t_map.tmp_map[i][j] != 'S' &&
			t_map.tmp_map[i][j] != 'W' && t_map.tmp_map[i][j] != 'E' &&
			t_map.tmp_map[i][j] != '0' && t_map.tmp_map[i][j] != '1' &&
			t_map.tmp_map[i][j] != ' ')
				ft_exit("Error: Invalid symbol in map!");
			check_on_one_start_position(t_map.tmp_map[i][j], &is_there);
			j++;
		}
		i++;
	}
	if (is_there == 0)
		ft_exit("Error: The start position is missing!");
	return (1);
}

int	check_on_one_start_position(char symbol, int *is_there)
{
	if (symbol == 'N' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'N' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	if (symbol == 'W' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'W' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	if (symbol == 'E' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'E' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	if (symbol == 'S' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'S' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	return (1);
}
