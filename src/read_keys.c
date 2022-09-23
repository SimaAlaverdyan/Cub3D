/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:32:57 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:36:14 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	read_arrow_keys(void)
{
	double oldDirX;
	double oldPlaneX;

	oldPlaneX = game.planeX;
	oldDirX = game.dirX;
	if (t_map.keys.right)
	{
		game.dirX = game.dirX * cos(-game.rotSpeed) - game.dirY * sin(-game.rotSpeed);
		game.dirY = oldDirX * sin(-game.rotSpeed) + game.dirY * cos(-game.rotSpeed);
		game.planeX = game.planeX * cos(-game.rotSpeed) - game.planeY * sin(-game.rotSpeed);
		game.planeY = oldPlaneX * sin(-game.rotSpeed) + game.planeY * cos(-game.rotSpeed);
	}
	else if (t_map.keys.left)
	{
		game.dirX = game.dirX * cos(game.rotSpeed) - game.dirY * sin(game.rotSpeed);
		game.dirY = oldDirX * sin(game.rotSpeed) + game.dirY * cos(game.rotSpeed);
		game.planeX = game.planeX * cos(game.rotSpeed) - game.planeY * sin(game.rotSpeed);
		game.planeY = oldPlaneX * sin(game.rotSpeed) + game.planeY * cos(game.rotSpeed);
	}
}

void	read_keys(void)
{
	if (t_map.keys.w)
	{
		if (t_map.matrix[(int)((game.posX) + game.dirX * game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX += game.dirX * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)((game.posY) + game.dirY * game.moveSpeed)] == '0')
			(game.posY) += game.dirY * game.moveSpeed;
	}
	else if (t_map.keys.s)
	{
		if (t_map.matrix[(int)(game.posX - game.dirX * game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX -= game.dirX * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)(game.posY - game.dirY * game.moveSpeed)] == '0')
			game.posY -= game.dirY * game.moveSpeed;
	}
	else if (t_map.keys.d)
	{
		if (t_map.matrix[(int)(game.posX + game.dirY * game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX += game.dirY * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)(game.posY - game.dirX * game.moveSpeed)] == '0')
			game.posY -= game.dirX * game.moveSpeed;
	}
	else if (t_map.keys.a)
	{
		if (t_map.matrix[(int)(game.posX - game.dirY * game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX -= game.dirY * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)(game.posY + game.dirX * game.moveSpeed)] == '0')
			game.posY += game.dirX * game.moveSpeed;
	}
	read_arrow_keys();
}
