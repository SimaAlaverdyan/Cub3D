/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:00:27 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/04 19:00:23 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int check_map(void)
{
 	check_rows();
    check_first_row();
	check_first_last_col();
	check_invalid_characters();
	check_rows2();

	// check_dublicate_characters();
	return (1);
}

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
    t_map.cols = max_col;
    close(fd);
}

void    r_and_c()
{
    int i;

    i = 0;
    while (t_map.tmp_map[i] != 0)
        i++;
    t_map.rows = i;
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

// void    create_matrix(int r, int c)
// {
//     int     i;
//     size_t  j;

//     allocate_matrix(r, c);    
//     i = 0;
//     j = 0;

//    check_map();
// }
