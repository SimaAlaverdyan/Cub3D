/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:32:57 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/24 20:24:01 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	right_key(double old_dirx, double old_planex)
{
	game.dirX = game.dirX * cos(-game.rotSpeed) - game.dirY
		* sin(-game.rotSpeed);
	game.dirY = old_dirx * sin(-game.rotSpeed) + game.dirY
		* cos(-game.rotSpeed);
	game.planeX = game.planeX * cos(-game.rotSpeed) - game.planeY
		* sin(-game.rotSpeed);
	game.planeY = old_planex * sin(-game.rotSpeed) + game.planeY
		* cos(-game.rotSpeed);
}

void	read_arrow_keys(void)
{
	double	old_dirx;
	double	old_planex;

	old_planex = game.planeX;
	old_dirx = game.dirX;
	if (t_map.keys.right)
		right_key(old_dirx, old_planex);
	else if (t_map.keys.left)
	{
		game.dirX = game.dirX * cos(game.rotSpeed) - game.dirY
			* sin(game.rotSpeed);
		game.dirY = old_dirx * sin(game.rotSpeed) + game.dirY
			* cos(game.rotSpeed);
		game.planeX = game.planeX * cos(game.rotSpeed) - game.planeY
			* sin(game.rotSpeed);
		game.planeY = old_planex * sin(game.rotSpeed) + game.planeY
			* cos(game.rotSpeed);
	}
}

void	a_d_keys(void)
{
	if (t_map.keys.d)
	{
		if (t_map.matrix[(int)(game.posX + game.dirY
				* game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX += game.dirY * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)(game.posY - game.dirX
				* game.moveSpeed)] == '0')
			game.posY -= game.dirX * game.moveSpeed;
	}
	else if (t_map.keys.a)
	{
		if (t_map.matrix[(int)(game.posX - game.dirY
				* game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX -= game.dirY * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)(game.posY + game.dirX
				* game.moveSpeed)] == '0')
			game.posY += game.dirX * game.moveSpeed;
	}
}

void	read_keys(void)
{
	if (t_map.keys.w)
	{
		if (t_map.matrix[(int)((game.posX) + game.dirX
				* game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX += game.dirX * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)((game.posY) + game.dirY
				* game.moveSpeed)] == '0')
			(game.posY) += game.dirY * game.moveSpeed;
	}
	else if (t_map.keys.s)
	{
		if (t_map.matrix[(int)(game.posX - game.dirX
				* game.moveSpeed)][(int)(game.posY)] == '0')
			game.posX -= game.dirX * game.moveSpeed;
		if (t_map.matrix[(int)(game.posX)][(int)(game.posY - game.dirY
				* game.moveSpeed)] == '0')
			game.posY -= game.dirY * game.moveSpeed;
	}
	a_d_keys();
	read_arrow_keys();
}
