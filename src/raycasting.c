#include "../include/cub3D.h"

void ft_raycasting(void)
{
    int x = 0;
    double BUFFER[WIN_WIDTH];
    while (x < WIN_WIDTH)
    {
        game.cameraX = 2 * x / (double)WIN_WIDTH - 1;
        game.rayDirX = game.dirX + game.planeX * game.cameraX;
        game.rayDirY = game.dirY + game.planeY * game.cameraX;
        game.mapX = (int)game.posX;
        game.mapY = (int)game.posY;

        game.deltaDistX = fabs(1 / game.rayDirX);
        game.deltaDistY = fabs(1 / game.rayDirY);

        int hit = 0;
        int side;

        if (game.rayDirX < 0)
        {
            game.stepX = -1;
            game.sideDistX = (game.posX - game.mapX) * game.deltaDistX;
        }
        else
        {
            game.stepX = 1;
            game.sideDistX = (game.mapX - game.posX + 1.0) * game.deltaDistX;
        }
        if (game.rayDirY < 0)
        {
            game.stepY = -1;
            game.sideDistY = (game.posY - game.mapY) * game.deltaDistY;
        }
        else
        {
            game.stepY = 1;
            game.sideDistY = (game.mapY - game.posY + 1.0) * game.deltaDistY;
        }
        while (hit == 0)
        {
            if (game.sideDistX < game.sideDistY)
            {
                game.sideDistX += game.deltaDistX;
                game.mapX += game.stepX;
                side = 0;
            }
            else
            {
                game.sideDistY += game.deltaDistY;
                game.mapY += game.stepY;
                side = 1;
            }
            if (t_map.matrix[game.mapX][game.mapY] == '1')
                hit = 1;
        }
        if (side == 0)
            game.perpWallDist = (game.mapX - game.posX + (1 - game.stepX) / 2) / game.rayDirX;
        else
            game.perpWallDist = (game.mapY - game.posY + (1 - game.stepY) / 2) / game.rayDirY;

        int lineHeight = (int)(WIN_HEIGHT / game.perpWallDist);
        int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
        int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        if (drawEnd >= WIN_HEIGHT)
            drawEnd = WIN_HEIGHT - 1;
        double wallX;
        if (side == 0)
            wallX = game.posY + game.perpWallDist * game.rayDirY;
        else
            wallX = game.posX + game.perpWallDist * game.rayDirX;
        wallX -= floor((wallX));
        int texX = (int)(wallX * (double)(TEXTURE_SIZE));
        if (side == 0 && game.rayDirX > 0)
            texX = TEXTURE_SIZE - texX - 1;
        if (side == 1 && game.rayDirY < 0)
            texX = TEXTURE_SIZE - texX - 1;

        double step = 1.0 * TEXTURE_SIZE / lineHeight;
        int color = 0;
        double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;

        for (int y = 0; y < drawStart; y++)
            my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.c_color));
        for (int y = drawStart; y < drawEnd; y++)
        {
            int texY = (int)texPos & (TEXTURE_SIZE - 1);
            texPos += step;
            if (side == 0)
            {
                if (game.stepX > 0)
                    color = get_color(&t_map.so, texX, texY);
                else
                    color = get_color(&t_map.no, texX, texY);
            }
            else
            {
                if (game.stepY > 0)
                    color = get_color(&t_map.we, texX, texY);
                else
                    color = get_color(&t_map.ea, texX, texY);
            }
            my_mlx_pixel_put(&t_map.data, x, y, color);
        }
        for (int y = drawEnd; y < WIN_HEIGHT; y++)
            my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.f_color));
        BUFFER[x] = game.perpWallDist;
        x++;
    }
}