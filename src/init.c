/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:51:24 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/04 19:51:28 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    init(int fd)
{
    t_map.key.w = 0;
    t_map.key.s = 0;
    t_map.key.d = 0;
    t_map.key.a = 0;
    game.dirX = 0;
    game.dirY = 0;
    game.moveSpeed = 0.08;
    game.planeX = 0;
    game.planeY = 0;
    game.rotSpeed = 0.04;
    game.posX = 0;
    game.posY = 0;
    get_cols(fd);
    // create_matrix(t_map.rows, t_map.cols);
    // create_initial_matrix(t_map.rows, t_map.cols, t_map.matrix);
    // allocate_matrix(t_map.rows, t_map.cols);
    // close(fd);
    // fd = open(argv[1], O_RDONLY);
    // create_matrix(fd, t_map.cols);
}
