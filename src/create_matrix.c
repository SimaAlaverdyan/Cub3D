/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:00:27 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/24 22:08:35 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_cols(int fd)
{
    char        *line;
    int         col;
    int         ret;
    int         max_col;

    max_col = 0;
    line = NULL;
    ret = 1;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        free(line);
        col = ft_strlen(line);
        if (col > max_col)
            max_col = col;
        if (!ret)
            break ;
    }
    t_map.cols = max_col + 2;
    close(fd);
}

void    r_and_c()
{
    int i;

    i = 0;
    while (t_map.tmp_map[i] != 0)
        i++;
    t_map.rows = i + 2;
}

void    allocate_matrix(int rows, int cols)
{
    int i;

    i = 0;
    t_map.matrix = (char **)malloc(sizeof(char *) * (rows));
    if (!t_map.matrix)
        ft_exit("Error: Malloc");
    while (i < rows)
        t_map.matrix[i++] = (char *)malloc(sizeof(char) * (cols));
}

void    create_matrix(int r, int c)
{
    int     i;
    size_t  j;

    allocate_matrix(r, c);    
    i = 0;
    j = 0;
    // while (i < r)
    // {
    //     j = 0;
    //     while (j < c)
    //     {
    //         t_map.matrix[i][j] = '-';
    //         j++;
    //     }
    //     i++;
    // }
    // char *sstr = NULL;
        
    while (i < t_map.rows-2)
	{
        j = 0;
		while (j < ft_strlen(t_map.tmp_map[i]))
	    {
            if (t_map.tmp_map[i][j] == 32)
                t_map.matrix[i][j] = 45;
            else
                t_map.matrix[i][j] = t_map.tmp_map[i][j];
            printf("%d", t_map.tmp_map[i][j]);
            j++;
		}
        printf("\n");
        // while ((int)j < t_map.cols)
        //     t_map.matrix[i][j] = '-';
        // t_map.matrix[i][j] = '\0';
		i++;
	}
    i = 0;
    while (i < t_map.rows - 2)
    {
        printf("%s\n", t_map.tmp_map[i]);
        i++;
    }
    free_matrix(t_map.tmp_map); 
    printf("%c", 45);
}
