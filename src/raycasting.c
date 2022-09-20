#include "../include/cub3D.h"

void    ft_ray_dirs(void)
{
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
}

void    ft_wall_hit()
{
    while (vars.hit == 0)
    {
        if (game.sideDistX < game.sideDistY)
        {
            game.sideDistX += game.deltaDistX;
            game.mapX += game.stepX;
            vars.side = 0;
        }
        else
        {
            game.sideDistY += game.deltaDistY;
            game.mapY += game.stepY;
            vars.side = 1;
        }
        if (t_map.matrix[game.mapX][game.mapY] == '1')
            vars.hit = 1;
    }
    if (vars.side == 0)
        game.perpWallDist = (game.mapX - game.posX + (1 - game.stepX) / 2) / game.rayDirX;
    else
        game.perpWallDist = (game.mapY - game.posY + (1 - game.stepY) / 2) / game.rayDirY;
}

void    ft_init_vars(void)
{
    vars.lineHeight = (int)(WIN_HEIGHT / game.perpWallDist);
    vars.drawStart = -vars.lineHeight / 2 + WIN_HEIGHT / 2;
    vars.drawEnd = vars.lineHeight / 2 + WIN_HEIGHT / 2;
    if (vars.drawStart < 0)
        vars.drawStart = 0;
    if (vars.drawEnd >= WIN_HEIGHT)
        vars.drawEnd = WIN_HEIGHT - 1;
    if (vars.side == 0)
        vars.wallX = game.posY + game.perpWallDist * game.rayDirY;
    else
        vars.wallX = game.posX + game.perpWallDist * game.rayDirX;
    vars.wallX -= floor((vars.wallX));
    vars.texX = (int)(vars.wallX * (double)(TEXTURE_SIZE));
    if (vars.side == 0 && game.rayDirX > 0)
        vars.texX = TEXTURE_SIZE - vars.texX - 1;
    if (vars.side == 1 && game.rayDirY < 0)
        vars.texX = TEXTURE_SIZE - vars.texX - 1;
    vars.step = 1.0 * TEXTURE_SIZE / vars.lineHeight;
    vars.texPos = (vars.drawStart - WIN_HEIGHT / 2 + vars.lineHeight / 2) * vars.step;
}

void    ft_draw(int *x)
{
    int     y;

    y = vars.drawStart;
    while (y < vars.drawEnd)
    {
        vars.texY = (int)vars.texPos & (TEXTURE_SIZE - 1);
        vars.texPos += vars.step;
        if (vars.side == 0)
        {
            if (game.stepX > 0)
                vars.color = get_color(&t_map.so, vars.texX, vars.texY);
            else
                vars.color = get_color(&t_map.no, vars.texX, vars.texY);
        }   
        else
        {
            if (game.stepY > 0)
                vars.color = get_color(&t_map.we, vars.texX, vars.texY);
            else
                vars.color = get_color(&t_map.ea, vars.texX, vars.texY);
        }
        my_mlx_pixel_put(&t_map.data, *x, y, vars.color);
        y++;
    }
}

void    ft_raycasting(void)
{
    int x;
    int y;

    x = 0;
    y = 0;
    vars.color = 0;
    while (x < WIN_WIDTH)
    {
        raycasting_vars(x);
        ft_ray_dirs();
        ft_wall_hit();
        ft_init_vars();
        y = 0;
        while (y++ < vars.drawStart)
            my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.c_color));
        ft_draw(&x);
        y = vars.drawEnd;
        while (y < WIN_HEIGHT)
        {
            my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.f_color));
            y++;
        }
        vars.BUFFER[x] = game.perpWallDist;
        x++;
    }
}
