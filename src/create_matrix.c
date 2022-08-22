/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:00:27 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/22 20:00:59 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_rows_cols(int fd)
{
    char        *line;
    int         row;
    int         col;
    int         ret;
    int         max_col;
    
    max_col = 0;
    line = NULL;
    row = 0;
    ret = 1;
    
    while (ret)
    {
        ret = get_next_line(fd, &line);
        row++;
        free(line);
        col = ft_gnl_strlen(line);
        
        if (col > max_col)
            max_col = col;
        
        if (!ret)
            break ;
    }
    t_map.rows = row;
    t_map.cols = max_col;
}

void    allocate_matrix(int rows, int cols)
{
    int i;

    i = 0;
    t_map.matrix = (char **)malloc(sizeof(char *) * (rows));
    while (i < rows)
        t_map.matrix[i++] = (char *)malloc(sizeof(char) * (cols));
}

void    create_matrix(int fd, int cols)
{
    int ret;
    int i;
    int j;
    char *line;

    i = 0;
    ret = 1;
    line = NULL;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        j = 0;
        while (j < cols)
        {
            t_map.matrix[i][j] = line[j];
            j++;
        }
        i++;
        free(line);
        if(!ret)
            break;
    }
}
