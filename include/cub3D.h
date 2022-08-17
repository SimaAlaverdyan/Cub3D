/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:19 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/17 19:34:37 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#define BUFFER_SIZE 1
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <math.h>
#include "mlx.h"
#include "../libft/libft.h"

int         ft_check_extension(char *path, char *ext);
int         get_next_line(int fd, char **line);
void    get_rows_cols(int fd);
void    allocate_matrix(int rows, int cols);
void    create_matrix(int fd, int cols);
void    init_map(int fd, char **argv);

struct s_map
{
    char *no;
    char *so;
    char *we;
    char *ea;
    int f_red;
    int f_green;
    int f_blue;
    int c_red;
    int c_green;
    int c_blue;
    char **matrix;
    int  rows;
    int  cols;
}           t_map;


typedef struct s_game
{
    void	*mlx;
	void	*mlx_win;
    struct s_map   map;
}               t_game;

#endif
