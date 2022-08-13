/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:19 by salaverd          #+#    #+#             */
/*   Updated: 2022/08/13 20:13:57 by zhatsago         ###   ########.fr       */
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

int     ft_check_extension(char *path, char *ext);
int				get_next_line(int fd, char **line);

typedef struct s_RowsCols
{
    int     rows;
    int     cols;
}           t_RowsCols;

#endif
