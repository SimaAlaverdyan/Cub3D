/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:30:02 by zhatsago          #+#    #+#             */
/*   Updated: 2022/08/28 16:00:22 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_rows(void)
{
	int			i;
	size_t		j;

	i = 1;
	while (i < t_map.rows - 1)
	{
		j = 1;
		while (j < ft_strlen(t_map.tmp_map[i]) - 1)
		{
			if (t_map.tmp_map[i][j] == ' ')
			{
				if (t_map.tmp_map[i][j + 1] == '0' || t_map.tmp_map[i][j - 1] == '0')
					ft_exit("Error: open border!1");
				if (t_map.tmp_map[i - 1][j] == '0' || t_map.tmp_map[i + 1][j] == '0')
					ft_exit("Error: open border!6");           
			}
			if (j > ft_strlen(t_map.tmp_map[i + 1]) - 1 && t_map.tmp_map[i][j] == '0')
				ft_exit("Error: open border!9");
			if (j > ft_strlen(t_map.tmp_map[i - 1]) - 1 && t_map.tmp_map[i][j] == '0')
				ft_exit("Error: open border!10");
			j++;
		}
		i++;
	}
	return (1);
}

int check_first_col(void)
{
    int i;
    
    i = 1;
    while (i < t_map.rows)
	{
		// if (t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i]) - 1] == '0' && 
		// 		t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i]) - 2] != '1')
		// 	ft_exit("Error: open border!4");
		if (t_map.tmp_map[i][0] == '0')
			ft_exit("Error: open border!3");
        i++;
    }
    return (1);
}

int	check_last_row(void)
{
	int i;
	size_t j;
    
	j = 0;
	i = t_map.rows - 1;
	while (j < ft_strlen(t_map.tmp_map[i]))
	{
		if (t_map.tmp_map[i][j] == '0')
			ft_exit("Error: open border!7");
        if (t_map.tmp_map[0][j] == '0')
			ft_exit("Error: open border!8");
		j++;
	}
	return (1);
}
