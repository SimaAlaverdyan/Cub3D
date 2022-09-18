/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:19 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/04 18:59:58 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <math.h>
# include "mlx.h" 
# include "../libft/libft.h"
# include <stdbool.h>

int			ft_check_extension(char *path, char *ext);
int			get_next_line(int fd, char **line);
int			ft_exit(char *str);
int			ft_mlx_pressed(int keycode);
int			ft_mlx_released(int keycode);
void		get_cols(int fd);
void    	init(int fd);
void		allocate_matrix(int rows, int cols);
void    	create_matrix(int r, int c);
void		parsing(int fd);
void		parsing_map(int fd);
int			ft_isspace(char *str);
int			check_map_name(char *string, char *ext);
int			check_ext(char *path, char *ext);
int			check_colors(void);
int			ft_isspace(char *str);
void		create_initial_matrix(int rows, int cols, char matrix[rows][cols]);
void		r_and_c();
char		**free_matrix(char **map);
int 		check_map();
int			check_rows(void);
int			check_first_last_col(void);
int			check_first_row(void);
int			check_invalid_characters(void);
// int			check_dublicate_characters(void);
int			check_on_one_start_position(char symbol, int *is_there);
int			check_rows2(void);
void		set_mlx_images();
void		set_mlx_addresses();
void		matrix();
void	first_and_last_row(char *s);
void	col_border(char *s);
void    check_borders(void);
void    minus_check(int i, int j);

typedef struct s_img
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_keys
{
	int		w;
	int		s;
	int		d;
	int		a;
	// int		left;
	// int		right;
}				t_keys;

struct s_map
{
	t_img		data;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_keys		key;
	int			f_color[3];
	int			c_color[3];
	int			rows_tmp;
	int			rows;
	int			cols;
	char		**tmp_map;
	char		**matrix;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
    double      cameraX;
    double      rayDirX;
    double      rayDirY;
    int         mapX;
    int         mapY;
    double      sideDistX;
    double      sideDistY;
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;
    double      moveSpeed;
    double      rotSpeed;
    int         stepX;
    int         stepY;
    int         s_count;
}				t_game;

t_game	game;
t_keys	keys;

#endif
