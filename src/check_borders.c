/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:30:02 by zhatsago          #+#    #+#             */
/*   Updated: 2022/08/25 21:59:58 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void check_rows()
{
    int i;
    size_t j;
    
    i = 0;
    j = 1;
    
    while (i < t_map.rows)
	{
        j = 0;
		while (j < ft_strlen(t_map.tmp_map[i]) - 1)
	    {
            // if (t_map.tmp_map[i][ft_strlen(t_map.tmp_map[i])] == '0')
            // {
            //     printf("\nError: Open border! %d %zu" ,i, j);
            //     break;
            // }
                // ft_exit("Error: Open border! %d %zu", i, j);
            // printf("%d", t_map.tmp_map[i][j]);

            if (t_map.tmp_map[i][j] == 32)
            {
                 printf("[%d][%lu] %d\n", i, j+1, t_map.tmp_map[i][j+1]);
                 printf("[%d][%lu] %d\n",i, j+ 1, t_map.tmp_map[i][j-1]);
                
                
                // if (t_map.tmp_map[i][j + 1] == 48 || t_map.tmp_map[i][j - 1] == 48)
                // {
                //     printf(" prev %c\n", t_map.tmp_map[i][j - 1]);
                //     printf(" aft %c", t_map.tmp_map[i][j + 1]);
                //     printf("\nError: Open border! %d %zu" ,i, j);
                //     break;
                // }
            }
                    // ft_exit("Error: Open border!");
            j++;
		}
                printf("\n");
		i++;
	}
}