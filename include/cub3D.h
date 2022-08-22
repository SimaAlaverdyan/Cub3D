/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:19 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/22 21:35:06 by zhatsago         ###   ########.fr       */
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
void		get_rows_cols(int fd);
void		allocate_matrix(int rows, int cols);
void		create_matrix(int fd, int cols);
void		parsing(int fd);
int			ft_isspace(char *str);
int			check_map_name(char *string, char *ext);
int			check_ext(char *path, char *ext);
int			check_colors(void);
void		create_initial_matrix( int rows, int cols, int matrix[rows][cols]);
void 		chack_init_matrix();

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
	char		**matrix;
	int			rows;
	int			cols;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
}				t_game;

#endif
