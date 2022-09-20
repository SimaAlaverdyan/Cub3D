#include "../include/cub3D.h"

void    raycasting_vars(int x)
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

