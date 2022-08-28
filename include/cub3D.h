/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:19 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/28 16:22:34 by zhatsago         ###   ########.fr       */
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

int			ft_check_extension(char *path, char *ext);
int			get_next_line(int fd, char **line);
void		ft_exit(char *str);
void		get_cols(int fd);
void    	init(int fd, char **argv);
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
int			check_first_col(void);
int			check_last_row(void);
int			check_invalid_characters(void);

typedef struct s_texture
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_texture;

struct s_map
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
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
	void	*mlx;
	void	*mlx_win;
}				t_game;

#endif
