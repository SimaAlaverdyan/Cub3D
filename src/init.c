/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:51:24 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:19:03 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init(int fd)
{
	t_map.keys.w = 0;
	t_map.keys.s = 0;
	t_map.keys.d = 0;
	t_map.keys.a = 0;
	game.dirX = 0;
	game.dirY = 0;
	game.moveSpeed = 0.08;
	game.planeX = 0;
	game.planeY = 0;
	game.rotSpeed = 0.04;
	game.posX = 0;
	game.posY = 0;
	get_cols(fd);
}
