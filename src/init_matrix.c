/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:18:40 by zhatsago          #+#    #+#             */
/*   Updated: 2022/08/22 21:37:24 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void create_initial_matrix( int rows, int cols, int matrix[rows][cols])
{
    int i;
    int j;

    i = 0;
    
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            matrix[i][j] = '-';
            j++;
        }
        i++;
    }
    
    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            printf("%c", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void chack_init_matrix()
{
	int matrix[t_map.rows + 2][t_map.cols + 2];
	create_initial_matrix(t_map.rows + 2, t_map.cols + 2, matrix);
}