#include "../include/cub3D.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void ft_clear()
{
    int i = 0;
    int j;

    while (i < WIN_HEIGHT)
    {
        j = 0;
        while (j < WIN_WIDTH)
        {
            my_mlx_pixel_put(&t_map.data, j, i, 0x00000000);
            j++;
        }
        i++;
    }
}

int start()
{
    read_keys();
    ft_clear();
    ft_raycasting();
    mlx_put_image_to_window(game.mlx, game.mlx_win, t_map.data.img, 0, 0);
    mlx_do_sync(game.mlx);
    return (0);
}