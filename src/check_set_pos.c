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

void    set_player_pos(int x, int y)
{
    game.player_view = t_map.matrix[y][x];
    game.posY = (double)x + 0.5;
    game.posX = (double)y + 0.5;
}

void    set_player_dir_plane2(char **map)
{
	if (map[(int)(game.posX - 0.5)][(int)(game.posY - 0.5)] == 'E')
    {
        game.dirX = 0.0;
        game.dirY = 1.0;
        game.planeX = 0.66;
        game.planeY = 0.0;
    }
    else if (map[(int)(game.posX - 0.5)][(int)(game.posY - 0.5)] == 'W')
    {
        game.dirX = 0.0;
        game.dirY = -1.0;
        game.planeX = -0.66;
        game.planeY = 0.0;
    }
}

void    set_player_dir_plane(char **map)
{
    if (map[(int)(game.posX - 0.5)][(int)(game.posY - 0.5)] == 'N')
    {
        game.dirX = -1.0;
        game.dirY = 0.0;
        game.planeX = 0.0;
        game.planeY = 0.66;
    }
    else if (map[(int)(game.posX - 0.5)][(int)(game.posY - 0.5)] == 'S')
    {
        game.dirX = 1.0;
        game.dirY = 0.0;
        game.planeX = 0.0;
        game.planeY = -0.66;
    }
    set_player_dir_plane2(map);
    map[(int)(game.posX - 0.5)][(int)(game.posY - 0.5)] = '0';
}

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
		while (j < ft_strlen(t_map.matrix[i]))
		{
			if (t_map.matrix[i][j] != 'N' && t_map.matrix[i][j] != 'S' &&
			t_map.matrix[i][j] != 'W' && t_map.matrix[i][j] != 'E' &&
			t_map.matrix[i][j] != '0' && t_map.matrix[i][j] != '1' &&
			t_map.matrix[i][j] != '-')
				ft_exit("Error: Invalid symbol in map!");
			check_on_one_start_position(t_map.matrix[i][j], &is_there);
			if (t_map.matrix[i][j] == 'N' || t_map.matrix[i][j] == 'S' ||
			t_map.matrix[i][j] == 'W' || t_map.matrix[i][j] == 'E')
			{
				set_player_pos(j, i);
				set_player_dir_plane(t_map.matrix);
			}
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
