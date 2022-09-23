/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:27:10 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:27:54 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	raycasting_vars(int x)
{
	vars.hit = 0;
	game.cameraX = 2 * x / (double)WIN_WIDTH - 1;
	game.rayDirX = game.dirX + game.planeX * game.cameraX;
	game.rayDirY = game.dirY + game.planeY * game.cameraX;
	game.mapX = (int)game.posX;
	game.mapY = (int)game.posY;
	game.deltaDistX = fabs(1 / game.rayDirX);
	game.deltaDistY = fabs(1 / game.rayDirY);
}
