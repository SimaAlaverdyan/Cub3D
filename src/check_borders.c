/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:30:02 by zhatsago          #+#    #+#             */
/*   Updated: 2022/08/27 21:07:47 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void check_rows()
{
    int i;
    size_t j;
    
    i = 1;
    while (i < t_map.rows - 1 )
	{
        j = 1;
        if (t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i]) - 1] == '0' && 
            t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i]) - 2] != '1')
            ft_exit("Error: open border!4");
        if (t_map.tmp_map[i][0] == '0')
            ft_exit("Error: open border!3");
		while (j < ft_strlen(t_map.tmp_map[i]) - 2)
	    {
            if (t_map.tmp_map[i][j] == ' ')
            {
                if (t_map.tmp_map[i][j + 1] == '0' || t_map.tmp_map[i][j - 1] == '0')
                    ft_exit("Error: open border!1");           
                if (t_map.tmp_map[i - 1][j] == '0' || t_map.tmp_map[i + 1][j] == '0')
                    ft_exit("Error: open border!6");           
            }     
            if ((t_map.tmp_map[0][j] == '0' || t_map.tmp_map[t_map.rows - 1][j] == '0'))
                printf("%d", t_map.rows); //not working properly
                // ft_exit("Error: open border!2");
            j++;
		}
		i++;
    }
}